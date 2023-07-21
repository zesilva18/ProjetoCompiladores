
/*José Pedro Ferreira Dinis e Silva Nº 2020237724 */


%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"
    #include "tree.h"

    int line = 1; 
    int collum = 1;
    int nova_coluna = 0;
    int nova_linha = 0; 
    int nova_linha2 = 0;
    int erro_linha = 0;
    int erro_coluna = 0;
    char buffer[1024];
    char strlit[1024];
    extern int flag; 
    extern int error;
    extern int flag_erro;
%}

barras ("\r"|"\n"|"\r\n")

reserved ("++"|"--"|"null"|"Integer"|"System"|"for"|"abstract"|"continue"|"switch"|"assert"|"default"|"package"|"synchronized"|"do"|"goto"|"private"|"break"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"finally"|"float"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"protected"|"short"|"strictfp"|"super"|"this"|"throw"|"throws"|"transient"|"try"|"volatile")

exponte                 (e|E)("+"|"-")?([0-9]|[0-9]["_"0-9]*[0-9])+
reallit					(([0-9]|[0-9]["_"0-9]*[0-9])+"."([0-9]|[0-9]["_"0-9]*[0-9])*{exponte}?)|(([0-9]|[0-9]["_"0-9]*[0-9])+{exponte})|("."([0-9]|[0-9]["_"0-9]*[0-9])+{exponte}?)

%X COMENTARIOS STRINGS ERRORSTRLIT ERRORESC SL_COMMENT
%%

"true"|"false"                          {if (flag==1){printf("BOOLLIT(%s)\n",yytext);}else if (flag==2) {yylval.string=(char*)strdup(yytext); return(BOOLLIT);}collum += yyleng;}

"&&"                                    {if (flag==1){printf("AND\n");}else if (flag==2) {return(AND);}collum += yyleng;}

"="                                     {if (flag==1){printf("ASSIGN\n");}else if (flag==2) {return(ASSIGN);}collum += yyleng;}

"*"                                     {if (flag==1){printf("STAR\n");}else if (flag==2) {return(STAR);}collum += yyleng;} 

","                                     {if (flag==1){printf("COMMA\n");}else if (flag==2) {return(COMMA);}collum += yyleng;}

"/"                                     {if (flag==1){printf("DIV\n");} else if (flag==2) {return(DIV);}collum += yyleng;}

"=="                                    {if (flag==1){printf("EQ\n");}else if (flag==2) {return(EQ);}collum += yyleng;}

">="                                    {if (flag==1){printf("GE\n");}else if (flag==2) {return(GE);}collum += yyleng;}

">"                                     {if (flag==1){printf("GT\n");}else if (flag==2) {return(GT);}collum += yyleng;}

"{"                                     {if (flag==1){printf("LBRACE\n");} else if (flag==2) {return(LBRACE);} collum += yyleng;}

"<="                                    {if (flag==1){printf("LE\n");} else if (flag==2) {return(LE);} collum += yyleng;}

"("                                     {if (flag==1){printf("LPAR\n");} else if (flag==2) {return(LPAR);}collum += yyleng;}

"["                                     {if (flag==1){printf("LSQ\n");}else if (flag==2) {return(LSQ);}collum += yyleng;}

"<"                                     {if (flag==1){printf("LT\n");}else if (flag==2) {return(LT);}collum += yyleng;}

"-"                                     {if (flag==1){printf("MINUS\n");}else if (flag==2) {return(MINUS);}collum += yyleng;}

"%"                                     {if (flag==1){printf("MOD\n");}else if (flag==2) {return(MOD);}collum += yyleng;}

"!="                                    {if (flag==1){printf("NE\n");}else if (flag==2) {return(NE);}collum += yyleng;}

"!"                                     {if (flag==1){printf("NOT\n");}else if (flag==2) {return(NOT);}collum += yyleng;}

"||"                                    {if (flag==1){printf("OR\n");}else if (flag==2) {return(OR);}collum += yyleng;}

"+"                                     {if (flag==1){printf("PLUS\n");}else if (flag==2) {return(PLUS);}collum += yyleng;}

"}"                                     {if (flag==1){printf("RBRACE\n");}else if (flag==2) {return(RBRACE);}collum += yyleng;}

")"                                     {if (flag==1){printf("RPAR\n");}else if (flag==2) {return(RPAR);}collum += yyleng;}

"]"                                     {if (flag==1){printf("RSQ\n");}else if (flag==2) {return(RSQ);}collum += yyleng;}

";"                                     {if (flag==1){printf("SEMICOLON\n");}else if (flag==2) {return(SEMICOLON);}collum += yyleng;}

"->"                                    {if (flag==1){printf("ARROW\n");}else if (flag==2) {return(ARROW);}collum += yyleng;}

"<<"                                    {if (flag==1){printf("LSHIFT\n");}else if (flag==2) {return(LSHIFT);}collum += yyleng;}

">>"                                    {if (flag==1){printf("RSHIFT\n");}else if (flag==2) {return(RSHIFT);}collum += yyleng;}

"^"                                     {if (flag==1){printf("XOR\n");}else if (flag==2) {return(XOR);}collum += yyleng;}

"boolean"                               {if (flag==1){printf("BOOL\n");}else if (flag==2) {return(BOOL);}collum += yyleng;}

"class"                                 {if (flag==1){printf("CLASS\n");}else if (flag==2) {return(CLASS);}collum += yyleng;}

