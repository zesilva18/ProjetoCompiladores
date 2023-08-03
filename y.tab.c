/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "jucompiler.y"

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



#line 219 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    CLASS = 258,                   /* CLASS  */
    PUBLIC = 259,                  /* PUBLIC  */
    STATIC = 260,                  /* STATIC  */
    STRING = 261,                  /* STRING  */
    VOID = 262,                    /* VOID  */
    INT = 263,                     /* INT  */
    DOUBLE = 264,                  /* DOUBLE  */
    BOOL = 265,                    /* BOOL  */
    SEMICOLON = 266,               /* SEMICOLON  */
    COMMA = 267,                   /* COMMA  */
    LBRACE = 268,                  /* LBRACE  */
    RBRACE = 269,                  /* RBRACE  */
    LPAR = 270,                    /* LPAR  */
    RPAR = 271,                    /* RPAR  */
    LSQ = 272,                     /* LSQ  */
    RSQ = 273,                     /* RSQ  */
    ASSIGN = 274,                  /* ASSIGN  */
    PLUS = 275,                    /* PLUS  */
    MINUS = 276,                   /* MINUS  */
    STAR = 277,                    /* STAR  */
    DIV = 278,                     /* DIV  */
    MOD = 279,                     /* MOD  */
    XOR = 280,                     /* XOR  */
    OR = 281,                      /* OR  */
    AND = 282,                     /* AND  */
    EQ = 283,                      /* EQ  */
    NE = 284,                      /* NE  */
    LE = 285,                      /* LE  */
    GE = 286,                      /* GE  */
    LT = 287,                      /* LT  */
    GT = 288,                      /* GT  */
    NOT = 289,                     /* NOT  */
    WHILE = 290,                   /* WHILE  */
    IF = 291,                      /* IF  */
    ELSE = 292,                    /* ELSE  */
    RETURN = 293,                  /* RETURN  */
    ARROW = 294,                   /* ARROW  */
    LSHIFT = 295,                  /* LSHIFT  */
    RSHIFT = 296,                  /* RSHIFT  */
    DOTLENGTH = 297,               /* DOTLENGTH  */
    PRINT = 298,                   /* PRINT  */
    PARSEINT = 299,                /* PARSEINT  */
    RESERVED = 300,                /* RESERVED  */
    REALLIT = 301,                 /* REALLIT  */
    STRLIT = 302,                  /* STRLIT  */
    INTLIT = 303,                  /* INTLIT  */
    ID = 304,                      /* ID  */
    BOOLLIT = 305                  /* BOOLLIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define CLASS 258
#define PUBLIC 259
#define STATIC 260
#define STRING 261
#define VOID 262
#define INT 263
#define DOUBLE 264
#define BOOL 265
#define SEMICOLON 266
#define COMMA 267
#define LBRACE 268
#define RBRACE 269
#define LPAR 270
#define RPAR 271
#define LSQ 272
#define RSQ 273
#define ASSIGN 274
#define PLUS 275
#define MINUS 276
#define STAR 277
#define DIV 278
#define MOD 279
#define XOR 280
#define OR 281
#define AND 282
#define EQ 283
#define NE 284
#define LE 285
#define GE 286
#define LT 287
#define GT 288
#define NOT 289
#define WHILE 290
#define IF 291
#define ELSE 292
#define RETURN 293
#define ARROW 294
#define LSHIFT 295
#define RSHIFT 296
#define DOTLENGTH 297
#define PRINT 298
#define PARSEINT 299
#define RESERVED 300
#define REALLIT 301
#define STRLIT 302
#define INTLIT 303
#define ID 304
#define BOOLLIT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 150 "jucompiler.y"

char* string;
struct ast_tree* ast;

#line 377 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CLASS = 3,                      /* CLASS  */
  YYSYMBOL_PUBLIC = 4,                     /* PUBLIC  */
  YYSYMBOL_STATIC = 5,                     /* STATIC  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_DOUBLE = 9,                     /* DOUBLE  */
  YYSYMBOL_BOOL = 10,                      /* BOOL  */
  YYSYMBOL_SEMICOLON = 11,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_LBRACE = 13,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 14,                    /* RBRACE  */
  YYSYMBOL_LPAR = 15,                      /* LPAR  */
  YYSYMBOL_RPAR = 16,                      /* RPAR  */
  YYSYMBOL_LSQ = 17,                       /* LSQ  */
  YYSYMBOL_RSQ = 18,                       /* RSQ  */
  YYSYMBOL_ASSIGN = 19,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 20,                      /* PLUS  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_STAR = 22,                      /* STAR  */
  YYSYMBOL_DIV = 23,                       /* DIV  */
  YYSYMBOL_MOD = 24,                       /* MOD  */
  YYSYMBOL_XOR = 25,                       /* XOR  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_AND = 27,                       /* AND  */
  YYSYMBOL_EQ = 28,                        /* EQ  */
  YYSYMBOL_NE = 29,                        /* NE  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_GE = 31,                        /* GE  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_NOT = 34,                       /* NOT  */
  YYSYMBOL_WHILE = 35,                     /* WHILE  */
  YYSYMBOL_IF = 36,                        /* IF  */
  YYSYMBOL_ELSE = 37,                      /* ELSE  */
  YYSYMBOL_RETURN = 38,                    /* RETURN  */
  YYSYMBOL_ARROW = 39,                     /* ARROW  */
  YYSYMBOL_LSHIFT = 40,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 41,                    /* RSHIFT  */
  YYSYMBOL_DOTLENGTH = 42,                 /* DOTLENGTH  */
  YYSYMBOL_PRINT = 43,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 44,                  /* PARSEINT  */
  YYSYMBOL_RESERVED = 45,                  /* RESERVED  */
  YYSYMBOL_REALLIT = 46,                   /* REALLIT  */
  YYSYMBOL_STRLIT = 47,                    /* STRLIT  */
  YYSYMBOL_INTLIT = 48,                    /* INTLIT  */
  YYSYMBOL_ID = 49,                        /* ID  */
  YYSYMBOL_BOOLLIT = 50,                   /* BOOLLIT  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_ProgramAux = 53,                /* ProgramAux  */
  YYSYMBOL_MethodDecl = 54,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 55,                 /* FieldDecl  */
  YYSYMBOL_FieldDeclAux = 56,              /* FieldDeclAux  */
  YYSYMBOL_tipo = 57,                      /* tipo  */
  YYSYMBOL_MethodHeader = 58,              /* MethodHeader  */
  YYSYMBOL_FormalParams = 59,              /* FormalParams  */
  YYSYMBOL_FormalParamsAux = 60,           /* FormalParamsAux  */
  YYSYMBOL_MethodBody = 61,                /* MethodBody  */
  YYSYMBOL_MethodBodyAux = 62,             /* MethodBodyAux  */
  YYSYMBOL_VarDecl = 63,                   /* VarDecl  */
  YYSYMBOL_VarDeclAux = 64,                /* VarDeclAux  */
  YYSYMBOL_Statement = 65,                 /* Statement  */
  YYSYMBOL_StatementAux = 66,              /* StatementAux  */
  YYSYMBOL_MethodInvocation = 67,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocationAux = 68,       /* MethodInvocationAux  */
  YYSYMBOL_MethodInvocationAux_2 = 69,     /* MethodInvocationAux_2  */
  YYSYMBOL_Assignment = 70,                /* Assignment  */
  YYSYMBOL_ParseArgs = 71,                 /* ParseArgs  */
  YYSYMBOL_Expr = 72,                      /* Expr  */
  YYSYMBOL_ExprAux = 73                    /* ExprAux  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   384

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   188,   188,   192,   194,   196,   198,   201,   205,   207,
     211,   213,   215,   217,   219,   222,   224,   227,   229,   231,
     235,   237,   241,   245,   247,   249,   255,   258,   259,   262,
     292,   294,   312,   334,   347,   349,   351,   353,   355,   357,
     359,   361,   363,   366,   367,   371,   373,   375,   378,   381,
     382,   385,   388,   390,   393,   395,   398,   400,   402,   404,
     406,   408,   410,   412,   414,   416,   418,   420,   422,   424,
     426,   428,   430,   432,   434,   436,   438,   440,   442,   444,
     446,   448,   450,   452
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CLASS", "PUBLIC",
  "STATIC", "STRING", "VOID", "INT", "DOUBLE", "BOOL", "SEMICOLON",
  "COMMA", "LBRACE", "RBRACE", "LPAR", "RPAR", "LSQ", "RSQ", "ASSIGN",
  "PLUS", "MINUS", "STAR", "DIV", "MOD", "XOR", "OR", "AND", "EQ", "NE",
  "LE", "GE", "LT", "GT", "NOT", "WHILE", "IF", "ELSE", "RETURN", "ARROW",
  "LSHIFT", "RSHIFT", "DOTLENGTH", "PRINT", "PARSEINT", "RESERVED",
  "REALLIT", "STRLIT", "INTLIT", "ID", "BOOLLIT", "$accept", "Program",
  "ProgramAux", "MethodDecl", "FieldDecl", "FieldDeclAux", "tipo",
  "MethodHeader", "FormalParams", "FormalParamsAux", "MethodBody",
  "MethodBodyAux", "VarDecl", "VarDeclAux", "Statement", "StatementAux",
  "MethodInvocation", "MethodInvocationAux", "MethodInvocationAux_2",
  "Assignment", "ParseArgs", "Expr", "ExprAux", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-41)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   -40,    21,    14,   -41,    35,    18,    28,    35,    34,
      35,    35,   -41,   110,   -41,   -41,   -41,   -41,     8,   -41,
     -41,   -41,     9,    49,    60,    30,   166,   -41,    68,    15,
      68,    73,    75,   -41,   170,    76,    83,    82,    84,    99,
      -3,    66,   107,   166,   166,   111,   114,   118,   117,    86,
     125,   130,   127,   -41,   -41,   -41,   185,   224,   224,   -41,
      46,   256,   256,   256,   -41,   -41,    -4,   -41,   -41,   -41,
     -41,   133,   287,   217,     2,    39,   224,   134,   -41,   -41,
     -41,   -41,   -41,   -41,   132,   136,   -41,   -41,   -41,   185,
     131,   152,   153,   154,   156,   -11,   -41,   -41,   -41,   -41,
     -41,   256,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   256,   256,   256,   256,   256,   157,   162,   169,
     165,   171,   -41,   172,   177,   -41,   141,   180,   143,    96,
     -41,   -41,   -41,   211,   211,   -41,   -41,   115,   115,   -41,
     -41,   -41,   337,   309,   323,   351,   351,    48,    48,    48,
      48,   263,   263,   182,   183,   -41,   224,   -41,   -41,   224,
     -41,   134,   -41,   -41,   146,   -41,   160,   -41,   -41,   189,
     177,   -41,   136,   211,   184,   -41,   -41,   -41,   -41
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     0,     6,     2,     4,     5,     0,    12,
      13,    14,     0,     0,     0,    11,     0,     7,    19,     0,
      19,     0,     0,    39,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,     0,     8,    42,    30,     0,     0,     0,    35,
       0,     0,     0,     0,    79,    78,    76,    80,    81,    55,
      82,     0,    54,     0,     0,     0,     0,    28,    22,    24,
      23,    36,    37,    38,     0,    21,    16,    10,    15,     0,
       0,     0,     0,     0,     0,    76,    74,    72,    73,    77,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,    49,    51,     0,     0,     0,     0,
      17,    43,    29,     0,     0,    83,    75,    56,    57,    58,
      59,    60,    62,    61,    63,    66,    67,    70,    71,    68,
      69,    64,    65,     0,     0,    53,     0,    47,    46,     0,
      48,    28,    26,    18,     0,    33,    31,    41,    40,     0,
      49,    27,    21,     0,     0,    50,    20,    32,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -41,   -41,    71,   -41,   -41,   167,    -6,   -41,   173,    44,
     -41,   -30,   -41,    56,   -33,   122,   -26,   -41,    55,   -32,
     -24,   -23,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    41,    23,    50,   130,
      27,    42,    43,   127,    44,    90,    68,   123,   160,    46,
      70,    71,    72
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    56,    47,   119,    75,    69,     1,    22,    45,     3,
      47,    75,    75,    79,    80,    76,    76,    45,    45,    47,
      47,     4,    49,    89,    49,    69,    69,     5,    69,    12,
      45,    99,    47,    13,    91,    92,     6,    94,    99,     7,
     121,    69,    29,    69,    69,    30,     8,    93,    15,    -3,
     118,   120,   124,   125,    60,   122,    89,    24,    25,    61,
      62,    60,    26,    45,    51,    47,    61,    62,   101,   102,
     103,   104,   105,    63,    48,    28,    19,    20,    21,    14,
      63,    16,    17,    39,    53,    64,    54,    65,    66,    67,
      39,    57,    64,    59,    65,    66,    67,    60,    58,    73,
     165,   166,    61,    62,    19,    20,    21,    45,    45,    47,
      47,    96,    97,    98,    74,    77,    63,    18,    19,    20,
      21,    78,    81,   164,    69,    82,    39,    69,    64,    83,
      65,    66,    67,   169,    84,    85,   170,   103,   104,   105,
     177,    86,    29,    88,   100,   132,   126,    45,   129,    47,
     128,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    32,   133,   134,
     135,    32,   136,   153,    19,    20,    21,    33,   154,    34,
     -25,    33,   156,    34,    55,   155,    32,   157,   158,   159,
     161,   162,   163,   167,   168,   172,    33,   173,    34,   -44,
     178,    35,    36,    52,    37,    35,    36,   174,    37,    38,
      39,   131,    32,    38,    39,    40,   176,   171,    87,    40,
      35,    36,    33,    37,    34,   175,     0,     0,    38,    39,
       0,     0,    60,     0,    40,     0,     0,    61,    62,    60,
       0,     0,     0,     0,    61,    62,    35,    36,     0,    37,
       0,    63,     0,     0,    38,    39,     0,     0,    63,     0,
      40,    39,     0,    64,   117,    65,    66,    67,    39,     0,
      64,    60,    65,    66,    67,     0,    61,    62,     0,     0,
       0,     0,     0,   101,   102,   103,   104,   105,     0,     0,
      63,   109,   110,   111,   112,   113,   114,     0,     0,     0,
      39,     0,    64,     0,    65,    95,    67,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,     0,     0,     0,     0,     0,     0,   115,   116,   101,
     102,   103,   104,   105,   106,     0,   108,   109,   110,   111,
     112,   113,   114,   101,   102,   103,   104,   105,   106,   115,
     116,   109,   110,   111,   112,   113,   114,   101,   102,   103,
     104,   105,     0,   115,   116,   109,   110,   111,   112,   113,
     114,   101,   102,   103,   104,   105,     0,   115,   116,     0,
       0,   111,   112,   113,   114
};

static const yytype_int16 yycheck[] =
{
      26,    34,    26,     1,    15,    37,     3,    13,    34,    49,
      34,    15,    15,    43,    44,    19,    19,    43,    44,    43,
      44,     0,    28,    56,    30,    57,    58,    13,    60,    11,
      56,    42,    56,     5,    57,    58,     1,    60,    42,     4,
       1,    73,    12,    75,    76,    15,    11,     1,    14,    14,
      73,    49,    75,    76,    15,    16,    89,    49,    49,    20,
      21,    15,    13,    89,    49,    89,    20,    21,    20,    21,
      22,    23,    24,    34,     6,    15,     8,     9,    10,     8,
      34,    10,    11,    44,    11,    46,    11,    48,    49,    50,
      44,    15,    46,    11,    48,    49,    50,    15,    15,    15,
     133,   134,    20,    21,     8,     9,    10,   133,   134,   133,
     134,    61,    62,    63,    15,    49,    34,     7,     8,     9,
      10,    14,    11,   129,   156,    11,    44,   159,    46,    11,
      48,    49,    50,   156,    17,    49,   159,    22,    23,    24,
     173,    16,    12,    16,    11,    14,    12,   173,    12,   173,
      18,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     1,    16,    16,
      16,     1,    16,    16,     8,     9,    10,    11,    16,    13,
      14,    11,    17,    13,    14,    16,     1,    16,    16,    12,
      49,    11,    49,    11,    11,    49,    11,    37,    13,    14,
      16,    35,    36,    30,    38,    35,    36,    18,    38,    43,
      44,    89,     1,    43,    44,    49,   172,   161,    51,    49,
      35,    36,    11,    38,    13,   170,    -1,    -1,    43,    44,
      -1,    -1,    15,    -1,    49,    -1,    -1,    20,    21,    15,
      -1,    -1,    -1,    -1,    20,    21,    35,    36,    -1,    38,
      -1,    34,    -1,    -1,    43,    44,    -1,    -1,    34,    -1,
      49,    44,    -1,    46,    47,    48,    49,    50,    44,    -1,
      46,    15,    48,    49,    50,    -1,    20,    21,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      34,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      44,    -1,    46,    -1,    48,    49,    50,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      31,    32,    33,    20,    21,    22,    23,    24,    25,    40,
      41,    28,    29,    30,    31,    32,    33,    20,    21,    22,
      23,    24,    -1,    40,    41,    28,    29,    30,    31,    32,
      33,    20,    21,    22,    23,    24,    -1,    40,    41,    -1,
      -1,    30,    31,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    49,     0,    13,     1,     4,    11,    53,
      54,    55,    11,     5,    53,    14,    53,    53,     7,     8,
       9,    10,    57,    58,    49,    49,    13,    61,    15,    12,
      15,    56,     1,    11,    13,    35,    36,    38,    43,    44,
      49,    57,    62,    63,    65,    67,    70,    71,     6,    57,
      59,    49,    59,    11,    11,    14,    65,    15,    15,    11,
      15,    20,    21,    34,    46,    48,    49,    50,    67,    70,
      71,    72,    73,    15,    15,    15,    19,    49,    14,    62,
      62,    11,    11,    11,    17,    49,    16,    56,    16,    65,
      66,    72,    72,     1,    72,    49,    73,    73,    73,    42,
      11,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    40,    41,    47,    72,     1,
      49,     1,    16,    68,    72,    72,    12,    64,    18,    12,
      60,    66,    14,    16,    16,    16,    16,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    16,    16,    16,    17,    16,    16,    12,
      69,    49,    11,    49,    57,    65,    65,    11,    11,    72,
      72,    64,    49,    37,    18,    69,    60,    65,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    59,    59,    59,
      60,    60,    61,    62,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    68,    69,
      69,    70,    71,    71,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     2,     2,     2,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     5,     3,     4,     0,
       4,     0,     3,     2,     2,     0,     4,     3,     0,     4,
       2,     5,     7,     5,     3,     2,     2,     2,     2,     1,
       5,     5,     2,     2,     0,     3,     4,     4,     2,     0,
       3,     3,     7,     4,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     3,     1,     2,     1,     1,
       1,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: CLASS ID LBRACE ProgramAux RBRACE  */
