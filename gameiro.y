

%{
    #include "y.tab.h"
    int coluna = 1;
    int linha_aux = 0;
    int coluna_aux = 1;
    int linha_aux_2 = 0;
    extern int flag_erro;
    char buffer[1024];
    char buffer_envio[1024];
    
    int error;
    extern int flag;
    extern int flag_erro_string;
    
%}

ID  ([A-Za-z]|[_$])([0-9]|[_$]|[A-Za-z])*
digitos  [0-9]+
nonzeros [1-9]
expoentes   ((E|e)[+-]?{digitos}([0-9]|_)*)
reservadas "switch"|"assert"|"default"|"package"|"finally"|"float"|"implements"|"import"|"instanceof"|"interface"|"long"|"native"|"new"|"synchronized"|"do"|"goto"|"private"|"break"|"++"|"--"|"null"|"Integer"|"System"|"for"|"abstract"|"continue"|"byte"|"case"|"catch"|"char"|"const"|"enum"|"extends"|"final"|"protected"|"short"|"strictfp"|"transient"|"try"|"volatile"|"super"|"this"|"throw"|"throws"
REALLIT (({digitos}*("_"*{digitos})+"."?{expoentes})|({digitos}"."{digitos}?{expoentes}?)|("."{digitos}{expoentes}?)|({digitos}{expoentes})|({digitos}*("_"*{digitos}){expoentes}))|(({digitos}*("_"*{digitos})*"."("_"*{digitos})+({expoentes})?)|({digitos}*("_"*{digitos})+"."))                      
INTLIT {nonzeros}(("_"|{digitos})*{digitos})?|"0"
SPACE " "
NEWLINE "\n"|"\r"|"\r\n"

%X COMMENT STRLLIT SINGLE_LINE_COMMENT

%%  

{reservadas}                {coluna += yyleng;     if(flag == 1){printf("RESERVED(%s)\n", yytext);} else if(flag == 2){return (RESERVED);}  }

