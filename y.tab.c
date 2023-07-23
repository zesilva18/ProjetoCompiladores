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
#line 3 "expr.y"

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


#line 107 "y.tab.c"

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
#line 39 "expr.y"

char* string;
struct ast_tree* ast_tree;

#line 265 "y.tab.c"

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
  YYSYMBOL_HelpProgam = 53,                /* HelpProgam  */
  YYSYMBOL_MethodDecl = 54,                /* MethodDecl  */
  YYSYMBOL_MethodHeader = 55,              /* MethodHeader  */
  YYSYMBOL_MethodBody = 56,                /* MethodBody  */
  YYSYMBOL_HelpMethod = 57,                /* HelpMethod  */
  YYSYMBOL_FieldDecl = 58,                 /* FieldDecl  */
  YYSYMBOL_HelpField = 59,                 /* HelpField  */
  YYSYMBOL_Type = 60,                      /* Type  */
  YYSYMBOL_FormalParams = 61,              /* FormalParams  */
  YYSYMBOL_FormalParamsAux = 62,           /* FormalParamsAux  */
  YYSYMBOL_VarDecl = 63,                   /* VarDecl  */
  YYSYMBOL_VarDeclAux = 64,                /* VarDeclAux  */
  YYSYMBOL_Statement = 65,                 /* Statement  */
  YYSYMBOL_StatementAux = 66,              /* StatementAux  */
  YYSYMBOL_MethodInvocation = 67,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocationaux = 68,       /* MethodInvocationaux  */
  YYSYMBOL_MethodInvocationaux_new = 69,   /* MethodInvocationaux_new  */
  YYSYMBOL_ParseArgs = 70,                 /* ParseArgs  */
  YYSYMBOL_Assignment = 71,                /* Assignment  */
  YYSYMBOL_Expr = 72,                      /* Expr  */
  YYSYMBOL_Expr_aux = 73                   /* Expr_aux  */
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
#define YYLAST   381

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

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
       0,    78,    78,    86,    87,    93,    96,   101,   109,   119,
     130,   136,   137,   138,   141,   149,   153,   161,   164,   165,
     166,   169,   174,   180,   183,   189,   193,   205,   211,   214,
     243,   259,   274,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   298,   299,   302,   303,   304,   307,   310,   311,
     314,   315,   318,   322,   323,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352
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
  "HelpProgam", "MethodDecl", "MethodHeader", "MethodBody", "HelpMethod",
  "FieldDecl", "HelpField", "Type", "FormalParams", "FormalParamsAux",
  "VarDecl", "VarDeclAux", "Statement", "StatementAux", "MethodInvocation",
  "MethodInvocationaux", "MethodInvocationaux_new", "ParseArgs",
  "Assignment", "Expr", "Expr_aux", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-44)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   -10,    20,    13,   -42,    46,    33,    44,    46,    38,
      46,    46,   -42,   113,   -42,   -42,   -42,   -42,     6,   -42,
     -42,   -42,    45,    23,    47,   156,   -42,    26,    61,    62,
     -42,    10,    75,    84,   163,    89,   100,    -5,   102,    56,
     156,   156,   107,   119,   120,    85,    61,   125,   138,   110,
     108,   -42,   137,   199,   199,   -42,    91,   217,   217,   217,
     -42,   -42,    49,   -42,   -42,   -42,   -42,   152,   270,   181,
       2,   112,   199,   -42,   159,   -42,   -42,   -42,   -42,   -42,
     164,   161,   -42,   150,   167,   -42,   137,   168,   169,   171,
     172,    -6,   248,   -42,   -42,   -42,   -42,   -42,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   173,   174,   177,   178,   182,   -42,
     187,   192,   -42,   157,   197,   -42,   -42,   175,   135,   -42,
     -42,   -42,    10,    10,   -42,   -42,   130,   130,   -42,   -42,
     -42,   320,   292,   306,   348,   348,    73,    73,    73,    73,
     334,   334,   205,   206,   -42,   199,   -42,   -42,   199,   -42,
     159,   -42,   -42,   185,   -42,   184,   -42,   -42,   200,   192,
     -42,   167,    10,   194,   -42,   -42,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    15,     0,     5,     2,     6,     4,     0,    18,
      19,    20,     0,     0,     0,     0,     7,    17,    23,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,    41,     0,     0,     0,    34,     0,     0,     0,     0,
      78,    77,    75,    79,    80,    81,    54,     0,    53,     0,
       0,     0,     0,    10,    28,    12,    11,    35,    37,    36,
      17,     0,    14,     0,    25,     9,     0,     0,     0,     0,
       0,    75,     0,    73,    71,    72,    76,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    49,    52,     0,     0,    16,     8,     0,     0,    21,
      42,    29,     0,     0,    82,    74,    55,    56,    57,    58,
      59,    61,    60,    62,    65,    66,    69,    70,    67,    68,
      63,    64,     0,     0,    51,     0,    46,    45,     0,    47,
      28,    26,    22,     0,    32,    30,    40,    39,     0,    49,
      27,    25,     0,     0,    48,    24,    31,    50
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,    90,   -42,   -42,   -42,    25,   -42,   142,    -9,
     180,    52,   -42,    76,   -30,   149,   -25,   -42,    70,   -23,
     -29,   -41,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    22,    26,    38,    11,    47,    39,
      50,   129,    40,   124,    41,    87,    64,   120,   159,    65,
      44,    67,    68
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,    52,    43,   116,    23,    66,    42,     1,    43,    71,
      71,    29,    88,    89,    72,    42,    42,    43,    43,    49,
       4,    30,    86,    31,    66,    66,     5,    42,   115,    43,
     121,   122,    92,    93,    94,    95,    96,    49,    45,     3,
      66,    46,    66,    66,    12,    32,    33,     6,    34,    13,
       7,   117,    15,    35,    36,    24,    86,     8,    25,    37,
      -3,    42,    28,    43,    71,    75,    76,    48,    72,    19,
      20,    21,    27,    51,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
      53,    96,    90,    98,    99,   100,   101,   102,    14,    54,
      16,    17,   164,   165,    69,    74,    56,    42,    42,    43,
      43,    57,    58,   118,   168,    70,    73,   169,    77,   163,
      18,    19,    20,    21,    85,    59,    66,    56,   119,    66,
      78,    79,    57,    58,    80,    36,    82,    60,    29,    61,
      91,    63,   176,    19,    20,    21,    59,    42,    30,    43,
      31,   -43,   100,   101,   102,    83,    36,    29,    60,    84,
      61,    62,    63,    97,    19,    20,    21,    30,   127,    31,
     -13,   123,    32,    33,    55,    34,    45,   126,    56,   128,
      35,    36,   131,    57,    58,   132,    37,   133,   134,   152,
     153,    32,    33,   154,    34,   155,    56,    59,   156,    35,
      36,    57,    58,   157,   158,    37,   160,    36,   161,    60,
     177,    61,    62,    63,    56,    59,   166,   167,   173,    57,
      58,   172,   125,   175,   162,    36,    81,    60,   114,    61,
      62,    63,    56,    59,   171,   130,   170,    57,    58,   174,
       0,     0,     0,    36,     0,    60,     0,    61,    62,    63,
       0,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    36,     0,    60,   135,    61,    91,    63,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,     0,     0,     0,     0,     0,   112,   113,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,     0,     0,     0,     0,     0,     0,
     112,   113,    98,    99,   100,   101,   102,   103,     0,   105,
     106,   107,   108,   109,   110,   111,    98,    99,   100,   101,
     102,   103,   112,   113,   106,   107,   108,   109,   110,   111,
      98,    99,   100,   101,   102,     0,   112,   113,   106,   107,
     108,   109,   110,   111,    98,    99,   100,   101,   102,     0,
     112,   113,   106,   107,   108,   109,   110,   111,    98,    99,
     100,   101,   102,     0,     0,     0,     0,     0,   108,   109,
     110,   111
};