#line 188 "jucompiler.y"
                                                             {root = criar_no("Program","");criar_filhos(root, criar_no("Id", (yyvsp[-3].string)));criar_filhos(root,(yyvsp[-1].ast));(yyval.ast) = root;}
#line 1585 "y.tab.c"
    break;

  case 3: /* ProgramAux: %empty  */
#line 192 "jucompiler.y"
                                                                                             {(yyval.ast)=NULL;}
#line 1591 "y.tab.c"
    break;

  case 4: /* ProgramAux: MethodDecl ProgramAux  */
#line 194 "jucompiler.y"
                                                             {(yyval.ast) = (yyvsp[-1].ast);criar_irmao((yyval.ast), (yyvsp[0].ast));}
#line 1597 "y.tab.c"
    break;

  case 5: /* ProgramAux: FieldDecl ProgramAux  */
#line 196 "jucompiler.y"
                                                             {(yyval.ast) = (yyvsp[-1].ast);criar_irmao((yyval.ast), (yyvsp[0].ast));}
#line 1603 "y.tab.c"
    break;

  case 6: /* ProgramAux: SEMICOLON ProgramAux  */
#line 198 "jucompiler.y"
                                                             {(yyval.ast) = (yyvsp[0].ast);}
#line 1609 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 201 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("MethodDecl","");criar_filhos((yyval.ast),(yyvsp[-1].ast));criar_filhos((yyval.ast),(yyvsp[0].ast));}
#line 1615 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC tipo ID FieldDeclAux SEMICOLON  */
#line 205 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("FieldDecl", "");criar_filhos((yyval.ast),(yyvsp[-3].ast));criar_filhos((yyval.ast), criar_no("Id", (yyvsp[-2].string)));mantertipo((yyvsp[-1].ast), (yyvsp[-3].ast)->tipo);criar_irmao((yyval.ast), (yyvsp[-1].ast));}
#line 1621 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 207 "jucompiler.y"
                                                             {(yyval.ast) = NULL;print_tree=0;}