"true"|"false"              {coluna += yyleng;     if(flag == 1){printf("BOOLLIT(%s)\n", yytext);}  else if (flag == 2){yylval.string=(char*)strdup(yytext);return(BOOLLIT);}coluna += yyleng;}
"&&"                        {coluna += yyleng;     if(flag == 1){printf("AND\n");}                  else if (flag == 2){return(AND);}       }
"="                         {coluna += yyleng;     if(flag == 1){printf("ASSIGN\n");}               else if (flag == 2){return(ASSIGN);}    }
"*"                         {coluna += yyleng;     if(flag == 1){printf("STAR\n");}                 else if (flag == 2){return(STAR);}      }
","                         {coluna += yyleng;     if(flag == 1){printf("COMMA\n");}                else if (flag == 2){return(COMMA);}     }
"/"                         {coluna += yyleng;     if(flag == 1){printf("DIV\n");}                  else if (flag == 2){return(DIV);}       }
"=="                        {coluna += yyleng;     if(flag == 1){printf("EQ\n");}                   else if (flag == 2){return(EQ);}        }
">="                        {coluna += yyleng;     if(flag == 1){printf("GE\n");}                   else if (flag == 2){return(GE);}        }
">"                         {coluna += yyleng;     if(flag == 1){printf("GT\n");}                   else if (flag == 2){return(GT);}        }
"{"                         {coluna += yyleng;     if(flag == 1){printf("LBRACE\n");}               else if (flag == 2){return(LBRACE);}    }
"<="                        {coluna += yyleng;     if(flag == 1){printf("LE\n");}                   else if (flag == 2){return(LE);}        }
"("                         {coluna += yyleng;     if(flag == 1){printf("LPAR\n");}                 else if (flag == 2){return(LPAR);}      }
"["                         {coluna += yyleng;     if(flag == 1){printf("LSQ\n");}                  else if (flag == 2){return(LSQ);}       }
"<"                         {coluna += yyleng;     if(flag == 1){printf("LT\n");}                   else if (flag == 2){return(LT);}        }
"-"                         {coluna += yyleng;     if(flag == 1){printf("MINUS\n");}                else if (flag == 2){return(MINUS);}     }
"%"                         {coluna += yyleng;     if(flag == 1){printf("MOD\n");}                  else if (flag == 2){return(MOD);}       }
"!="                        {coluna += yyleng;     if(flag == 1){printf("NE\n");}                   else if (flag == 2){return(NE);}        }
"!"                         {coluna += yyleng;     if(flag == 1){printf("NOT\n");}                  else if (flag == 2){return(NOT);}       }
"||"                        {coluna += yyleng;     if(flag == 1){printf("OR\n");}                   else if (flag == 2){return(OR);}        }
"+"                         {coluna += yyleng;     if(flag == 1){printf("PLUS\n");}                 else if (flag == 2){return(PLUS);}      }
"}"                         {coluna += yyleng;     if(flag == 1){printf("RBRACE\n");}               else if (flag == 2){return(RBRACE);}    }
")"                         {coluna += yyleng;     if(flag == 1){printf("RPAR\n");}                 else if (flag == 2){return(RPAR);}      }
"]"                         {coluna += yyleng;     if(flag == 1){printf("RSQ\n");}                  else if (flag == 2){return(RSQ);}       }
";"                         {coluna += yyleng;     if(flag == 1){printf("SEMICOLON\n");}            else if (flag == 2){return(SEMICOLON);} }
"->"                        {coluna += yyleng;     if(flag == 1){printf("ARROW\n");}                else if (flag == 2){return(ARROW);}     }
"<<"                        {coluna += yyleng;     if(flag == 1){printf("LSHIFT\n");}               else if (flag == 2){return(LSHIFT);}    }
">>"                        {coluna += yyleng;     if(flag == 1){printf("RSHIFT\n");}               else if (flag == 2){return(RSHIFT);}    }
"^"                         {coluna += yyleng;     if(flag == 1){printf("XOR\n");}                  else if (flag == 2){return(XOR);}       }
"boolean"                   {coluna += yyleng;     if(flag == 1){printf("BOOL\n");}                 else if (flag == 2){return(BOOL);}      }
"class"                     {coluna += yyleng;     if(flag == 1){printf("CLASS\n");}                else if (flag == 2){return(CLASS);}     }
".length"                   {coluna += yyleng;     if(flag == 1){printf("DOTLENGTH\n");}            else if (flag == 2){return(DOTLENGTH);} }
"double"                    {coluna += yyleng;     if(flag == 1){printf("DOUBLE\n");}               else if (flag == 2){return(DOUBLE);}    }
"else"                      {coluna += yyleng;     if(flag == 1){printf("ELSE\n");}                 else if (flag == 2){return(ELSE);}      }
"if"                        {coluna += yyleng;     if(flag == 1){printf("IF\n");}                   else if (flag == 2){return(IF);}        }
"int"                       {coluna += yyleng;     if(flag == 1){printf("INT\n");}                  else if (flag == 2){return(INT);}       }
"System.out.print"          {coluna += yyleng;     if(flag == 1){printf("PRINT\n");}                else if (flag == 2){return(PRINT);}     }
"Integer.parseInt"          {coluna += yyleng;     if(flag == 1){printf("PARSEINT\n");}             else if (flag == 2){return(PARSEINT);}  }
"public"                    {coluna += yyleng;     if(flag == 1){printf("PUBLIC\n");}               else if (flag == 2){return(PUBLIC);}    }
"return"                    {coluna += yyleng;     if(flag == 1){printf("RETURN\n");}               else if (flag == 2){return(RETURN);}    }
"static"                    {coluna += yyleng;     if(flag == 1){printf("STATIC\n");}               else if (flag == 2){return(STATIC);}    }
"String"                    {coluna += yyleng;     if(flag == 1){printf("STRING\n");}               else if (flag == 2){return(STRING);}    }
"void"                      {coluna += yyleng;     if(flag == 1){printf("VOID\n");}                 else if (flag == 2){return(VOID);}      }
"while"                     {coluna += yyleng;     if(flag == 1){printf("WHILE\n");}                else if (flag == 2){return(WHILE);}     }


{ID}                        {coluna += yyleng; if(flag == 1){printf("ID(%s)\n", yytext);}           else if (flag == 2){yylval.string=(char*)strdup(yytext);return(ID);}}

