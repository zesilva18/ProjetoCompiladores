
%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct ast_tree *root;
struct ast_tree *methodParams;
struct ast_tree *temp;
struct ast_tree *aux;
int flag = 1;

char *tipo;
int print_tree = 1;

int yylex(void);
extern int yyerror(char *s);


int yydegug = 1;

typedef struct ast_tree
{
    char *tipo;
    char *value;
    struct ast_tree *pai;
    struct ast_tree *filho;
    struct ast_tree *irmao;
}ast_tree;

//funcoes para a arvore

ast_tree *criar_no(char *token, char* value) { //criar arvore
    ast_tree *node = (ast_tree *)malloc(sizeof(ast_tree));
    node->tipo = token;
    node->value = value;
    node->pai = NULL;
    node->irmao = NULL;
    node->filho = NULL;

    return node;
}

void criar_filhos(ast_tree *root, ast_tree *filho)
{
    if (filho == NULL)
    {
        return;
    }

    if (root == NULL)
    {
        return;
    }

    if (root->filho != NULL)
    {
        ast_tree *aux = root->filho;
        while (aux->irmao != NULL)
        {
            aux = aux->irmao;
        }
        aux->irmao = filho;
    }
    else
    {
        root->filho = filho;
    }
    filho->pai = root;
}

void criar_irmao(ast_tree *irmao, ast_tree *newirmao) { //adicionar irmaos
    if (newirmao == NULL || irmao == NULL) {
        return;
    }

    else {
        ast_tree *aux = irmao;
        while (aux->irmao != NULL) {
            aux = aux->irmao;
        }
        aux->irmao = newirmao;
    }
    newirmao->pai = irmao->pai;
}

void printar_arvore(ast_tree *tree, int n_pontos)
{
    if (tree == NULL)
    {
        return;
    }
    if (strcmp(tree->tipo, "Semicolon") != 0)
    {
        for (int i = 0; i < n_pontos; i++)
            printf(".");

        printf("%s", tree->tipo);
        if (strcmp(tree->value, "") != 0)
        {
            printf("(%s)\n", tree->value);
        }
        else
        {
            printf("\n");
        }
    }
    if (tree->filho != NULL) //funcao recursiva para percorrer a arvore
    {
        printar_arvore(tree->filho, n_pontos + 2);
    }
    if (tree->irmao != NULL)
    {
        printar_arvore(tree->irmao, n_pontos);
    }
}

//create function to free tree 

void free_tree(ast_tree *tree) //funcao para libertar a arvore
{
    if (tree == NULL)
    {
        return;
    }
    if (tree->filho != NULL)
    {
        free_tree(tree->filho);
    }
    if (tree->irmao != NULL)
    {
        free_tree(tree->irmao);
    }
    free(tree);
}

void mantertipo(ast_tree* no,char* tipo){
        ast_tree* auxiliar = NULL;
        for (ast_tree *atual = no; atual; atual = atual->irmao){ //percorre os irmaos do no
            auxiliar=criar_no(tipo, "");
            auxiliar->irmao=atual->filho;
            atual->filho=auxiliar;
        }
}


%}