#line 1627 "y.tab.c"
    break;

  case 10: /* FieldDeclAux: COMMA ID FieldDeclAux  */
#line 211 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("FieldDecl","");criar_filhos((yyval.ast), criar_no("Id", (yyvsp[-1].string)));criar_irmao((yyval.ast), (yyvsp[0].ast));}
#line 1633 "y.tab.c"
    break;

  case 11: /* FieldDeclAux: %empty  */
#line 213 "jucompiler.y"
                                                             {(yyval.ast) = NULL;}
#line 1639 "y.tab.c"
    break;

  case 12: /* tipo: INT  */
#line 215 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("Int", "");}
#line 1645 "y.tab.c"
    break;

  case 13: /* tipo: DOUBLE  */
#line 217 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("Double", "");}
#line 1651 "y.tab.c"
    break;

  case 14: /* tipo: BOOL  */
#line 219 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("Bool", "");}
#line 1657 "y.tab.c"
    break;

  case 15: /* MethodHeader: tipo ID LPAR FormalParams RPAR  */
#line 222 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("MethodHeader","");methodParams = criar_no("MethodParams","");criar_filhos((yyval.ast),(yyvsp[-4].ast));criar_filhos((yyval.ast),criar_no("Id", (yyvsp[-3].string)));criar_filhos((yyval.ast), methodParams);criar_filhos(methodParams,(yyvsp[-1].ast));}
#line 1663 "y.tab.c"
    break;

  case 16: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 224 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("MethodHeader","");methodParams = criar_no("MethodParams","");criar_filhos((yyval.ast),criar_no("Void", ""));criar_filhos((yyval.ast),criar_no("Id", (yyvsp[-3].string)));criar_filhos((yyval.ast), methodParams);criar_filhos(methodParams,(yyvsp[-1].ast));}