static const yytype_int16 yycheck[] =
{
      25,    31,    25,     1,    13,    34,    31,     3,    31,    15,
      15,     1,    53,    54,    19,    40,    41,    40,    41,    28,
       0,    11,    52,    13,    53,    54,    13,    52,    69,    52,
      71,    72,    56,    57,    58,    59,    42,    46,    12,    49,
      69,    15,    71,    72,    11,    35,    36,     1,    38,     5,
       4,    49,    14,    43,    44,    49,    86,    11,    13,    49,
      14,    86,    15,    86,    15,    40,    41,     6,    19,     8,
       9,    10,    49,    11,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      15,    42,     1,    20,    21,    22,    23,    24,     8,    15,
      10,    11,   132,   133,    15,    49,    15,   132,   133,   132,
     133,    20,    21,     1,   155,    15,    14,   158,    11,   128,
       7,     8,     9,    10,    16,    34,   155,    15,    16,   158,
      11,    11,    20,    21,    49,    44,    11,    46,     1,    48,
      49,    50,   172,     8,     9,    10,    34,   172,    11,   172,
      13,    14,    22,    23,    24,    17,    44,     1,    46,    49,
      48,    49,    50,    11,     8,     9,    10,    11,    18,    13,
      14,    12,    35,    36,    11,    38,    12,    16,    15,    12,
      43,    44,    14,    20,    21,    16,    49,    16,    16,    16,
      16,    35,    36,    16,    38,    17,    15,    34,    16,    43,
      44,    20,    21,    16,    12,    49,    49,    44,    11,    46,
      16,    48,    49,    50,    15,    34,    11,    11,    18,    20,
      21,    37,    80,   171,    49,    44,    46,    46,    47,    48,
      49,    50,    15,    34,    49,    86,   160,    20,    21,   169,
      -1,    -1,    -1,    44,    -1,    46,    -1,    48,    49,    50,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    46,    16,    48,    49,    50,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      40,    41,    20,    21,    22,    23,    24,    25,    -1,    27,
      28,    29,    30,    31,    32,    33,    20,    21,    22,    23,
      24,    25,    40,    41,    28,    29,    30,    31,    32,    33,
      20,    21,    22,    23,    24,    -1,    40,    41,    28,    29,
      30,    31,    32,    33,    20,    21,    22,    23,    24,    -1,
      40,    41,    28,    29,    30,    31,    32,    33,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    49,     0,    13,     1,     4,    11,    53,
      54,    58,    11,     5,    53,    14,    53,    53,     7,     8,
       9,    10,    55,    60,    49,    13,    56,    49,    15,     1,
      11,    13,    35,    36,    38,    43,    44,    49,    57,    60,
      63,    65,    67,    70,    71,    12,    15,    59,     6,    60,
      61,    11,    65,    15,    15,    11,    15,    20,    21,    34,
      46,    48,    49,    50,    67,    70,    71,    72,    73,    15,
      15,    15,    19,    14,    49,    57,    57,    11,    11,    11,
      49,    61,    11,    17,    49,    16,    65,    66,    72,    72,
       1,    49,    73,    73,    73,    73,    42,    11,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    40,    41,    47,    72,     1,    49,     1,    16,
      68,    72,    72,    12,    64,    59,    16,    18,    12,    62,
      66,    14,    16,    16,    16,    16,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    16,    16,    16,    17,    16,    16,    12,    69,
      49,    11,    49,    60,    65,    65,    11,    11,    72,    72,
      64,    49,    37,    18,    69,    62,    65,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    57,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    62,    62,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    67,    68,    69,    69,
      70,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     0,     2,     2,     2,     4,     5,     5,
       3,     2,     2,     0,     6,     2,     3,     0,     1,     1,
       1,     3,     4,     0,     4,     0,     4,     3,     0,     4,
       5,     7,     5,     3,     2,     2,     2,     2,     1,     5,
       5,     2,     2,     0,     3,     4,     4,     2,     3,     0,
       7,     4,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     1,     2,     1,     1,     1,
       1,     1,     3
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
  case 2: /* Program: CLASS ID LBRACE HelpProgam RBRACE  */
#line 78 "expr.y"
                                                                     {
                                                                raiz = ast_node("Program","");       
                                                                add_childs(raiz, ast_node("Id", (yyvsp[-3].string)));
                                                                add_childs(raiz,(yyvsp[-1].ast_tree));
                                                                (yyval.ast_tree) = raiz;
                                                            }
#line 1478 "y.tab.c"
    break;

  case 3: /* HelpProgam: %empty  */
#line 86 "expr.y"
                                                             { (yyval.ast_tree) = NULL;}
#line 1484 "y.tab.c"
    break;

  case 4: /* HelpProgam: FieldDecl HelpProgam  */
#line 87 "expr.y"
                                                             {                                                           
                                                                (yyval.ast_tree) = (yyvsp[-1].ast_tree);
                                                                
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                
                                                            }
#line 1495 "y.tab.c"
    break;

  case 5: /* HelpProgam: SEMICOLON HelpProgam  */
#line 93 "expr.y"
                                                             {
                                                                (yyval.ast_tree) = (yyvsp[0].ast_tree);
                                                            }
#line 1503 "y.tab.c"
    break;

  case 6: /* HelpProgam: MethodDecl HelpProgam  */
#line 96 "expr.y"
                                                             {
                                                                (yyval.ast_tree) = (yyvsp[-1].ast_tree);
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                            }
#line 1512 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 101 "expr.y"
                                                                                    {
                                                                                    (yyval.ast_tree) = ast_node("MethodDecl","");
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                    }
#line 1522 "y.tab.c"
    break;

  case 8: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 109 "expr.y"
                                                               {
                                                                (yyval.ast_tree) = ast_node("MethodHeader","");
                                                                aux = ast_node("MethodParams","");
                                                                add_childs((yyval.ast_tree),(yyvsp[-4].ast_tree)); 
                                                                add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-3].string)));
                                                                add_childs((yyval.ast_tree), aux);
                                                                add_childs(aux,(yyvsp[-1].ast_tree));
                                                               }
