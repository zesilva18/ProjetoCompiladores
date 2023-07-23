/* Jose Silva */

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tree.h"


struct ast_tree *raiz;
struct ast_tree *aux;
struct ast_tree *temp;
int flag = 1;
int error = 0;
char *type;
int n_sons;
int yydebug = 1;
int flag_erro = 0;

extern int yylex();
extern int yyerror(char *s);
extern int yylineno;
extern int line;
extern int collum;

int flag_while = 0;

void mantertipo(ast_tree* no,char* type){
        ast_tree* auxiliar = NULL;
        for (ast_tree *atual = no; atual; atual = atual->brother){
            auxiliar=ast_node(type, "");
            auxiliar->brother=atual->son;
            atual->son=auxiliar;
        }
}

%}

%union{
char* string;
struct ast_tree* ast_tree;
}

//tokens

%token CLASS PUBLIC STATIC
%token STRING VOID INT DOUBLE BOOL
%token SEMICOLON COMMA LBRACE RBRACE LPAR RPAR LSQ RSQ ASSIGN
%token PLUS MINUS STAR DIV MOD
%token XOR OR AND EQ NE LE GE LT GT NOT
%token WHILE IF ELSE RETURN 
%token ARROW LSHIFT RSHIFT DOTLENGTH PRINT PARSEINT
%token RESERVED

%token <string> REALLIT STRLIT INTLIT ID BOOLLIT

%type <ast_tree> StatementAux Statement MethodDecl MethodBody Expr_aux HelpProgam HelpMethod Program Expr MethodInvocation Assignment ParseArgs  MethodInvocationaux  VarDecl Type VarDeclAux FieldDecl HelpField FormalParams FormalParamsAux MethodHeader MethodInvocationaux_new

/* Precedências */
%left COMMA
%right ASSIGN
%left OR
%left AND
%left XOR
%left LSHIFT RSHIFT
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR DIV MOD
%right NOT 
%left LPAR RPAR
%nonassoc ELSE



%%
// .
Program: CLASS ID LBRACE HelpProgam RBRACE                           {
                                                                raiz = ast_node("Program","");       
                                                                add_childs(raiz, ast_node("Id", $2));
                                                                add_childs(raiz,$4);
                                                                $$ = raiz;
                                                            }
        ;

HelpProgam:                                                  { $$ = NULL;}
          | FieldDecl HelpProgam                             {                                                           
                                                                $$ = $1;
                                                                
                                                                add_brother($$, $2);
                                                                
                                                            }
          | SEMICOLON HelpProgam                             {
                                                                $$ = $2;
                                                            }
          | MethodDecl HelpProgam                            {
                                                                $$ = $1;
                                                                add_brother($$, $2);
                                                            }

MethodDecl: PUBLIC STATIC MethodHeader MethodBody                                   {
                                                                                    $$ = ast_node("MethodDecl","");
                                                                                    add_childs($$,$3);
                                                                                    add_childs($$,$4);
                                                                                    }                                             
           ;


MethodHeader: Type ID LPAR FormalParams RPAR                   {
                                                                $$ = ast_node("MethodHeader","");
                                                                aux = ast_node("MethodParams","");
                                                                add_childs($$,$1); 
                                                                add_childs($$,ast_node("Id", $2));
                                                                add_childs($$, aux);
                                                                add_childs(aux,$4);
                                                               }


        | VOID ID LPAR FormalParams RPAR                       {
                                                                $$ = ast_node("MethodHeader","");
                                                                aux = ast_node("MethodParams","");
                                                                add_childs($$,ast_node("Void", "")); 
                                                                add_childs($$,ast_node("Id", $2));
                                                                add_childs($$, aux);
                                                                add_childs(aux,$4);
                                                               }

        ;

MethodBody: LBRACE HelpMethod RBRACE                                             {$$ = ast_node("MethodBody",""); 
                                                                                    add_childs($$,$2);
                                                                                    }
          ;


HelpMethod: Statement HelpMethod                                              {if($1 != NULL) {$$ = $1; add_brother($$, $2);} else{$$ = $2;}}
             | VarDecl HelpMethod                                                {$$ = $1; add_brother($$, $2);}
             |                                                                      {$$ = NULL;}
             ;

FieldDecl: PUBLIC STATIC Type ID HelpField SEMICOLON     {
                                                                $$ = ast_node("FieldDecl", "");
                                                                add_childs($$,$3);
                                                                add_childs($$, ast_node("Id", $4));
                                                                mantertipo($5, $3->type);
                                                                add_brother($$, $5);
                                                                
                                                            }
        | error SEMICOLON                                    {$$ = NULL;flag_erro = 1;}
        ;


HelpField: COMMA ID HelpField                         {
                                                                $$ = ast_node("FieldDecl","");                                                                
                                                                add_childs($$, ast_node("Id", $2));
                                                                
                                                                add_brother($$, $3);
                                                                
                                                            }

            |                                              {$$ = NULL;}                                                
            ;