#line 1669 "y.tab.c"
    break;

  case 17: /* FormalParams: tipo ID FormalParamsAux  */
#line 227 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("ParamDecl","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_filhos((yyval.ast),criar_no("Id", (yyvsp[-1].string)));criar_irmao((yyval.ast),(yyvsp[0].ast));}
#line 1675 "y.tab.c"
    break;

  case 18: /* FormalParams: STRING LSQ RSQ ID  */
#line 229 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("ParamDecl","");criar_filhos((yyval.ast),criar_no("StringArray",""));criar_filhos((yyval.ast),criar_no("Id", (yyvsp[0].string)));}
#line 1681 "y.tab.c"
    break;

  case 19: /* FormalParams: %empty  */
#line 231 "jucompiler.y"
                                                             {(yyval.ast) = NULL;}
#line 1687 "y.tab.c"
    break;

  case 20: /* FormalParamsAux: COMMA tipo ID FormalParamsAux  */
#line 235 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("ParamDecl","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_filhos((yyval.ast),criar_no("Id",(yyvsp[-1].string)));criar_irmao((yyval.ast),(yyvsp[0].ast));}
#line 1693 "y.tab.c"
    break;

  case 21: /* FormalParamsAux: %empty  */
#line 237 "jucompiler.y"
                                                             {(yyval.ast) = NULL;}