#line 1535 "y.tab.c"
    break;

  case 9: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 119 "expr.y"
                                                               {
                                                                (yyval.ast_tree) = ast_node("MethodHeader","");
                                                                aux = ast_node("MethodParams","");
                                                                add_childs((yyval.ast_tree),ast_node("Void", "")); 
                                                                add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-3].string)));
                                                                add_childs((yyval.ast_tree), aux);
                                                                add_childs(aux,(yyvsp[-1].ast_tree));
                                                               }
#line 1548 "y.tab.c"
    break;

  case 10: /* MethodBody: LBRACE HelpMethod RBRACE  */
#line 130 "expr.y"
                                                                                 {(yyval.ast_tree) = ast_node("MethodBody",""); 
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                                    }
#line 1556 "y.tab.c"
    break;

  case 11: /* HelpMethod: Statement HelpMethod  */
#line 136 "expr.y"
                                                                              {if((yyvsp[-1].ast_tree) != NULL) {(yyval.ast_tree) = (yyvsp[-1].ast_tree); add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));} else{(yyval.ast_tree) = (yyvsp[0].ast_tree);}}
#line 1562 "y.tab.c"
    break;

  case 12: /* HelpMethod: VarDecl HelpMethod  */
#line 137 "expr.y"
                                                                                 {(yyval.ast_tree) = (yyvsp[-1].ast_tree); add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 1568 "y.tab.c"
    break;

  case 13: /* HelpMethod: %empty  */
#line 138 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;}
#line 1574 "y.tab.c"
    break;

  case 14: /* FieldDecl: PUBLIC STATIC Type ID HelpField SEMICOLON  */
#line 141 "expr.y"
                                                         {
                                                                (yyval.ast_tree) = ast_node("FieldDecl", "");
                                                                add_childs((yyval.ast_tree),(yyvsp[-3].ast_tree));
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].string)));
                                                                mantertipo((yyvsp[-1].ast_tree), (yyvsp[-3].ast_tree)->type);
                                                                add_brother((yyval.ast_tree), (yyvsp[-1].ast_tree));
                                                                
                                                            }