".length"                               {if (flag==1){printf("DOTLENGTH\n");}else if (flag==2) {return(DOTLENGTH);}collum += yyleng;}

"double"                                {if (flag==1){printf("DOUBLE\n");}else if (flag==2) {return(DOUBLE);}collum += yyleng;}

"else"                                  {if (flag==1){printf("ELSE\n");}else if (flag==2) {return(ELSE);}collum += yyleng;}

"if"                                    {if (flag==1){printf("IF\n");}else if (flag==2) {return(IF);}collum += yyleng;}

"int"                                   {if (flag==1){printf("INT\n");}else if (flag==2) {return(INT);}collum += yyleng;}

"System.out.print"                      {if (flag==1){printf("PRINT\n");}else if (flag==2) {return(PRINT);}collum += yyleng;}

"Integer.parseInt"                      {if (flag==1){printf("PARSEINT\n");}else if (flag==2) {return(PARSEINT);}collum += yyleng;}

"public"                                {if (flag==1){printf("PUBLIC\n");}else if (flag==2) {return(PUBLIC);}collum += yyleng;}

"return"                                {if (flag==1){printf("RETURN\n");}else if (flag==2) {return(RETURN);}collum += yyleng;}

"static"                                {if (flag==1){printf("STATIC\n");}else if (flag==2) {return(STATIC);}collum += yyleng;}

"String"                                {if (flag==1){printf("STRING\n");}else if (flag==2) {return(STRING);}collum += yyleng;}

"void"                                  {if (flag==1){printf("VOID\n");}else if (flag==2) {return(VOID);}collum += yyleng;}

"while"                                 {if (flag==1){printf("WHILE\n");}else if (flag==2) {return(WHILE);}collum += yyleng;}


\"                           {nova_coluna = collum; collum += 1; nova_linha=line; BEGIN STRINGS; buffer[0] = '\0'; error = 0;}
<STRINGS>[^\\"\r\n]*         {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\f                 {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\n                 {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\t                 {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\r                 {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\\[\\"]             {collum+=yyleng; strcat(buffer, yytext);}
<STRINGS>\"                  {collum+=yyleng; BEGIN 0; if (error!=1){if(flag==1){printf("STRLIT(\"%s\")\n", buffer);}else if (flag==2) {strlit[0] = '"'; strcat(strlit, buffer); strcat(strlit, "\""); yylval.string=(char*)strdup(strlit);  bzero(strlit,sizeof(strlit)); return(STRLIT);}}}
<STRINGS>\\.|\\              {error=1; if (yytext[1] != '\r') {printf("Line %d, col %d: invalid escape sequence (%s)\n", line, collum, yytext); collum+=yyleng;} else {printf("Line %d, col %d: invalid escape sequence (\\)\n", line, collum); collum+=yyleng;}}
<STRINGS>{barras}     {error=1; printf("Line %d, col %d: unterminated string literal\n", nova_linha, nova_coluna); line++; collum=1; nova_coluna=0; BEGIN 0;}
<STRINGS><<EOF>>             {error=1; printf("Line %d, col %d: unterminated string literal\n", nova_linha, nova_coluna); line++; collum=1; nova_coluna=0; BEGIN 0;}



{reserved}   {if (flag==1){ printf("RESERVED(%s)\n", yytext);}else if(flag == 2){return(RESERVED);}collum += yyleng;}

[A-Za-z_\$][0-9A-Za-z_\$]*                                                                                                             {if (flag==1){printf("ID(%s)\n", yytext);}else if (flag==2) {yylval.string=(char*)strdup(yytext); return(ID);}collum += yyleng;}

{reallit}                                                                                            {if (flag==1){printf("REALLIT(%s)\n", yytext);}else if (flag==2) {yylval.string=(char*)strdup(yytext); return(REALLIT);}collum += yyleng;}


[0-9]|[1-9]["_"0-9]*[0-9]                                                                                              {if (flag==1){ printf("INTLIT(%s)\n", yytext);}else if (flag==2) {yylval.string=(char*)strdup(yytext); return(INTLIT);}collum += yyleng;}


"//"                           {BEGIN SL_COMMENT;collum = 1;line++;}
<SL_COMMENT>{barras}   {BEGIN 0;}
<SL_COMMENT><<EOF>>            {BEGIN 0;}
<SL_COMMENT>.                  ;   

"/""*"                          {nova_linha = line;nova_coluna=collum; nova_linha2 = 0;collum += 2;BEGIN(COMENTARIOS);}
<COMENTARIOS><<EOF>>            {line += nova_linha2; printf("Line %d, col %d: unterminated comment\n", nova_linha, nova_coluna); BEGIN(0);collum += yyleng;}
<COMENTARIOS>"*""/"             {BEGIN(0); line += nova_linha2; collum+=2;}
<COMENTARIOS>{barras}   {nova_linha2++;collum = 1;}
<COMENTARIOS>.                  {collum += yyleng;}

"\f"|"\t"                                    {collum += yyleng;}
" "                                          {collum += yyleng;}
"\n"|"\r"|"\r\n"                             {line++; collum = 1;}
.                                            {printf("Line %d, col %d: illegal character (%s)\n",line,collum, yytext);collum += yyleng;}


%%

int yywrap(){ 
return 1;
}

void yyerror(char *s){
    if(flag_erro == 1){
            printf("Line %d, col %d: %s: %s\n", line, collum, s, yytext);
    }
    else{
        printf("Line %d, col %d: %s: %s", erro_linha, erro_coluna, s, yytext);
    }
}