Type: INT                                                   {$$ = ast_node("Int", "");}
    | DOUBLE                                                {$$ = ast_node("Double", "");}
    | BOOL                                                  {$$ = ast_node("Bool", "");}                
    ;

FormalParams: Type ID FormalParamsAux                                      {$$ = ast_node("ParamDecl","");
                                                                            add_childs($$,$1);
                                                                            add_childs($$,ast_node("Id", $2));
                                                                            add_brother($$,$3);}
                                                                            
            | STRING LSQ RSQ ID                                            {
                                                                           $$ = ast_node("ParamDecl","");
                                                                           add_childs($$,ast_node("StringArray",""));
                                                                           add_childs($$,ast_node("Id", $4));
                                                                           }
        
            |                                                {$$ = NULL;}                                  


FormalParamsAux: COMMA Type ID FormalParamsAux                            { $$ = ast_node("ParamDecl","");
                                                                            add_childs($$,$2);
                                                                            add_childs($$,ast_node("Id",$3));
                                                                            add_brother($$,$4);
                                                                            }
                                                                            
                |                                                         {$$ = NULL;}
                ;


VarDecl: Type ID VarDeclAux SEMICOLON                                   {
    
                                                                $$ = ast_node("VarDecl", "");
                                                                add_childs($$, $1);
                                                                add_childs($$, ast_node("Id", $2));
                                                                mantertipo($3, $1->type);
                                                                
                                                                add_brother($$, $3);
                                                                
                                                                }
        ;

VarDeclAux: COMMA ID VarDeclAux                            { 
                                                                $$ = ast_node("VarDecl","");
                                                                add_childs($$, ast_node("Id", $2));                                                              
                                                                add_brother($$, $3);
                                                                
                                                            }
        |                                                   {$$ = NULL;}
        ;

Statement:    LBRACE Statement StatementAux RBRACE                               {

                                                                                int count = 0;
                                                                                if($2 != NULL){
                                                                                    count ++;
                                                                                }

                                                                                temp = $3;

                                                                                while( temp != NULL){
                                                                                    if(temp->type != NULL && strcmp(temp->type, "Semicolon") != 0){
                                                                                        count ++;
                                                                                    }

                                                                                    temp = temp->brother;
                                                                                }

                                                                                if(count > 1){
                                                                                         $$ = ast_node("Block","");
                                                                                        add_childs($$,$2);
                                                                                        add_childs($$,$3);
                                                                                }else {
                                                                                    $$ = $2;
                                                                                }   

                                                                                }



            | IF LPAR Expr RPAR Statement                                   {
                                                                               $$ = ast_node("If","");
                                                                               

                                                                               add_childs($$,$3);


                                                                               if($5 == NULL || strcmp($5->type, "Semicolon") == 0){
                                                                                    add_childs($$,ast_node("Block",""));
                                                                                    add_childs($$,ast_node("Block",""));
                                                                               }else{
                                                                                    add_childs($$,$5);
                                                                                    add_childs($$,ast_node("Block",""));
                                                                               }
                                                                            }

            | IF LPAR Expr RPAR Statement ELSE Statement                    {
                                                                                $$ = ast_node("If","");
                                                                                add_childs($$,$3);
                                                                                if($5 == NULL || strcmp($5->type, "Semicolon") == 0){  //caso o primeiro satatement seja null
                                                                                    add_childs($$,ast_node("Block",""));}
                                                                                else{
                                                                                    add_childs($$,$5);
                                                                                    }
                                                                                if($7 == NULL || strcmp($7->type, "Semicolon") == 0){ //caso o segundo statement seja null
                                                                                    add_childs($$,ast_node("Block",""));}
                                                                                else{
                                                                                    add_childs($$,$7);
                                                                                    }

                                                                            }
            | WHILE LPAR Expr RPAR Statement                                {
                                                                             $$ = ast_node("While","");
                                                                             add_childs($$,$3);

                                                                             if($5 == NULL || strcmp($5->type, "Semicolon") == 0){ //n tiver nd no statement
                                                                                    add_childs($$,ast_node("Block",""));
                                                                                }
                                                                                else{
                                                                                    add_childs($$,$5);
                                                                                }
                                                                             
                                                                            }

            | RETURN Expr SEMICOLON                                                 {$$ = ast_node("Return","");add_childs($$,$2);}
            | RETURN SEMICOLON                                                      {$$ = ast_node("Return", "");}
            | MethodInvocation SEMICOLON                                            {$$ = $1;}
            | Assignment SEMICOLON                                                  {$$ = ast_node("Assign", "");add_childs($$, $1);}
            | ParseArgs SEMICOLON                                                   {$$ = $1;}
            | SEMICOLON                                                             {$$ = ast_node("Semicolon", "");}
            | PRINT LPAR Expr RPAR SEMICOLON                                        {$$ = ast_node("Print","");add_childs($$,$3);}   
            | PRINT LPAR STRLIT RPAR SEMICOLON                                      {$$ = ast_node("Print","");add_childs($$, ast_node("StrLit", $3));}
            | error SEMICOLON                                                       {$$ = NULL;flag_erro = 1;}
            ;