#line 1587 "y.tab.c"
    break;

  case 15: /* FieldDecl: error SEMICOLON  */
#line 149 "expr.y"
                                                             {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 1593 "y.tab.c"
    break;

  case 16: /* HelpField: COMMA ID HelpField  */
#line 153 "expr.y"
                                                      {
                                                                (yyval.ast_tree) = ast_node("FieldDecl","");                                                                
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-1].string)));
                                                                
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                
                                                            }
#line 1605 "y.tab.c"
    break;

  case 17: /* HelpField: %empty  */
#line 161 "expr.y"
                                                           {(yyval.ast_tree) = NULL;}
#line 1611 "y.tab.c"
    break;

  case 18: /* Type: INT  */
#line 164 "expr.y"
                                                            {(yyval.ast_tree) = ast_node("Int", "");}
#line 1617 "y.tab.c"
    break;

  case 19: /* Type: DOUBLE  */
#line 165 "expr.y"
                                                            {(yyval.ast_tree) = ast_node("Double", "");}
#line 1623 "y.tab.c"
    break;

  case 20: /* Type: BOOL  */
#line 166 "expr.y"
                                                            {(yyval.ast_tree) = ast_node("Bool", "");}
#line 1629 "y.tab.c"
    break;

  case 21: /* FormalParams: Type ID FormalParamsAux  */
