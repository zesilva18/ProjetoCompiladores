/*
    Autores:
    Gonçalo Franja Ferreira - 2020226867
    Gonçalo Gameiro Neves - 2020239361

*/

%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Tree.h"


struct AST *root;
struct AST *methodParams;
struct AST *temp;
char aux[1024];
char aux2[1024];
struct AST *methodParams;
int flag = 1;

char *type;
int n_sons;
int yydebug = 1;
int print_tree = 1;

int yylex(void);
extern int yylineno;
extern int coluna;
extern int yyerror(char *s);


int yydegug = 1;



%}

%union{
char* string;
struct AST* ast;
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
// Certo
Program: CLASS ID LBRACE ProgramAux RBRACE                   {root = AST_newNode("Program","");AST_addSon(root, AST_newNode("Id", $2));AST_addSon(root,$4);$$ = root;}
        ;
        
// Certo +/- ? 
ProgramAux: /*empty*/									     {$$=NULL;}
          | MethodDecl ProgramAux                            {$$ = $1;AST_addBrother($$, $2);}
          | FieldDecl ProgramAux                             {$$ = $1;AST_addBrother($$, $2);}
          | SEMICOLON ProgramAux                             {$$ = $2;}
          
// Certo
MethodDecl: PUBLIC STATIC MethodHeader MethodBody            {$$ = AST_newNode("MethodDecl","");AST_addSon($$,$3);AST_addSon($$,$4);}   
                                            

// Certo +/- ?   
FieldDecl: PUBLIC STATIC Type ID FieldDeclAux SEMICOLON      {$$ = AST_newNode("FieldDecl", "");AST_addSon($$,$3);AST_addSon($$, AST_newNode("Id", $4));givetype($5, $3->type);AST_addBrother($$, $5);}
        | error SEMICOLON                                    {$$ = NULL;print_tree=0;}// nao recupera deste
        

// Certo ?
FieldDeclAux: COMMA ID FieldDeclAux                          {$$ = AST_newNode("FieldDecl","");AST_addSon($$, AST_newNode("Id", $2));AST_addBrother($$, $3);}

            |                                                {$$ = NULL;}                                     
            
// Certo
Type: INT                                                    {$$ = AST_newNode("Int", "");}
    | DOUBLE                                                 {$$ = AST_newNode("Double", "");}
    | BOOL                                                   {$$ = AST_newNode("Bool", "");}             
    


// Certo ? 
MethodHeader: Type ID LPAR FormalParams RPAR                 {$$ = AST_newNode("MethodHeader","");methodParams = AST_newNode("MethodParams","");AST_addSon($$,$1);AST_addSon($$,AST_newNode("Id", $2));AST_addSon($$, methodParams);AST_addSon(methodParams,$4);}
        | VOID ID LPAR FormalParams RPAR                     {$$ = AST_newNode("MethodHeader","");methodParams = AST_newNode("MethodParams","");AST_addSon($$,AST_newNode("Void", ""));AST_addSon($$,AST_newNode("Id", $2));AST_addSon($$, methodParams);AST_addSon(methodParams,$4);}
                                                               
        
// Certo
FormalParams: Type ID FormalParamsAux                        {$$ = AST_newNode("ParamDecl","");AST_addSon($$,$1);AST_addSon($$,AST_newNode("Id", $2));AST_addBrother($$,$3);}
                                                                            
            | STRING LSQ RSQ ID                              {$$ = AST_newNode("ParamDecl","");AST_addSon($$,AST_newNode("StringArray",""));AST_addSon($$,AST_newNode("Id", $4));}
            |                                                {$$ = NULL;}
            
            
// Certo ? 
FormalParamsAux: COMMA Type ID FormalParamsAux               {$$ = AST_newNode("ParamDecl","");AST_addSon($$,$2);AST_addSon($$,AST_newNode("Id",$3));AST_addBrother($$,$4);}
                                                                            
                |                                            {$$ = NULL;}
                

// Certo
MethodBody: LBRACE MethodBodyAux RBRACE                      {$$ = AST_newNode("MethodBody","");AST_addSon($$,$2);}
          

// Certo
MethodBodyAux: Statement MethodBodyAux                       {if($1 != NULL){$$ = $1; AST_addBrother($$, $2);}else{$$ = $2;}}
             | VarDecl MethodBodyAux                         {$$ = $1; AST_addBrother($$, $2);}
             |                                               {$$ = NULL;}
             

                      

// Certo
VarDecl: Type ID VarDeclAux SEMICOLON                        {$$ = AST_newNode("VarDecl", "");AST_addSon($$, $1);AST_addSon($$, AST_newNode("Id", $2));givetype($3, $1->type);AST_addBrother($$, $3);}
        
// Certo
VarDeclAux: COMMA ID VarDeclAux                              {$$ = AST_newNode("VarDecl","");AST_addSon($$, AST_newNode("Id", $2));AST_addBrother($$, $3);}
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
                                                                    $$ = AST_newNode("Block","");
                                                                    AST_addSon($$,$2);
                                                                    AST_addSon($$,$3);
                                                                }
                                                                else {
                                                                    $$ = $2;
                                                                }
                                                            }

		 | IF LPAR Expr RPAR Statement 					     {
                                                                $$ = AST_newNode("If","");
                                                                AST_addSon($$,$3);
                                                                
                                                                if($5 == NULL || strcmp($5->type,"Semicolon")==0){
                                                                    AST_addSon($$,AST_newNode("Block",""));
                                                                    AST_addSon($$,AST_newNode("Block",""));
                                                                }else{
                                                                    AST_addSon($$,$5);
                                                                    AST_addSon($$,AST_newNode("Block",""));
                                                                }
                                                                
                                                            }


		 | IF LPAR Expr RPAR Statement ELSE Statement 	     {
                                                                $$ = AST_newNode("If","");
                                                                AST_addSon($$,$3);
                                                                if($5 == NULL || strcmp($5->type,"Semicolon")==0){
                                                                    AST_addSon($$,AST_newNode("Block","")); // addbrother(3,5)
                                                                }else{
                                                                    AST_addSon($$,$5);
                                                                }
                                                                if($7 == NULL || strcmp($7->type,"Semicolon")==0){
                                                                    AST_addSon($$,AST_newNode("Block","")); // addbrother(3,7)
                                                                }else{
                                                                    AST_addSon($$,$7);
                                                                }
                                                                
                                                            }
                                                            


		 | WHILE LPAR Expr RPAR Statement 				     {
                                                                $$ = AST_newNode("While","");
                                                                AST_addSon($$,$3);
                                                                if($5 == NULL || strcmp($5->type,"Semicolon")==0){
                                                                    AST_addSon($$,AST_newNode("Block",""));
                                                                }else{
                                                                    AST_addSon($$,$5);
                                                                }
                                                            }
		 
         | RETURN Expr SEMICOLON  						     {$$ = AST_newNode("Return","");AST_addSon($$,$2);}
		 | RETURN SEMICOLON								     {$$ = AST_newNode("Return", "");}
		 | MethodInvocation SEMICOLON 					     {$$ = $1;}
		 | Assignment SEMICOLON 						     {$$ = AST_newNode("Assign","");AST_addSon($$,$1);}
		 | ParseArgs SEMICOLON 							     {$$ = $1;}
		 | SEMICOLON									     {$$ = AST_newNode("Semicolon","");}		
		 | PRINT LPAR Expr RPAR SEMICOLON 				     {$$ = AST_newNode("Print","");AST_addSon($$,$3);}
		 | PRINT LPAR STRLIT RPAR SEMICOLON 			     {$$ = AST_newNode("Print","");AST_addSon($$, AST_newNode("StrLit", $3));}
		 | error SEMICOLON 								     {$$ = NULL;print_tree = 0;}
  