StatementAux: Statement StatementAux                                                {$$ = $1; add_brother($$,$2);}
            |                                                                       {$$ = NULL;}
            ;

MethodInvocation: ID LPAR RPAR                                                      {$$ = ast_node("Call", "");add_childs($$, ast_node("Id", $1));}
                | ID LPAR MethodInvocationaux RPAR                             {$$ = ast_node("Call", "");add_childs($$, ast_node("Id", $1));add_childs($$, $3);}     
                | ID LPAR error RPAR                                                {$$ = NULL;flag_erro = 1;}                             
                ;

MethodInvocationaux: Expr MethodInvocationaux_new                                 {$$ = $1;add_brother($$, $2);}             
                    ;

MethodInvocationaux_new: COMMA Expr MethodInvocationaux_new                        {$$ = $2;add_brother($$, $3);}
                        |                                                       {$$ = NULL;}
                        ;

ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                                       {$$ = ast_node("ParseArgs","");add_childs($$, ast_node("Id", $3));add_childs($$, $5);}
        | PARSEINT LPAR error RPAR                                                  {$$ = NULL;flag_erro = 1;}
        ;

Assignment: ID ASSIGN Expr                                                          {$$ = ast_node("Id", "");add_brother($$, $3);}
     ;


Expr : Expr_aux                                                                      {$$ = $1;}
       | Assignment                                                                  {$$ = ast_node("Assign", ""); add_childs($$, $1);}

Expr_aux : Expr_aux PLUS Expr_aux                                                           {$$ = ast_node("Add","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux MINUS Expr_aux                                                               {$$ = ast_node("Sub","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux STAR Expr_aux                                                                {$$ = ast_node("Mul","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux DIV Expr_aux                                                                 {$$ = ast_node("Div","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux MOD Expr_aux                                                                 {$$ = ast_node("Mod","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux OR Expr_aux                                                                  {$$ = ast_node("Or","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux XOR Expr_aux                                                                 {$$ = ast_node("Xor","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux AND Expr_aux                                                                 {$$ = ast_node("And","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux LSHIFT Expr_aux                                                              {$$ = ast_node("Lshift","");add_childs($$,$1);add_brother($1,$3);} 
    | Expr_aux RSHIFT Expr_aux                                                              {$$ = ast_node("Rshift","");add_childs($$,$1);add_brother($1,$3);} 
    | Expr_aux EQ Expr_aux                                                                  {$$ = ast_node("Eq","");add_childs($$,$1);add_brother($1,$3);}   
    | Expr_aux NE Expr_aux                                                                  {$$ = ast_node("Ne","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux LT Expr_aux                                                                  {$$ = ast_node("Lt","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux GT Expr_aux                                                                  {$$ = ast_node("Gt","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux LE Expr_aux                                                                  {$$ = ast_node("Le","");add_childs($$,$1);add_brother($1,$3);}
    | Expr_aux GE Expr_aux                                                                  {$$ = ast_node("Ge","");add_childs($$,$1);add_brother($1,$3);}
    | MINUS Expr_aux %prec NOT                                                          {$$ = ast_node("Minus","");add_childs($$,$2);} 
    | NOT Expr_aux                                                           {$$ = ast_node("Not","");add_childs($$,$2);}
    | PLUS Expr_aux  %prec NOT                                                          {$$ = ast_node("Plus","");add_childs($$,$2);}
    | LPAR Expr_aux RPAR                                                                {$$ = $2;} 
    | ID                                                                            {$$ = ast_node("Id",$1);}
    | ID DOTLENGTH                                                                  {$$ = ast_node("Length",""); add_childs($$,ast_node("Id",$1));}
    | INTLIT                                                                        {$$ = ast_node("DecLit",$1);}
    | REALLIT                                                                       {$$ = ast_node("RealLit",$1);} 
    | BOOLLIT                                                                       {$$ = ast_node("BoolLit",$1);}
    | MethodInvocation                                                              {$$ = $1;}
    | ParseArgs                                                                     {$$ = $1;}
    | LPAR error RPAR                                                               {$$ = NULL;flag_erro = 1;}
    ;

%%



int main(int argc, char *argv[]){
    if(argc > 1){
		if(strcmp(argv[1],"-e1") == 0){
            /* Analise Lexical : Mostra so os erros */
			flag=0;
            yylex();
		}else if(strcmp(argv[1],"-l") == 0){
            /* Analise Lexical : Mostra tudo */
            flag=1;
            yylex();
        }else if(strcmp(argv[1],"-e2") == 0){
            /* Analise Lexical & Sintatica : Mostra so os erros */
            flag = 2;
            yylex();
            yyparse();  
	}else{
            /* Analise Lexical & Sintatica : Mostra tudo */
            flag = 2;
            yyparse();
            if(flag_erro == 0){
                ast_print(raiz,0);
            }
        }
    }else{
            /* Analise Lexical & Sintatica : Mostra tudo */
            flag = 2;
            yyparse();
            if(flag_erro == 0){
                ast_print(raiz,0);
            }
        }       
    return 0;
}