#line 169 "expr.y"
                                                                           {(yyval.ast_tree) = ast_node("ParamDecl","");
                                                                            add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                            add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-1].string)));
                                                                            add_brother((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 1638 "y.tab.c"
    break;

  case 22: /* FormalParams: STRING LSQ RSQ ID  */
#line 174 "expr.y"
                                                                           {
                                                                           (yyval.ast_tree) = ast_node("ParamDecl","");
                                                                           add_childs((yyval.ast_tree),ast_node("StringArray",""));
                                                                           add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[0].string)));
                                                                           }
#line 1648 "y.tab.c"
    break;

  case 23: /* FormalParams: %empty  */
#line 180 "expr.y"
                                                             {(yyval.ast_tree) = NULL;}
#line 1654 "y.tab.c"
    break;

  case 24: /* FormalParamsAux: COMMA Type ID FormalParamsAux  */
#line 183 "expr.y"
                                                                          { (yyval.ast_tree) = ast_node("ParamDecl","");
                                                                            add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                            add_childs((yyval.ast_tree),ast_node("Id",(yyvsp[-1].string)));
                                                                            add_brother((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                            }
#line 1664 "y.tab.c"
    break;

  case 25: /* FormalParamsAux: %empty  */
#line 189 "expr.y"
                                                                          {(yyval.ast_tree) = NULL;}
#line 1670 "y.tab.c"
    break;

  case 26: /* VarDecl: Type ID VarDeclAux SEMICOLON  */
#line 193 "expr.y"
                                                                        {
    
                                                                (yyval.ast_tree) = ast_node("VarDecl", "");
                                                                add_childs((yyval.ast_tree), (yyvsp[-3].ast_tree));
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].string)));
                                                                mantertipo((yyvsp[-1].ast_tree), (yyvsp[-3].ast_tree)->type);
                                                                
                                                                add_brother((yyval.ast_tree), (yyvsp[-1].ast_tree));
                                                                
                                                                }