#line 1699 "y.tab.c"
    break;

  case 22: /* MethodBody: LBRACE MethodBodyAux RBRACE  */
#line 241 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("MethodBody","");criar_filhos((yyval.ast),(yyvsp[-1].ast));}
#line 1705 "y.tab.c"
    break;

  case 23: /* MethodBodyAux: Statement MethodBodyAux  */
#line 245 "jucompiler.y"
                                                             {if((yyvsp[-1].ast) != NULL){(yyval.ast) = (yyvsp[-1].ast); criar_irmao((yyval.ast), (yyvsp[0].ast));}else{(yyval.ast) = (yyvsp[0].ast);}}
#line 1711 "y.tab.c"
    break;

  case 24: /* MethodBodyAux: VarDecl MethodBodyAux  */
#line 247 "jucompiler.y"
                                                             {(yyval.ast) = (yyvsp[-1].ast); criar_irmao((yyval.ast), (yyvsp[0].ast));}
#line 1717 "y.tab.c"
    break;

  case 25: /* MethodBodyAux: %empty  */
#line 249 "jucompiler.y"
                                                             {(yyval.ast) = NULL;}
#line 1723 "y.tab.c"
    break;

  case 26: /* VarDecl: tipo ID VarDeclAux SEMICOLON  */
#line 255 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("VarDecl", "");criar_filhos((yyval.ast), (yyvsp[-3].ast));criar_filhos((yyval.ast), criar_no("Id", (yyvsp[-2].string)));mantertipo((yyvsp[-1].ast), (yyvsp[-3].ast)->tipo);criar_irmao((yyval.ast), (yyvsp[-1].ast));}
#line 1729 "y.tab.c"
    break;

  case 27: /* VarDeclAux: COMMA ID VarDeclAux  */