{REALLIT}                   {coluna += yyleng; if(flag == 1){printf("REALLIT(%s)\n", yytext);}      else if (flag == 2){yylval.string=(char*)strdup(yytext);return(REALLIT);}}

{INTLIT}                    {coluna += yyleng; if(flag == 1){printf("INTLIT(%s)\n", yytext);}       else if (flag == 2){yylval.string=(char*)strdup(yytext);return(INTLIT);}}             


"//"                           {BEGIN SINGLE_LINE_COMMENT;coluna = 1;yylineno++;}
<SINGLE_LINE_COMMENT>{NEWLINE} {BEGIN 0;}
<SINGLE_LINE_COMMENT><<EOF>>   {BEGIN 0;}
<SINGLE_LINE_COMMENT>.         ;

"/""*"                      {linha_aux = yylineno;coluna_aux=coluna;linha_aux_2 = 0;coluna += 2;BEGIN(COMMENT);}
<COMMENT><<EOF>>            {yylineno += linha_aux_2; printf("Line %d, col %d: unterminated comment\n", linha_aux, coluna_aux); BEGIN(0);coluna += yyleng;}
<COMMENT>"*""/"             {yylineno += linha_aux_2; coluna += 2; BEGIN(0);}
<COMMENT>{NEWLINE}          {linha_aux_2++;           coluna = 1;}
<COMMENT>.                  {coluna += yyleng;}

\"                           {coluna_aux = coluna; coluna += 1; linha_aux = yylineno; BEGIN STRLLIT; buffer[0] = '\0'; error = 0;}
<STRLLIT>[^\\"\r\n]*         {coluna+=yyleng; strcat(buffer, yytext);}
<STRLLIT>\\f                 {coluna+=yyleng; strcat(buffer, yytext);}
<STRLLIT>\\n                 {coluna+=yyleng; strcat(buffer, yytext);}
<STRLLIT>\\t                 {coluna+=yyleng; strcat(buffer, yytext);}
<STRLLIT>\\r                 {coluna+=yyleng; strcat(buffer, yytext);}
<STRLLIT>\\[\\"]             {coluna+=yyleng; strcat(buffer, yytext);}
<STRLLIT>\"                  {coluna+=yyleng; BEGIN 0;if (error!=1){ if(flag==1) {printf("STRLLIT(\"%s\")\n", buffer);} else if (flag == 2) {buffer_envio[0] = '\"';strcat(buffer_envio,buffer);strcat(buffer_envio,"\"");yylval.string = (char *)strdup(buffer_envio); bzero(buffer_envio,sizeof(buffer_envio));return(STRLIT);}}}
<STRLLIT>\\.|\\              {error=1; if (yytext[1] != '\r') {printf("Line %d, col %d: invalid escape sequence (%s)\n", yylineno, coluna, yytext); coluna+=yyleng;} else {printf("Line %d, col %d: invalid escape sequence (\\)\n", yylineno, coluna); coluna+=yyleng;}}
<STRLLIT>{NEWLINE}           {error=1; printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); yylineno++; coluna=1; coluna_aux=0;buffer[0] = '\0';BEGIN 0;}
<STRLLIT><<EOF>>             {error=1; printf("Line %d, col %d: unterminated string literal\n", linha_aux, coluna_aux); yylineno++; coluna=1; coluna_aux=0;buffer[0] = '\0'; BEGIN 0;}

"\f"|"\t"                    {coluna += yyleng;}
{SPACE}                      {coluna += yyleng;}
{NEWLINE}                    {yylineno++;coluna = 1;}
.                            {printf("Line %d, col %d: illegal character (%s)\n",yylineno,coluna, yytext);coluna += yyleng;}


%%


void yyerror(char *s) {
    if(strlen(buffer) > 1){
        printf("Line %d, col %d: %s: \"%s\"\n", yylineno, coluna_aux + (int) yyleng - 1, s, buffer);
        buffer[0] = '\0';
    }else{
        if(yylineno == 1 && yytext[-1] != '\n'){
            printf("Line %d, col %d: %s: %s\n", yylineno, coluna - (int) yyleng + 1, s, yytext);
        }else{
            printf("Line %d, col %d: %s: %s\n", yylineno, coluna - (int) yyleng,     s, yytext);
        }
    }
}


int yywrap() {
    return 1;
}

