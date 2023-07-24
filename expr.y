
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Tree.h"


struct ast_tree *root;
struct ast_tree *methodParams;
struct ast_tree *temp;
char aux[1024];
char aux2[1024];
int flag = 1;

char *type;
int n_sons;
int yydebug = 1;
int print_tree = 1;

int yylex(void);
extern int line;
extern int coluna;
extern int yyerror(char *s);


int yydegug = 1;

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
struct ast_tree* ast;
}

/* TOKENS */
%token CLASS PUBLIC STATIC
%token STRING VOID INT DOUBLE BOOL
%token SEMICOLON COMMA LBRACE RBRACE LPAR RPAR LSQ RSQ ASSIGN
%token PLUS MINUS STAR DIV MOD
%token XOR OR AND EQ NE LE GE LT GT NOT
%token WHILE IF ELSE RETURN 
%token ARROW LSHIFT RSHIFT DOTLENGTH PRINT PARSEINT
%token RESERVED

%token <string> REALLIT STRLIT INTLIT ID BOOLLIT

%type <ast> StatementAux Statement ExprAux MethodDecl MethodBody ProgramAux MethodBodyAux Program Expr MethodInvocation Assignment ParseArgs  MethodInvocationAux MethodInvocationAux_2 VarDecl Type VarDeclAux FieldDecl FieldDeclAux FormalParams FormalParamsAux MethodHeader

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

Program: CLASS ID LBRACE ProgramAux RBRACE                   {root = ast_node("Program","");add_childs(root, ast_node("Id", $2));add_childs(root,$4);$$ = root;}
        ;
        

ProgramAux: 									     {$$=NULL;}
          | MethodDecl ProgramAux                            {$$ = $1;add_brother($$, $2);}
          | FieldDecl ProgramAux                             {$$ = $1;add_brother($$, $2);}
          | SEMICOLON ProgramAux                             {$$ = $2;}
          

MethodDecl: PUBLIC STATIC MethodHeader MethodBody            {$$ = ast_node("MethodDecl","");add_childs($$,$3);add_childs($$,$4);}   
                                            

  
FieldDecl: PUBLIC STATIC Type ID FieldDeclAux SEMICOLON      {$$ = ast_node("FieldDecl", "");add_childs($$,$3);add_childs($$, ast_node("Id", $4));mantertipo($5, $3->type);add_brother($$, $5);}
        | error SEMICOLON                                    {$$ = NULL;print_tree=0;}// nao recupera deste
        


FieldDeclAux: COMMA ID FieldDeclAux                          {$$ = ast_node("FieldDecl","");add_childs($$, ast_node("Id", $2));add_brother($$, $3);}

            |                                                {$$ = NULL;}                                     
            
Type: INT                                                    {$$ = ast_node("Int", "");}
    | DOUBLE                                                 {$$ = ast_node("Double", "");}
    | BOOL                                                   {$$ = ast_node("Bool", "");}             
    

MethodHeader: Type ID LPAR FormalParams RPAR                 {$$ = ast_node("MethodHeader","");methodParams = ast_node("MethodParams","");add_childs($$,$1);add_childs($$,ast_node("Id", $2));add_childs($$, methodParams);add_childs(methodParams,$4);}
        | VOID ID LPAR FormalParams RPAR                     {$$ = ast_node("MethodHeader","");methodParams = ast_node("MethodParams","");add_childs($$,ast_node("Void", ""));add_childs($$,ast_node("Id", $2));add_childs($$, methodParams);add_childs(methodParams,$4);}
                                                               

FormalParams: Type ID FormalParamsAux                        {$$ = ast_node("ParamDecl","");add_childs($$,$1);add_childs($$,ast_node("Id", $2));add_brother($$,$3);}
                                                                            
            | STRING LSQ RSQ ID                              {$$ = ast_node("ParamDecl","");add_childs($$,ast_node("StringArray",""));add_childs($$,ast_node("Id", $4));}
            |                                                {$$ = NULL;}
            
            

FormalParamsAux: COMMA Type ID FormalParamsAux               {$$ = ast_node("ParamDecl","");add_childs($$,$2);add_childs($$,ast_node("Id",$3));add_brother($$,$4);}
                                                                            
                |                                            {$$ = NULL;}
                