#line 258 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("VarDecl","");criar_filhos((yyval.ast), criar_no("Id", (yyvsp[-1].string)));criar_irmao((yyval.ast), (yyvsp[0].ast));}
#line 1735 "y.tab.c"
    break;

  case 28: /* VarDeclAux: %empty  */
#line 259 "jucompiler.y"
                                                             {(yyval.ast) = NULL;}
#line 1741 "y.tab.c"
    break;

  case 29: /* Statement: LBRACE Statement StatementAux RBRACE  */
#line 262 "jucompiler.y"
                                                                 {
                                                                int count = 0;
                                                                if((yyvsp[-2].ast) != NULL){
                                                                    count++;
                                                                }

                                                                temp = (yyvsp[-1].ast);
                                                                while(temp != NULL){
                                                                    if(temp->tipo != NULL){

                                                                        if (strcmp(temp->tipo,"Semicolon")!=0){
                                                                            count++;
                                                                        }
                                                                        
                                                                    }

                                                                    temp = temp->irmao;
                                                                }
                                                                
                                                                if(count <= 1){
                                                                    (yyval.ast) = (yyvsp[-2].ast);
                                                                }

                                                                else {                                                                    
                                                                    (yyval.ast) = criar_no("Block","");
                                                                    criar_filhos((yyval.ast),(yyvsp[-2].ast));
                                                                    criar_filhos((yyval.ast),(yyvsp[-1].ast));
                                                                }
                                                            }
#line 1775 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE RBRACE  */
#line 292 "jucompiler.y"
                                                                                                     {(yyval.ast) = NULL;}
#line 1781 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement  */
#line 294 "jucompiler.y"
                                                                                     {
                                                                (yyval.ast) = criar_no("If","");

                                                                criar_filhos((yyval.ast),(yyvsp[-2].ast));
                                                                
                                                                if((yyvsp[0].ast) == NULL || strcmp((yyvsp[0].ast)->tipo,"Semicolon")==0){
                                                                    criar_filhos((yyval.ast),criar_no("Block",""));
                                                                    criar_filhos((yyval.ast),criar_no("Block",""));
                                                                }
                                                                
                                                                else{
                                                                    criar_filhos((yyval.ast),(yyvsp[0].ast));
                                                                    criar_filhos((yyval.ast),criar_no("Block",""));
                                                                }
                                                                
                                                            }
#line 1802 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 312 "jucompiler.y"
                                                                     {
                                                                (yyval.ast) = criar_no("If","");

                                                                criar_filhos((yyval.ast),(yyvsp[-4].ast));

                                                                if((yyvsp[-2].ast) == NULL || strcmp((yyvsp[-2].ast)->tipo,"Semicolon")==0){
                                                                    criar_filhos((yyval.ast),criar_no("Block",""));
                                                                }
                                                                else{
                                                                    criar_filhos((yyval.ast),(yyvsp[-2].ast));
                                                                }
                                                                if((yyvsp[0].ast) == NULL || strcmp((yyvsp[0].ast)->tipo,"Semicolon")==0){
                                                                    criar_filhos((yyval.ast),criar_no("Block",""));
                                                                }
                                                                else{
                                                                    criar_filhos((yyval.ast),(yyvsp[0].ast));
                                                                }
                                                                
                                                            }
#line 1826 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 334 "jucompiler.y"
                                                                                     {
                                                                (yyval.ast) = criar_no("While","");

                                                                criar_filhos((yyval.ast),(yyvsp[-2].ast));

                                                                if((yyvsp[0].ast) == NULL || strcmp((yyvsp[0].ast)->tipo,"Semicolon")==0){
                                                                    criar_filhos((yyval.ast),criar_no("Block",""));
                                                                }
                                                                else{
                                                                    criar_filhos((yyval.ast),(yyvsp[0].ast));
                                                                }
                                                            }
#line 1843 "y.tab.c"
    break;

  case 34: /* Statement: RETURN Expr SEMICOLON  */
#line 347 "jucompiler.y"
                                                                                     {(yyval.ast) = criar_no("Return","");criar_filhos((yyval.ast),(yyvsp[-1].ast));}