#line 1685 "y.tab.c"
    break;

  case 27: /* VarDeclAux: COMMA ID VarDeclAux  */
#line 205 "expr.y"
                                                           { 
                                                                (yyval.ast_tree) = ast_node("VarDecl","");
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-1].string)));                                                              
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                
                                                            }
#line 1696 "y.tab.c"
    break;

  case 28: /* VarDeclAux: %empty  */
#line 211 "expr.y"
                                                            {(yyval.ast_tree) = NULL;}
#line 1702 "y.tab.c"
    break;

  case 29: /* Statement: LBRACE Statement StatementAux RBRACE  */
#line 214 "expr.y"
                                                                                 {

                                                                                int count = 0;
                                                                                if((yyvsp[-2].ast_tree) != NULL){
                                                                                    count ++;
                                                                                }

                                                                                temp = (yyvsp[-1].ast_tree);

                                                                                while( temp != NULL){
                                                                                    if(temp->type != NULL && strcmp(temp->type, "Semicolon") != 0){
                                                                                        count ++;
                                                                                    }

                                                                                    temp = temp->brother;
                                                                                }

                                                                                if(count > 1){
                                                                                         (yyval.ast_tree) = ast_node("Block","");
                                                                                        add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                                        add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                                }else {
                                                                                    (yyval.ast_tree) = (yyvsp[-2].ast_tree);
                                                                                }   

                                                                                }
#line 1733 "y.tab.c"
    break;

  case 30: /* Statement: IF LPAR Expr RPAR Statement  */
#line 243 "expr.y"
                                                                            {
                                                                               (yyval.ast_tree) = ast_node("If","");
                                                                               

                                                                               add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));


                                                                               if((yyvsp[0].ast_tree) == NULL || strcmp((yyvsp[0].ast_tree)->type, "Semicolon") == 0){
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));
                                                                               }else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));
                                                                               }
                                                                            }
#line 1753 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 259 "expr.y"
                                                                            {
                                                                                (yyval.ast_tree) = ast_node("If","");
                                                                                add_childs((yyval.ast_tree),(yyvsp[-4].ast_tree));
                                                                                if((yyvsp[-2].ast_tree) == NULL || strcmp((yyvsp[-2].ast_tree)->type, "Semicolon") == 0){  //caso o primeiro satatement seja null
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));}
                                                                                else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                                    }
                                                                                if((yyvsp[0].ast_tree) == NULL || strcmp((yyvsp[0].ast_tree)->type, "Semicolon") == 0){ //caso o segundo statement seja null
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));}
                                                                                else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                    }

                                                                            }
#line 1773 "y.tab.c"
    break;

  case 32: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 274 "expr.y"
                                                                            {
                                                                             (yyval.ast_tree) = ast_node("While","");
                                                                             add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));

                                                                             if((yyvsp[0].ast_tree) == NULL || strcmp((yyvsp[0].ast_tree)->type, "Semicolon") == 0){ //n tiver nd no statement
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));
                                                                                }
                                                                                else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                }
                                                                             
                                                                            }
#line 1790 "y.tab.c"
    break;

  case 33: /* Statement: RETURN Expr SEMICOLON  */
#line 287 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Return","");add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));}
#line 1796 "y.tab.c"
    break;

  case 34: /* Statement: RETURN SEMICOLON  */
#line 288 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Return", "");}
#line 1802 "y.tab.c"
    break;

  case 35: /* Statement: MethodInvocation SEMICOLON  */
#line 289 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 1808 "y.tab.c"
    break;

  case 36: /* Statement: Assignment SEMICOLON  */
#line 290 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Assign", "");add_childs((yyval.ast_tree), (yyvsp[-1].ast_tree));}
#line 1814 "y.tab.c"
    break;

  case 37: /* Statement: ParseArgs SEMICOLON  */