MethodBody: LBRACE MethodBodyAux RBRACE                      {$$ = ast_node("MethodBody","");add_childs($$,$2);}
          


MethodBodyAux: Statement MethodBodyAux                       {if($1 != NULL){$$ = $1; add_brother($$, $2);}else{$$ = $2;}}
             | VarDecl MethodBodyAux                         {$$ = $1; add_brother($$, $2);}
             |                                               {$$ = NULL;}
             

                      


VarDecl: Type ID VarDeclAux SEMICOLON                        {$$ = ast_node("VarDecl", "");add_childs($$, $1);add_childs($$, ast_node("Id", $2));mantertipo($3, $1->type);add_brother($$, $3);}
        

VarDeclAux: COMMA ID VarDeclAux                              {$$ = ast_node("VarDecl","");add_childs($$, ast_node("Id", $2));add_brother($$, $3);}
        |                                                    {$$ = NULL;}
        

Statement:  LBRACE Statement StatementAux RBRACE	         {
                                                                int count = 0;
                                                                if($2 != NULL){
                                                                    count++;
                                                                }
                                                                temp = $3;
                                                                while(temp != NULL){
                                                                    if(temp->type != NULL && strcmp(temp->type,"Semicolon")!=0){
                                                                        count++;
                                                                    }

                                                                    temp = temp->brother;
                                                                }
                                                                
                                                                if(count > 1){
                                                                    $$ = ast_node("Block","");
                                                                    add_childs($$,$2);
                                                                    add_childs($$,$3);
                                                                }
                                                                else {
                                                                    $$ = $2;
                                                                }
                                                            }

		 | LBRACE RBRACE 								     {$$ = NULL;}

		 | IF LPAR Expr RPAR Statement 					     {
                                                                $$ = ast_node("If","");
                                                                add_childs($$,$3);
                                                                
                                                                if($5 == NULL || strcmp($5->type,"Semicolon")==0){
                                                                    add_childs($$,ast_node("Block",""));
                                                                    add_childs($$,ast_node("Block",""));
                                                                }else{
                                                                    add_childs($$,$5);
                                                                    add_childs($$,ast_node("Block",""));
                                                                }
                                                                
                                                            }


		 | IF LPAR Expr RPAR Statement ELSE Statement 	     {
                                                                $$ = ast_node("If","");
                                                                add_childs($$,$3);
                                                                if($5 == NULL || strcmp($5->type,"Semicolon")==0){
                                                                    add_childs($$,ast_node("Block","")); // addbrother(3,5)
                                                                }else{
                                                                    add_childs($$,$5);
                                                                }
                                                                if($7 == NULL || strcmp($7->type,"Semicolon")==0){
                                                                    add_childs($$,ast_node("Block","")); // addbrother(3,7)
                                                                }else{
                                                                    add_childs($$,$7);
                                                                }
                                                                
                                                            }
                                                            


		 | WHILE LPAR Expr RPAR Statement 				     {
                                                                $$ = ast_node("While","");
                                                                add_childs($$,$3);
                                                                if($5 == NULL || strcmp($5->type,"Semicolon")==0){
                                                                    add_childs($$,ast_node("Block",""));
                                                                }else{
                                                                    add_childs($$,$5);
                                                                }
                                                            }
		 
         | RETURN Expr SEMICOLON  						     {$$ = ast_node("Return","");add_childs($$,$2);}
		 | RETURN SEMICOLON								     {$$ = ast_node("Return", "");}
		 | MethodInvocation SEMICOLON 					     {$$ = $1;}
		 | Assignment SEMICOLON 						     {$$ = ast_node("Assign","");add_childs($$,$1);}
		 | ParseArgs SEMICOLON 							     {$$ = $1;}
		 | SEMICOLON									     {$$ = ast_node("Semicolon","");}		
		 | PRINT LPAR Expr RPAR SEMICOLON 				     {$$ = ast_node("Print","");add_childs($$,$3);}
		 | PRINT LPAR STRLIT RPAR SEMICOLON 			     {$$ = ast_node("Print","");add_childs($$, ast_node("StrLit", $3));}
		 | error SEMICOLON 								     {$$ = NULL;print_tree = 0;}
  
// Certo
StatementAux: Statement StatementAux                         {$$ = $1;add_brother($$,$2);}
            |                                                {$$ = NULL;}
            