#line 1849 "y.tab.c"
    break;

  case 35: /* Statement: RETURN SEMICOLON  */
#line 349 "jucompiler.y"
                                                                                                     {(yyval.ast) = criar_no("Return", "");}
#line 1855 "y.tab.c"
    break;

  case 36: /* Statement: MethodInvocation SEMICOLON  */
#line 351 "jucompiler.y"
                                                                                     {(yyval.ast) = (yyvsp[-1].ast);}
#line 1861 "y.tab.c"
    break;

  case 37: /* Statement: Assignment SEMICOLON  */
#line 353 "jucompiler.y"
                                                                                             {(yyval.ast) = criar_no("Assign","");criar_filhos((yyval.ast),(yyvsp[-1].ast));}
#line 1867 "y.tab.c"
    break;

  case 38: /* Statement: ParseArgs SEMICOLON  */
#line 355 "jucompiler.y"
                                                                                             {(yyval.ast) = (yyvsp[-1].ast);}
#line 1873 "y.tab.c"
    break;

  case 39: /* Statement: SEMICOLON  */
#line 357 "jucompiler.y"
                                                                                                     {(yyval.ast) = criar_no("Semicolon","");}
#line 1879 "y.tab.c"
    break;

  case 40: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 359 "jucompiler.y"
                                                                                     {(yyval.ast) = criar_no("Print","");criar_filhos((yyval.ast),(yyvsp[-2].ast));}
#line 1885 "y.tab.c"
    break;

  case 41: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 361 "jucompiler.y"
                                                                             {(yyval.ast) = criar_no("Print","");criar_filhos((yyval.ast), criar_no("StrLit", (yyvsp[-2].string)));}
#line 1891 "y.tab.c"
    break;

  case 42: /* Statement: error SEMICOLON  */
#line 363 "jucompiler.y"
                                                                                                     {(yyval.ast) = NULL;print_tree = 0;}
#line 1897 "y.tab.c"
    break;

  case 43: /* StatementAux: Statement StatementAux  */
#line 366 "jucompiler.y"
                                                             {(yyval.ast) = (yyvsp[-1].ast);criar_irmao((yyval.ast),(yyvsp[0].ast));}
#line 1903 "y.tab.c"
    break;

  case 44: /* StatementAux: %empty  */
#line 367 "jucompiler.y"
                                                             {(yyval.ast) = NULL;}
#line 1909 "y.tab.c"
    break;

  case 45: /* MethodInvocation: ID LPAR RPAR  */
#line 371 "jucompiler.y"
                                                                                 {(yyval.ast) = criar_no("Call", "");criar_filhos((yyval.ast), criar_no("Id", (yyvsp[-2].string)));}
#line 1915 "y.tab.c"
    break;

  case 46: /* MethodInvocation: ID LPAR MethodInvocationAux RPAR  */
#line 373 "jucompiler.y"
                                                                                     {(yyval.ast) = criar_no("Call", "");criar_filhos((yyval.ast), criar_no("Id", (yyvsp[-3].string)));criar_filhos((yyval.ast),(yyvsp[-1].ast));}
#line 1921 "y.tab.c"
    break;

  case 47: /* MethodInvocation: ID LPAR error RPAR  */
#line 375 "jucompiler.y"
                                                                                             {(yyval.ast) = NULL;print_tree = 0;}
#line 1927 "y.tab.c"
    break;

  case 48: /* MethodInvocationAux: Expr MethodInvocationAux_2  */
#line 378 "jucompiler.y"
                                                                     {(yyval.ast) = (yyvsp[-1].ast);criar_irmao((yyval.ast),(yyvsp[0].ast));}
#line 1933 "y.tab.c"
    break;

  case 49: /* MethodInvocationAux_2: %empty  */
#line 381 "jucompiler.y"
                                                                                 {(yyval.ast) = NULL;}
#line 1939 "y.tab.c"
    break;

  case 50: /* MethodInvocationAux_2: COMMA Expr MethodInvocationAux_2  */
#line 382 "jucompiler.y"
                                                                                 {(yyval.ast) = (yyvsp[-1].ast);criar_irmao((yyval.ast),(yyvsp[0].ast));}
#line 1945 "y.tab.c"
    break;

  case 51: /* Assignment: ID ASSIGN Expr  */
#line 385 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("Id", (yyvsp[-2].string)); criar_irmao((yyval.ast),(yyvsp[0].ast));}
#line 1951 "y.tab.c"
    break;

  case 52: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 388 "jucompiler.y"
                                                             {(yyval.ast) = criar_no("ParseArgs","");aux = criar_no("Id", (yyvsp[-4].string)); criar_filhos((yyval.ast), aux);criar_irmao(aux, (yyvsp[-2].ast));}
#line 1957 "y.tab.c"
    break;

  case 53: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 390 "jucompiler.y"
                                                             {(yyval.ast) = NULL;print_tree=0;}
#line 1963 "y.tab.c"
    break;

  case 54: /* Expr: ExprAux  */