%union{
char* string;
struct ast_tree* ast;
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

%type <ast> StatementAux Statement ExprAux MethodDecl MethodBody ProgramAux MethodBodyAux Program Expr MethodInvocation Assignment ParseArgs  MethodInvocationAux MethodInvocationAux_2 VarDecl tipo VarDeclAux FieldDecl FieldDeclAux FormalParams FormalParamsAux MethodHeader

//precedencias
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

Program: CLASS ID LBRACE ProgramAux RBRACE                   {root = criar_no("Program","");criar_filhos(root, criar_no("Id", $2));criar_filhos(root,$4);$$ = root;}
        ;
        

ProgramAux: 									             {$$=NULL;}

          | MethodDecl ProgramAux                            {$$ = $1;criar_irmao($$, $2);}

          | FieldDecl ProgramAux                             {$$ = $1;criar_irmao($$, $2);}

          | SEMICOLON ProgramAux                             {$$ = $2;}
          

MethodDecl: PUBLIC STATIC MethodHeader MethodBody            {$$ = criar_no("MethodDecl","");criar_filhos($$,$3);criar_filhos($$,$4);}   
                                            

  
FieldDecl: PUBLIC STATIC tipo ID FieldDeclAux SEMICOLON      {$$ = criar_no("FieldDecl", "");criar_filhos($$,$3);criar_filhos($$, criar_no("Id", $4));mantertipo($5, $3->tipo);criar_irmao($$, $5);}

        | error SEMICOLON                                    {$$ = NULL;print_tree=0;}
        


FieldDeclAux: COMMA ID FieldDeclAux                          {$$ = criar_no("FieldDecl","");criar_filhos($$, criar_no("Id", $2));criar_irmao($$, $3);}

            |                                                {$$ = NULL;}                                     
            
tipo: INT                                                    {$$ = criar_no("Int", "");}

    | DOUBLE                                                 {$$ = criar_no("Double", "");}

    | BOOL                                                   {$$ = criar_no("Bool", "");}             
    

MethodHeader: tipo ID LPAR FormalParams RPAR                 {$$ = criar_no("MethodHeader","");methodParams = criar_no("MethodParams","");criar_filhos($$,$1);criar_filhos($$,criar_no("Id", $2));criar_filhos($$, methodParams);criar_filhos(methodParams,$4);}

        | VOID ID LPAR FormalParams RPAR                     {$$ = criar_no("MethodHeader","");methodParams = criar_no("MethodParams","");criar_filhos($$,criar_no("Void", ""));criar_filhos($$,criar_no("Id", $2));criar_filhos($$, methodParams);criar_filhos(methodParams,$4);}
                                                               

FormalParams: tipo ID FormalParamsAux                        {$$ = criar_no("ParamDecl","");criar_filhos($$,$1);criar_filhos($$,criar_no("Id", $2));criar_irmao($$,$3);}
                                                                            
            | STRING LSQ RSQ ID                              {$$ = criar_no("ParamDecl","");criar_filhos($$,criar_no("StringArray",""));criar_filhos($$,criar_no("Id", $4));}

            |                                                {$$ = NULL;}
            
            

FormalParamsAux: COMMA tipo ID FormalParamsAux               {$$ = criar_no("ParamDecl","");criar_filhos($$,$2);criar_filhos($$,criar_no("Id",$3));criar_irmao($$,$4);}
                                                                            
                |                                            {$$ = NULL;}
                


MethodBody: LBRACE MethodBodyAux RBRACE                      {$$ = criar_no("MethodBody","");criar_filhos($$,$2);}
          


MethodBodyAux: Statement MethodBodyAux                       {if($1 != NULL){$$ = $1; criar_irmao($$, $2);}else{$$ = $2;}}

             | VarDecl MethodBodyAux                         {$$ = $1; criar_irmao($$, $2);}

             |                                               {$$ = NULL;}
             

                      


VarDecl: tipo ID VarDeclAux SEMICOLON                        {$$ = criar_no("VarDecl", "");criar_filhos($$, $1);criar_filhos($$, criar_no("Id", $2));mantertipo($3, $1->tipo);criar_irmao($$, $3);}
        

VarDeclAux: COMMA ID VarDeclAux                              {$$ = criar_no("VarDecl","");criar_filhos($$, criar_no("Id", $2));criar_irmao($$, $3);}
        |                                                    {$$ = NULL;}
        

Statement:  LBRACE Statement StatementAux RBRACE	         {
                                                                int count = 0;
                                                                if($2 != NULL){
                                                                    count++;
                                                                }

                                                                temp = $3;
                                                                while(temp != NULL){
                                                                    if(temp->tipo != NULL){

                                                                        if (strcmp(temp->tipo,"Semicolon")!=0){
                                                                            count++;
                                                                        }
                                                                        
                                                                    }

                                                                    temp = temp->irmao;
                                                                }
                                                                
                                                                if(count <= 1){
                                                                    $$ = $2;
                                                                }

                                                                else {                                                                    
                                                                    $$ = criar_no("Block","");
                                                                    criar_filhos($$,$2);
                                                                    criar_filhos($$,$3);
                                                                }
                                                            }

		 | LBRACE RBRACE 								     {$$ = NULL;}

		 | IF LPAR Expr RPAR Statement 					     {
                                                                $$ = criar_no("If","");

                                                                criar_filhos($$,$3);
                                                                
                                                                if($5 == NULL || strcmp($5->tipo,"Semicolon")==0){
                                                                    criar_filhos($$,criar_no("Block",""));
                                                                    criar_filhos($$,criar_no("Block",""));
                                                                }
                                                                
                                                                else{
                                                                    criar_filhos($$,$5);
                                                                    criar_filhos($$,criar_no("Block",""));
                                                                }
                                                                
                                                            }


		 | IF LPAR Expr RPAR Statement ELSE Statement 	     {
                                                                $$ = criar_no("If","");

                                                                criar_filhos($$,$3);

                                                                if($5 == NULL || strcmp($5->tipo,"Semicolon")==0){
                                                                    criar_filhos($$,criar_no("Block",""));
                                                                }
                                                                else{
                                                                    criar_filhos($$,$5);
                                                                }
                                                                if($7 == NULL || strcmp($7->tipo,"Semicolon")==0){
                                                                    criar_filhos($$,criar_no("Block",""));
                                                                }
                                                                else{
                                                                    criar_filhos($$,$7);
                                                                }
                                                                
                                                            }
                                                            


		 | WHILE LPAR Expr RPAR Statement 				     {
                                                                $$ = criar_no("While","");

                                                                criar_filhos($$,$3);

                                                                if($5 == NULL || strcmp($5->tipo,"Semicolon")==0){
                                                                    criar_filhos($$,criar_no("Block",""));
                                                                }
                                                                else{
                                                                    criar_filhos($$,$5);
                                                                }
                                                            }
		 
         | RETURN Expr SEMICOLON  						     {$$ = criar_no("Return","");criar_filhos($$,$2);}

		 | RETURN SEMICOLON								     {$$ = criar_no("Return", "");}

		 | MethodInvocation SEMICOLON 					     {$$ = $1;}

		 | Assignment SEMICOLON 						     {$$ = criar_no("Assign","");criar_filhos($$,$1);}

		 | ParseArgs SEMICOLON 							     {$$ = $1;}

		 | SEMICOLON									     {$$ = criar_no("Semicolon","");}		

		 | PRINT LPAR Expr RPAR SEMICOLON 				     {$$ = criar_no("Print","");criar_filhos($$,$3);}

		 | PRINT LPAR STRLIT RPAR SEMICOLON 			     {$$ = criar_no("Print","");criar_filhos($$, criar_no("StrLit", $3));}

		 | error SEMICOLON 								     {$$ = NULL;print_tree = 0;}
  

StatementAux: Statement StatementAux                         {$$ = $1;criar_irmao($$,$2);}
            |                                                {$$ = NULL;}
            


MethodInvocation:  ID LPAR RPAR 					         {$$ = criar_no("Call", "");criar_filhos($$, criar_no("Id", $1));}

				| ID LPAR MethodInvocationAux RPAR 		     {$$ = criar_no("Call", "");criar_filhos($$, criar_no("Id", $1));criar_filhos($$,$3);}

				| ID LPAR error RPAR 					     {$$ = NULL;print_tree = 0;} //  nao recupera deste


MethodInvocationAux: Expr MethodInvocationAux_2			     {$$ = $1;criar_irmao($$,$2);}


MethodInvocationAux_2: 						                 {$$ = NULL;}
					| COMMA Expr MethodInvocationAux_2       {$$ = $2;criar_irmao($$,$3);}
     

Assignment: ID ASSIGN Expr                                   {$$ = criar_no("Id", $1); criar_irmao($$,$3);}


ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR                {$$ = criar_no("ParseArgs","");aux = criar_no("Id", $3); criar_filhos($$, aux);criar_irmao(aux, $5);}

        | PARSEINT LPAR error RPAR                           {$$ = NULL;print_tree=0;}
     

Expr: ExprAux                                               {$$ = $1;}

    | Assignment                                            {$$ = criar_no("Assign","");criar_filhos($$,$1);}


ExprAux: ExprAux PLUS ExprAux                               {$$ = criar_no("Add","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux MINUS ExprAux                                 {$$ = criar_no("Sub","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux STAR ExprAux                                  {$$ = criar_no("Mul","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux DIV ExprAux                                   {$$ = criar_no("Div","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux MOD ExprAux                                   {$$ = criar_no("Mod","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux OR ExprAux                                    {$$ = criar_no("Or","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux XOR ExprAux                                   {$$ = criar_no("Xor","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux AND ExprAux                                   {$$ = criar_no("And","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux LSHIFT ExprAux                                {$$ = criar_no("Lshift","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux RSHIFT ExprAux                                {$$ = criar_no("Rshift","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux EQ ExprAux                                    {$$ = criar_no("Eq","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux NE ExprAux                                    {$$ = criar_no("Ne","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux LT ExprAux                                    {$$ = criar_no("Lt","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux GT ExprAux                                    {$$ = criar_no("Gt","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux LE ExprAux                                    {$$ = criar_no("Le","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | ExprAux GE ExprAux                                    {$$ = criar_no("Ge","");criar_filhos($$,$1);criar_irmao($1,$3);}

    | MINUS ExprAux %prec NOT                               {$$ = criar_no("Minus","");criar_filhos($$,$2);}

    | NOT ExprAux                                           {$$ = criar_no("Not","");criar_filhos($$,$2);}

    | PLUS ExprAux  %prec NOT                               {$$ = criar_no("Plus","");criar_filhos($$,$2);}

    | LPAR Expr RPAR                                        {$$ = $2;}

    | ID                                                    {$$ = criar_no("Id",$1);}

    | ID DOTLENGTH                                          {$$ = criar_no("Length","");criar_filhos($$,criar_no("Id",$1));}

    | INTLIT                                                {$$ = criar_no("DecLit",$1);}

    | REALLIT                                               {$$ = criar_no("RealLit",$1);}

    | BOOLLIT                                               {$$ = criar_no("BoolLit",$1);}

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

            //printar arvore

            int numero_pontos = 0;

            printar_arvore(root, numero_pontos);
        }
    }

    //libertar memoria

    free(root);
    free(methodParams);
    free(temp);
    return 0;
}