// Certo
StatementAux: Statement StatementAux                         {$$ = $1;AST_addBrother($$,$2);}
            |                                                {$$ = NULL;}
            

// Certo
MethodInvocation:  ID LPAR RPAR 					         {$$ = AST_newNode("Call", "");AST_addSon($$, AST_newNode("Id", $1));}
				| ID LPAR MethodInvocationAux RPAR 		     {$$ = AST_newNode("Call", "");AST_addSon($$, AST_newNode("Id", $1));AST_addSon($$,$3);}
				| ID LPAR error RPAR 					     {$$ = NULL;print_tree = 0;} //  nao recupera deste

// Certo
MethodInvocationAux: Expr MethodInvocationAux_2			     {$$ = $1;AST_addBrother($$,$2);}

// Certo
MethodInvocationAux_2: 						                 {$$ = NULL;}
					| COMMA Expr MethodInvocationAux_2       {$$ = $2;AST_addBrother($$,$3);}
     
// Certo
Assignment: ID ASSIGN Expr                                   {$$ = AST_newNode("Id", $1); AST_addBrother($$,$3);}

// Certo
ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                {$$ = AST_newNode("ParseArgs","");AST_addSon($$, AST_newNode("Id", $3));AST_addSon($$, $5);}
        | PARSEINT LPAR error RPAR                           {$$ = NULL;print_tree=0;}
     