#line 393 "jucompiler.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 1969 "y.tab.c"
    break;

  case 55: /* Expr: Assignment  */
#line 395 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Assign","");criar_filhos((yyval.ast),(yyvsp[0].ast));}
#line 1975 "y.tab.c"
    break;

  case 56: /* ExprAux: ExprAux PLUS ExprAux  */
#line 398 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Add","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1981 "y.tab.c"
    break;

  case 57: /* ExprAux: ExprAux MINUS ExprAux  */
#line 400 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Sub","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1987 "y.tab.c"
    break;

  case 58: /* ExprAux: ExprAux STAR ExprAux  */
#line 402 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Mul","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1993 "y.tab.c"
    break;

  case 59: /* ExprAux: ExprAux DIV ExprAux  */
#line 404 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Div","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 1999 "y.tab.c"
    break;

  case 60: /* ExprAux: ExprAux MOD ExprAux  */
#line 406 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Mod","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2005 "y.tab.c"
    break;

  case 61: /* ExprAux: ExprAux OR ExprAux  */
#line 408 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Or","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2011 "y.tab.c"
    break;

  case 62: /* ExprAux: ExprAux XOR ExprAux  */
#line 410 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Xor","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2017 "y.tab.c"
    break;

  case 63: /* ExprAux: ExprAux AND ExprAux  */
#line 412 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("And","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2023 "y.tab.c"
    break;

  case 64: /* ExprAux: ExprAux LSHIFT ExprAux  */
#line 414 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Lshift","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2029 "y.tab.c"
    break;

  case 65: /* ExprAux: ExprAux RSHIFT ExprAux  */
#line 416 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Rshift","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2035 "y.tab.c"
    break;

  case 66: /* ExprAux: ExprAux EQ ExprAux  */
#line 418 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Eq","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2041 "y.tab.c"
    break;

  case 67: /* ExprAux: ExprAux NE ExprAux  */
#line 420 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Ne","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2047 "y.tab.c"
    break;

  case 68: /* ExprAux: ExprAux LT ExprAux  */
#line 422 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Lt","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2053 "y.tab.c"
    break;

  case 69: /* ExprAux: ExprAux GT ExprAux  */
#line 424 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Gt","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2059 "y.tab.c"
    break;

  case 70: /* ExprAux: ExprAux LE ExprAux  */
#line 426 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Le","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2065 "y.tab.c"
    break;

  case 71: /* ExprAux: ExprAux GE ExprAux  */
#line 428 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Ge","");criar_filhos((yyval.ast),(yyvsp[-2].ast));criar_irmao((yyvsp[-2].ast),(yyvsp[0].ast));}
#line 2071 "y.tab.c"
    break;

  case 72: /* ExprAux: MINUS ExprAux  */
#line 430 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Minus","");criar_filhos((yyval.ast),(yyvsp[0].ast));}
#line 2077 "y.tab.c"
    break;

  case 73: /* ExprAux: NOT ExprAux  */
#line 432 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Not","");criar_filhos((yyval.ast),(yyvsp[0].ast));}
#line 2083 "y.tab.c"
    break;

  case 74: /* ExprAux: PLUS ExprAux  */
#line 434 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Plus","");criar_filhos((yyval.ast),(yyvsp[0].ast));}
#line 2089 "y.tab.c"
    break;

  case 75: /* ExprAux: LPAR Expr RPAR  */
#line 436 "jucompiler.y"
                                                            {(yyval.ast) = (yyvsp[-1].ast);}
#line 2095 "y.tab.c"
    break;

  case 76: /* ExprAux: ID  */
#line 438 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Id",(yyvsp[0].string));}
#line 2101 "y.tab.c"
    break;

  case 77: /* ExprAux: ID DOTLENGTH  */
#line 440 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("Length","");criar_filhos((yyval.ast),criar_no("Id",(yyvsp[-1].string)));}
#line 2107 "y.tab.c"
    break;

  case 78: /* ExprAux: INTLIT  */
#line 442 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("DecLit",(yyvsp[0].string));}
#line 2113 "y.tab.c"
    break;

  case 79: /* ExprAux: REALLIT  */
#line 444 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("RealLit",(yyvsp[0].string));}
#line 2119 "y.tab.c"
    break;

  case 80: /* ExprAux: BOOLLIT  */
#line 446 "jucompiler.y"
                                                            {(yyval.ast) = criar_no("BoolLit",(yyvsp[0].string));}
#line 2125 "y.tab.c"
    break;

  case 81: /* ExprAux: MethodInvocation  */
#line 448 "jucompiler.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 2131 "y.tab.c"
    break;

  case 82: /* ExprAux: ParseArgs  */
#line 450 "jucompiler.y"
                                                            {(yyval.ast) = (yyvsp[0].ast);}
#line 2137 "y.tab.c"
    break;

  case 83: /* ExprAux: LPAR error RPAR  */
#line 452 "jucompiler.y"
                                                            {(yyval.ast) = NULL;print_tree=0;}
#line 2143 "y.tab.c"
    break;


#line 2147 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 456 "jucompiler.y"




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