// Certo
MethodInvocation:  ID LPAR RPAR 					         {$$ = ast_node("Call", "");add_childs($$, ast_node("Id", $1));}
				| ID LPAR MethodInvocationAux RPAR 		     {$$ = ast_node("Call", "");add_childs($$, ast_node("Id", $1));add_childs($$,$3);}
				| ID LPAR error RPAR 					     {$$ = NULL;print_tree = 0;} //  nao recupera deste

// Certo
MethodInvocationAux: Expr MethodInvocationAux_2			     {$$ = $1;add_brother($$,$2);}

// Certo
MethodInvocationAux_2: 						                 {$$ = NULL;}
					| COMMA Expr MethodInvocationAux_2       {$$ = $2;add_brother($$,$3);}
     
// Certo
Assignment: ID ASSIGN Expr                                   {$$ = ast_node("Id", $1); add_brother($$,$3);}

// Certo
ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                {$$ = ast_node("ParseArgs","");add_childs($$, ast_node("Id", $3));add_childs($$, $5);}
        | PARSEINT LPAR error RPAR                           {$$ = NULL;print_tree=0;}
     
// Certo
Expr: ExprAux                                               {$$ = $1;}
    | Assignment                                            {$$ = ast_node("Assign","");add_childs($$,$1);}

// Certo
ExprAux: ExprAux PLUS ExprAux                               {$$ = ast_node("Add","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux MINUS ExprAux                                 {$$ = ast_node("Sub","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux STAR ExprAux                                  {$$ = ast_node("Mul","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux DIV ExprAux                                   {$$ = ast_node("Div","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux MOD ExprAux                                   {$$ = ast_node("Mod","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux OR ExprAux                                    {$$ = ast_node("Or","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux XOR ExprAux                                   {$$ = ast_node("Xor","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux AND ExprAux                                   {$$ = ast_node("And","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux LSHIFT ExprAux                                {$$ = ast_node("Lshift","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux RSHIFT ExprAux                                {$$ = ast_node("Rshift","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux EQ ExprAux                                    {$$ = ast_node("Eq","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux NE ExprAux                                    {$$ = ast_node("Ne","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux LT ExprAux                                    {$$ = ast_node("Lt","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux GT ExprAux                                    {$$ = ast_node("Gt","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux LE ExprAux                                    {$$ = ast_node("Le","");add_childs($$,$1);add_brother($1,$3);}
    | ExprAux GE ExprAux                                    {$$ = ast_node("Ge","");add_childs($$,$1);add_brother($1,$3);}
    | MINUS ExprAux %prec NOT                               {$$ = ast_node("Minus","");add_childs($$,$2);}
    | NOT ExprAux                                           {$$ = ast_node("Not","");add_childs($$,$2);}
    | PLUS ExprAux  %prec NOT                               {$$ = ast_node("Plus","");add_childs($$,$2);}
    | LPAR Expr RPAR                                        {$$ = $2;}
    | ID                                                    {$$ = ast_node("Id",$1);}
    | ID DOTLENGTH                                          {$$ = ast_node("Length","");add_childs($$,ast_node("Id",$1));}
    | INTLIT                                                {$$ = ast_node("DecLit",$1);}
    | REALLIT                                               {$$ = ast_node("RealLit",$1);}
    | BOOLLIT                                               {$$ = ast_node("BoolLit",$1);}
    | MethodInvocation                                      {$$ = $1;}
    | ParseArgs                                             {$$ = $1;}
    | LPAR error RPAR                                       {$$ = NULL;print_tree=0;}
    

%%



int main(int argc, char *argv[]){
	if(strcmp(argv[1],"-e1") == 0){
        /* Analise Lexical : Mostra so os erros */
		flag=0;
        yylex();
    }else if(strcmp(argv[1],"-l") == 0){
        /* Analise Lexical : Mostra os erros e os tokens */
        flag=1;
        yylex();
    }
    if(strcmp(argv[1],"-e2") == 0){
        /* Analise Sintatica : Mostra so os erros */
        flag=2;
        yyparse();
    }
    else if(strcmp(argv[1],"-t") == 0){
        /* Analise Sintatica : Mostra os erros e a arvore */
        flag=2;
        yyparse();
        if(print_tree == 1){
            ast_print(root,0);
        }
    }
    return 0;
}