// Certo
Expr: ExprAux                                               {$$ = $1;}
    | Assignment                                            {$$ = AST_newNode("Assign","");AST_addSon($$,$1);}

// Certo
ExprAux: ExprAux PLUS ExprAux                               {$$ = AST_newNode("Add","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux MINUS ExprAux                                 {$$ = AST_newNode("Sub","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux STAR ExprAux                                  {$$ = AST_newNode("Mul","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux DIV ExprAux                                   {$$ = AST_newNode("Div","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux MOD ExprAux                                   {$$ = AST_newNode("Mod","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux OR ExprAux                                    {$$ = AST_newNode("Or","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux XOR ExprAux                                   {$$ = AST_newNode("Xor","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux AND ExprAux                                   {$$ = AST_newNode("And","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux LSHIFT ExprAux                                {$$ = AST_newNode("Lshift","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux RSHIFT ExprAux                                {$$ = AST_newNode("Rshift","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux EQ ExprAux                                    {$$ = AST_newNode("Eq","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux NE ExprAux                                    {$$ = AST_newNode("Ne","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux LT ExprAux                                    {$$ = AST_newNode("Lt","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux GT ExprAux                                    {$$ = AST_newNode("Gt","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux LE ExprAux                                    {$$ = AST_newNode("Le","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | ExprAux GE ExprAux                                    {$$ = AST_newNode("Ge","");AST_addSon($$,$1);AST_addBrother($1,$3);}
    | MINUS ExprAux %prec NOT                               {$$ = AST_newNode("Minus","");AST_addSon($$,$2);}
    | NOT ExprAux                                           {$$ = AST_newNode("Not","");AST_addSon($$,$2);}
    | PLUS ExprAux  %prec NOT                               {$$ = AST_newNode("Plus","");AST_addSon($$,$2);}
    | LPAR Expr RPAR                                        {$$ = $2;}
    | ID                                                    {$$ = AST_newNode("Id",$1);}
    | ID DOTLENGTH                                          {$$ = AST_newNode("Length","");AST_addSon($$,AST_newNode("Id",$1));}
    | INTLIT                                                {$$ = AST_newNode("DecLit",$1);}
    | REALLIT                                               {$$ = AST_newNode("RealLit",$1);}
    | BOOLLIT                                               {$$ = AST_newNode("BoolLit",$1);}
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
            AST_print(root,0);
        }
    }
    AST_free(root);
    return 0;
}