#line 291 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 1820 "y.tab.c"
    break;

  case 38: /* Statement: SEMICOLON  */
#line 292 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Semicolon", "");}
#line 1826 "y.tab.c"
    break;

  case 39: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 293 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Print","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));}
#line 1832 "y.tab.c"
    break;

  case 40: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 294 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Print","");add_childs((yyval.ast_tree), ast_node("StrLit", (yyvsp[-2].string)));}
#line 1838 "y.tab.c"
    break;

  case 41: /* Statement: error SEMICOLON  */
#line 295 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 1844 "y.tab.c"
    break;

  case 42: /* StatementAux: Statement StatementAux  */
#line 298 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree); add_brother((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 1850 "y.tab.c"
    break;

  case 43: /* StatementAux: %empty  */
#line 299 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;}
#line 1856 "y.tab.c"
    break;

  case 44: /* MethodInvocation: ID LPAR RPAR  */
#line 302 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Call", "");add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].string)));}
#line 1862 "y.tab.c"
    break;

  case 45: /* MethodInvocation: ID LPAR MethodInvocationaux RPAR  */
#line 303 "expr.y"
                                                                               {(yyval.ast_tree) = ast_node("Call", "");add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-3].string)));add_childs((yyval.ast_tree), (yyvsp[-1].ast_tree));}
#line 1868 "y.tab.c"
    break;

  case 46: /* MethodInvocation: ID LPAR error RPAR  */
#line 304 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 1874 "y.tab.c"
    break;

  case 47: /* MethodInvocationaux: Expr MethodInvocationaux_new  */
#line 307 "expr.y"
                                                                                  {(yyval.ast_tree) = (yyvsp[-1].ast_tree);add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 1880 "y.tab.c"
    break;

  case 48: /* MethodInvocationaux_new: COMMA Expr MethodInvocationaux_new  */
#line 310 "expr.y"
                                                                                   {(yyval.ast_tree) = (yyvsp[-1].ast_tree);add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 1886 "y.tab.c"
    break;

  case 49: /* MethodInvocationaux_new: %empty  */
#line 311 "expr.y"
                                                                                {(yyval.ast_tree) = NULL;}
#line 1892 "y.tab.c"
    break;

  case 50: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 314 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("ParseArgs","");add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-4].string)));add_childs((yyval.ast_tree), (yyvsp[-2].ast_tree));}
#line 1898 "y.tab.c"
    break;

  case 51: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 315 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 1904 "y.tab.c"
    break;

  case 52: /* Assignment: ID ASSIGN Expr  */
#line 318 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Id", "");add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 1910 "y.tab.c"
    break;

  case 53: /* Expr: Expr_aux  */
#line 322 "expr.y"
                                                                                     {(yyval.ast_tree) = (yyvsp[0].ast_tree);}
#line 1916 "y.tab.c"
    break;

  case 54: /* Expr: Assignment  */
#line 323 "expr.y"
                                                                                     {(yyval.ast_tree) = ast_node("Assign", ""); add_childs((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 1922 "y.tab.c"
    break;

  case 55: /* Expr_aux: Expr_aux PLUS Expr_aux  */
#line 325 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Add","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1928 "y.tab.c"
    break;

  case 56: /* Expr_aux: Expr_aux MINUS Expr_aux  */
#line 326 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Sub","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1934 "y.tab.c"
    break;

  case 57: /* Expr_aux: Expr_aux STAR Expr_aux  */
#line 327 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Mul","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1940 "y.tab.c"
    break;

  case 58: /* Expr_aux: Expr_aux DIV Expr_aux  */
#line 328 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Div","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1946 "y.tab.c"
    break;

  case 59: /* Expr_aux: Expr_aux MOD Expr_aux  */
#line 329 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Mod","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1952 "y.tab.c"
    break;

  case 60: /* Expr_aux: Expr_aux OR Expr_aux  */
#line 330 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Or","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1958 "y.tab.c"
    break;

  case 61: /* Expr_aux: Expr_aux XOR Expr_aux  */
#line 331 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Xor","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1964 "y.tab.c"
    break;

  case 62: /* Expr_aux: Expr_aux AND Expr_aux  */
#line 332 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("And","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1970 "y.tab.c"
    break;

  case 63: /* Expr_aux: Expr_aux LSHIFT Expr_aux  */
#line 333 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Lshift","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1976 "y.tab.c"
    break;

  case 64: /* Expr_aux: Expr_aux RSHIFT Expr_aux  */
#line 334 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Rshift","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1982 "y.tab.c"
    break;

  case 65: /* Expr_aux: Expr_aux EQ Expr_aux  */
#line 335 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Eq","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1988 "y.tab.c"
    break;

  case 66: /* Expr_aux: Expr_aux NE Expr_aux  */
#line 336 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Ne","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1994 "y.tab.c"
    break;

  case 67: /* Expr_aux: Expr_aux LT Expr_aux  */
#line 337 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Lt","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2000 "y.tab.c"
    break;

  case 68: /* Expr_aux: Expr_aux GT Expr_aux  */
#line 338 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Gt","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2006 "y.tab.c"
    break;

  case 69: /* Expr_aux: Expr_aux LE Expr_aux  */
#line 339 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Le","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2012 "y.tab.c"
    break;

  case 70: /* Expr_aux: Expr_aux GE Expr_aux  */
#line 340 "expr.y"
                                                                                            {(yyval.ast_tree) = ast_node("Ge","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2018 "y.tab.c"
    break;

  case 71: /* Expr_aux: MINUS Expr_aux  */
#line 341 "expr.y"
                                                                                        {(yyval.ast_tree) = ast_node("Minus","");add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2024 "y.tab.c"
    break;

  case 72: /* Expr_aux: NOT Expr_aux  */
#line 342 "expr.y"
                                                                             {(yyval.ast_tree) = ast_node("Not","");add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2030 "y.tab.c"
    break;

  case 73: /* Expr_aux: PLUS Expr_aux  */
#line 343 "expr.y"
                                                                                        {(yyval.ast_tree) = ast_node("Plus","");add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2036 "y.tab.c"
    break;

  case 74: /* Expr_aux: LPAR Expr_aux RPAR  */
#line 344 "expr.y"
                                                                                        {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 2042 "y.tab.c"
    break;

  case 75: /* Expr_aux: ID  */
#line 345 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Id",(yyvsp[0].string));}
#line 2048 "y.tab.c"
    break;

  case 76: /* Expr_aux: ID DOTLENGTH  */
#line 346 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Length",""); add_childs((yyval.ast_tree),ast_node("Id",(yyvsp[-1].string)));}
#line 2054 "y.tab.c"
    break;

  case 77: /* Expr_aux: INTLIT  */
#line 347 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("DecLit",(yyvsp[0].string));}
#line 2060 "y.tab.c"
    break;

  case 78: /* Expr_aux: REALLIT  */
#line 348 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("RealLit",(yyvsp[0].string));}
#line 2066 "y.tab.c"
    break;

  case 79: /* Expr_aux: BOOLLIT  */
#line 349 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("BoolLit",(yyvsp[0].string));}
#line 2072 "y.tab.c"
    break;

  case 80: /* Expr_aux: MethodInvocation  */
#line 350 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[0].ast_tree);}
#line 2078 "y.tab.c"
    break;

  case 81: /* Expr_aux: ParseArgs  */
#line 351 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[0].ast_tree);}
#line 2084 "y.tab.c"
    break;

  case 82: /* Expr_aux: LPAR error RPAR  */
#line 352 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 2090 "y.tab.c"
    break;


#line 2094 "y.tab.c"

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

#line 355 "expr.y"




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
