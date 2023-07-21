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
  YYSYMBOL_ParseArgs = 69,                 /* ParseArgs  */
  YYSYMBOL_Assignment = 70,                /* Assignment  */
  YYSYMBOL_Expr = 71                       /* Expr  */
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
#define YYLAST   490

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

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
       0,    77,    77,    83,    86,    90,    96,    99,   102,   110,
     119,   127,   136,   145,   151,   152,   153,   156,   164,   168,
     176,   179,   180,   181,   184,   189,   197,   203,   207,   219,
     225,   228,   241,   257,   272,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   293,   294,   297,   298,   299,   302,
     303,   306,   307,   310,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341
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
  "MethodInvocationaux", "ParseArgs", "Assignment", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-46)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,   -20,    33,    14,   -32,    59,    24,    43,   162,    39,
     162,   162,   -32,     4,    24,   -32,   -32,   -32,   -32,    13,
     -32,   -32,   -32,    52,    26,    41,   118,   -32,    32,   171,
      60,   -32,   157,    62,    87,   163,   101,   103,   -12,    90,
      71,   118,   118,   113,   114,   119,    84,   222,   123,   121,
     -32,    94,   128,   -32,   157,   141,   206,   206,   -32,   102,
     206,   206,   206,   -32,   -32,     7,   -32,   -32,   -32,   -32,
     237,   170,     8,    30,   206,   -32,   145,   -32,   -32,   -32,
     -32,   -32,   147,   -32,   144,   -32,   146,   153,   -32,   -32,
     -32,   281,   303,   156,   325,   -32,   -32,   -32,   -32,   -32,
     206,   206,   206,   206,   206,   206,   206,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   159,   347,   166,   152,
     172,   -32,   259,   393,   137,   178,   -32,   -32,   149,    89,
     -32,    23,    23,   -32,   -32,   200,   200,   -32,   -32,   -32,
     443,   415,   429,   457,   457,    91,    91,    91,    91,   213,
     213,   183,   185,   -32,   206,   -32,   206,   186,   145,   -32,
     -32,   150,   -32,   168,   -32,   -32,   371,   259,   -32,   -32,
     153,    23,   187,   -32,   -32,   -32,   -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     3,     0,     0,     0,
       0,     0,    18,     0,     0,     6,     2,     4,     5,     0,
      21,    22,    23,     0,     0,     0,     0,     8,    20,     0,
       0,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      12,     0,     0,    43,     0,     0,     0,     0,    35,     0,
       0,     0,     0,    77,    76,    74,    78,    79,    81,    80,
       0,     0,     0,     0,     0,    13,    30,    15,    14,    39,
      41,    40,    20,    10,     0,    17,     0,    27,    11,    44,
      31,     0,     0,     0,     0,    72,    70,    71,    75,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    47,    50,    53,     0,     0,    19,     9,     0,     0,
      24,     0,     0,    82,    73,    54,    55,    56,    57,    58,
      60,    59,    61,    64,    65,    68,    69,    66,    67,    62,
      63,     0,     0,    52,     0,    48,     0,     0,    30,    28,
      25,     0,    34,    32,    38,    37,     0,    50,    46,    29,
      27,     0,     0,    49,    26,    33,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -32,   -32,   131,   -32,   -32,   -32,    27,   -32,   126,    -8,
     182,    40,   -32,    57,   -31,   193,   -26,    58,   -24,   -22,
     -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    23,    27,    39,    11,    48,    40,
      52,   130,    41,   125,    42,    55,    67,   157,    68,    69,
      70
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    54,    44,    73,    45,    24,    43,    74,    44,   118,
      45,    19,    20,    21,    22,    43,    43,    44,    44,    45,
      45,    51,    73,    54,    30,     1,    74,     5,    43,     3,
      44,   120,    45,     4,    31,    12,    32,    91,    92,    51,
      94,    95,    96,    97,    46,    59,   121,    47,    13,    98,
      60,    61,   117,    16,   122,   123,    29,   119,    33,    34,
       6,    35,    25,     7,    62,    26,    36,    37,    77,    78,
       8,    53,    38,    -7,    37,    28,    63,    56,    64,    65,
      66,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,    20,    21,    22,
     162,   163,    57,    93,    75,    43,    43,    44,    44,    45,
      45,   100,   101,   102,   103,   104,    71,    59,    72,    30,
      76,   161,    60,    61,    79,    80,    20,    21,    22,    31,
      81,    32,   -16,    82,    85,   166,    62,   167,    86,    15,
     175,    17,    18,    87,    88,    43,    37,    44,    63,    45,
      64,    65,    66,    33,    34,    90,    35,   124,    30,    46,
     127,    36,    37,    14,   128,   129,     7,    38,    31,   154,
      32,   -45,   133,     8,    58,   151,    -7,    49,    59,    20,
      21,    22,   153,    60,    61,    59,   158,    50,   155,   159,
      60,    61,    33,    34,   164,    35,   165,    62,   160,   170,
      36,    37,   168,   176,    62,   171,    38,    37,   126,    63,
     174,    64,    65,    66,    37,   169,    63,   116,    64,    65,
      66,    59,   102,   103,   104,   173,    60,    61,    49,    84,
      20,    21,    22,   100,   101,   102,   103,   104,    83,     0,
      62,   108,   109,   110,   111,   112,   113,    89,    99,     0,
      37,     0,    63,     0,    64,    65,    66,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   156,     0,     0,     0,     0,     0,   114,   115,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,     0,     0,     0,     0,   131,     0,   114,
     115,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,   132,
       0,   114,   115,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,     0,     0,     0,
       0,   134,     0,   114,   115,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,     0,
       0,     0,     0,   152,     0,   114,   115,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,     0,     0,     0,     0,     0,     0,   114,   115,   172,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,     0,
       0,   114,   115,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,     0,     0,     0,
       0,     0,     0,   114,   115,   100,   101,   102,   103,   104,
     105,     0,   107,   108,   109,   110,   111,   112,   113,   100,
     101,   102,   103,   104,   105,   114,   115,   108,   109,   110,
     111,   112,   113,   100,   101,   102,   103,   104,     0,   114,
     115,   108,   109,   110,   111,   112,   113,   100,   101,   102,
     103,   104,     0,   114,   115,     0,     0,   110,   111,   112,
     113
};

static const yytype_int16 yycheck[] =
{
      26,    32,    26,    15,    26,    13,    32,    19,    32,     1,
      32,     7,     8,     9,    10,    41,    42,    41,    42,    41,
      42,    29,    15,    54,     1,     3,    19,    13,    54,    49,
      54,     1,    54,     0,    11,    11,    13,    56,    57,    47,
      59,    60,    61,    62,    12,    15,    16,    15,     5,    42,
      20,    21,    71,    14,    73,    74,    15,    49,    35,    36,
       1,    38,    49,     4,    34,    13,    43,    44,    41,    42,
      11,    11,    49,    14,    44,    49,    46,    15,    48,    49,
      50,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,     8,     9,    10,
     131,   132,    15,     1,    14,   131,   132,   131,   132,   131,
     132,    20,    21,    22,    23,    24,    15,    15,    15,     1,
      49,   129,    20,    21,    11,    11,     8,     9,    10,    11,
      11,    13,    14,    49,    11,   154,    34,   156,    17,     8,
     171,    10,    11,    49,    16,   171,    44,   171,    46,   171,
      48,    49,    50,    35,    36,    14,    38,    12,     1,    12,
      16,    43,    44,     1,    18,    12,     4,    49,    11,    17,
      13,    14,    16,    11,    11,    16,    14,     6,    15,     8,
       9,    10,    16,    20,    21,    15,    49,    16,    16,    11,
      20,    21,    35,    36,    11,    38,    11,    34,    49,    49,
      43,    44,    16,    16,    34,    37,    49,    44,    82,    46,
     170,    48,    49,    50,    44,   158,    46,    47,    48,    49,
      50,    15,    22,    23,    24,   167,    20,    21,     6,    47,
       8,     9,    10,    20,    21,    22,    23,    24,    16,    -1,
      34,    28,    29,    30,    31,    32,    33,    54,    11,    -1,
      44,    -1,    46,    -1,    48,    49,    50,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    12,    -1,    -1,    -1,    -1,    -1,    40,    41,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    16,    -1,    40,
      41,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    16,
      -1,    40,    41,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    16,    -1,    40,    41,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    16,    -1,    40,    41,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    18,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    20,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    20,
      21,    22,    23,    24,    25,    40,    41,    28,    29,    30,
      31,    32,    33,    20,    21,    22,    23,    24,    -1,    40,
      41,    28,    29,    30,    31,    32,    33,    20,    21,    22,
      23,    24,    -1,    40,    41,    -1,    -1,    30,    31,    32,
      33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    52,    49,     0,    13,     1,     4,    11,    53,
      54,    58,    11,     5,     1,    53,    14,    53,    53,     7,
       8,     9,    10,    55,    60,    49,    13,    56,    49,    15,
       1,    11,    13,    35,    36,    38,    43,    44,    49,    57,
      60,    63,    65,    67,    69,    70,    12,    15,    59,     6,
      16,    60,    61,    11,    65,    66,    15,    15,    11,    15,
      20,    21,    34,    46,    48,    49,    50,    67,    69,    70,
      71,    15,    15,    15,    19,    14,    49,    57,    57,    11,
      11,    11,    49,    16,    61,    11,    17,    49,    16,    66,
      14,    71,    71,     1,    71,    71,    71,    71,    42,    11,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    40,    41,    47,    71,     1,    49,
       1,    16,    71,    71,    12,    64,    59,    16,    18,    12,
      62,    16,    16,    16,    16,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    16,    16,    16,    17,    16,    12,    68,    49,    11,
      49,    60,    65,    65,    11,    11,    71,    71,    16,    64,
      49,    37,    18,    68,    62,    65,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    53,    54,    55,
      55,    55,    55,    56,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    60,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    66,    66,    67,    67,    67,    68,
      68,    69,    69,    70,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     2,     2,     2,     0,     4,     5,
       4,     5,     4,     3,     2,     2,     0,     6,     2,     3,
       0,     1,     1,     1,     3,     4,     4,     0,     4,     3,
       0,     3,     5,     7,     5,     2,     3,     5,     5,     2,
       2,     2,     1,     2,     2,     0,     5,     3,     4,     3,
       0,     7,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     3,     1,     2,     1,     1,     1,     1,
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
#line 77 "expr.y"
                                                                     {
                                                                (yyval.ast_tree) = ast_node("Program","");       
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-3].string)));
                                                                add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                raiz = (yyval.ast_tree);
                                                            }
#line 1497 "y.tab.c"
    break;

  case 3: /* Program: CLASS ID LBRACE error  */
#line 83 "expr.y"
                                                           {(yyval.ast_tree) = NULL;flag_erro=1;}
#line 1503 "y.tab.c"
    break;

  case 4: /* HelpProgam: MethodDecl HelpProgam  */
#line 86 "expr.y"
                                                             {
                                                                (yyval.ast_tree) = (yyvsp[-1].ast_tree);
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                            }
#line 1512 "y.tab.c"
    break;

  case 5: /* HelpProgam: FieldDecl HelpProgam  */
#line 90 "expr.y"
                                                             {                                                           
                                                                (yyval.ast_tree) = (yyvsp[-1].ast_tree);
                                                                
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                
                                                            }
#line 1523 "y.tab.c"
    break;

  case 6: /* HelpProgam: SEMICOLON HelpProgam  */
#line 96 "expr.y"
                                                             {
                                                                (yyval.ast_tree) = (yyvsp[0].ast_tree);
                                                            }
#line 1531 "y.tab.c"
    break;

  case 7: /* HelpProgam: %empty  */
#line 99 "expr.y"
                                                              {(yyval.ast_tree) = NULL;}
#line 1537 "y.tab.c"
    break;

  case 8: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 102 "expr.y"
                                                                                    {
                                                                                    (yyval.ast_tree) = ast_node("MethodDecl","");
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                    }
#line 1547 "y.tab.c"
    break;

  case 9: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 110 "expr.y"
                                                               {
                                                                (yyval.ast_tree) = ast_node("MethodHeader","");
                                                                aux = ast_node("MethodParams","");
                                                                add_childs((yyval.ast_tree),(yyvsp[-4].ast_tree)); 
                                                                add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-3].string)));
                                                                add_childs((yyval.ast_tree), aux);
                                                                add_childs(aux,(yyvsp[-1].ast_tree));
                                                               }
#line 1560 "y.tab.c"
    break;

  case 10: /* MethodHeader: Type ID LPAR RPAR  */
#line 119 "expr.y"
                                                               {
                                                                (yyval.ast_tree) = ast_node("MethodHeader","");
                                                                add_childs((yyval.ast_tree),(yyvsp[-3].ast_tree));
                                                                aux = ast_node("MethodParams","");
                                                                add_brother((yyvsp[-3].ast_tree),ast_node("Id", (yyvsp[-2].string)));
                                                                add_childs((yyval.ast_tree), aux);
                                                               }
#line 1572 "y.tab.c"
    break;

  case 11: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 127 "expr.y"
                                                               {
                                                                (yyval.ast_tree) = ast_node("MethodHeader","");
                                                                aux = ast_node("MethodParams","");
                                                                add_childs((yyval.ast_tree),ast_node("Void", "")); 
                                                                add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-3].string)));
                                                                add_childs((yyval.ast_tree), aux);
                                                                add_childs(aux,(yyvsp[-1].ast_tree));
                                                               }
#line 1585 "y.tab.c"
    break;

  case 12: /* MethodHeader: VOID ID LPAR RPAR  */
#line 136 "expr.y"
                                                               {
                                                                (yyval.ast_tree) = ast_node("MethodHeader","");
                                                                aux = ast_node("MethodParams","");
                                                                add_childs((yyval.ast_tree),ast_node("Void", "")); 
                                                                add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-2].string)));
                                                                add_childs((yyval.ast_tree), aux);
                                                               }
#line 1597 "y.tab.c"
    break;

  case 13: /* MethodBody: LBRACE HelpMethod RBRACE  */
#line 145 "expr.y"
                                                                                 {(yyval.ast_tree) = ast_node("MethodBody",""); 
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));
                                                                                    }
#line 1605 "y.tab.c"
    break;

  case 14: /* HelpMethod: Statement HelpMethod  */
#line 151 "expr.y"
                                                                              {(yyval.ast_tree) = (yyvsp[-1].ast_tree); add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 1611 "y.tab.c"
    break;

  case 15: /* HelpMethod: VarDecl HelpMethod  */
#line 152 "expr.y"
                                                                                 {(yyval.ast_tree) = (yyvsp[-1].ast_tree); add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 1617 "y.tab.c"
    break;

  case 16: /* HelpMethod: %empty  */
#line 153 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;}
#line 1623 "y.tab.c"
    break;

  case 17: /* FieldDecl: PUBLIC STATIC Type ID HelpField SEMICOLON  */
#line 156 "expr.y"
                                                         {
                                                                (yyval.ast_tree) = ast_node("FieldDecl", "");
                                                                add_childs((yyval.ast_tree),(yyvsp[-3].ast_tree));
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].string)));
                                                                mantertipo((yyvsp[-1].ast_tree), (yyvsp[-3].ast_tree)->type);
                                                                add_brother((yyval.ast_tree), (yyvsp[-1].ast_tree));
                                                                
                                                            }
#line 1636 "y.tab.c"
    break;

  case 18: /* FieldDecl: error SEMICOLON  */
#line 164 "expr.y"
                                                             {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 1642 "y.tab.c"
    break;

  case 19: /* HelpField: COMMA ID HelpField  */
#line 168 "expr.y"
                                                      {
                                                                (yyval.ast_tree) = ast_node("FieldDecl","");                                                                
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-1].string)));
                                                                
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                
                                                            }
#line 1654 "y.tab.c"
    break;

  case 20: /* HelpField: %empty  */
#line 176 "expr.y"
                                                           {(yyval.ast_tree) = NULL;}
#line 1660 "y.tab.c"
    break;

  case 21: /* Type: INT  */
#line 179 "expr.y"
                                                            {(yyval.ast_tree) = ast_node("Int", "");}
#line 1666 "y.tab.c"
    break;

  case 22: /* Type: DOUBLE  */
#line 180 "expr.y"
                                                            {(yyval.ast_tree) = ast_node("Double", "");}
#line 1672 "y.tab.c"
    break;

  case 23: /* Type: BOOL  */
#line 181 "expr.y"
                                                            {(yyval.ast_tree) = ast_node("Bool", "");}
#line 1678 "y.tab.c"
    break;

  case 24: /* FormalParams: Type ID FormalParamsAux  */
#line 184 "expr.y"
                                                                           {(yyval.ast_tree) = ast_node("ParamDecl","");
                                                                            add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                            add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-1].string)));
                                                                            add_brother((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 1687 "y.tab.c"
    break;

  case 25: /* FormalParams: STRING LSQ RSQ ID  */
#line 189 "expr.y"
                                                                           {
                                                                           (yyval.ast_tree) = ast_node("ParamDecl","");
                                                                           add_childs((yyval.ast_tree),ast_node("StringArray",""));
                                                                           add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[0].string)));
                                                                           }
#line 1697 "y.tab.c"
    break;

  case 26: /* FormalParamsAux: COMMA Type ID FormalParamsAux  */
#line 197 "expr.y"
                                                                          { (yyval.ast_tree) = ast_node("ParamDecl","");
                                                                            add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                            add_childs((yyval.ast_tree),ast_node("Id",(yyvsp[-1].string)));
                                                                            add_brother((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                            }
#line 1707 "y.tab.c"
    break;

  case 27: /* FormalParamsAux: %empty  */
#line 203 "expr.y"
                                                                          {(yyval.ast_tree) = NULL;}
#line 1713 "y.tab.c"
    break;

  case 28: /* VarDecl: Type ID VarDeclAux SEMICOLON  */
#line 207 "expr.y"
                                                                        {
    
                                                                (yyval.ast_tree) = ast_node("VarDecl", "");
                                                                add_childs((yyval.ast_tree), (yyvsp[-3].ast_tree));
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].string)));
                                                                mantertipo((yyvsp[-1].ast_tree), (yyvsp[-3].ast_tree)->type);
                                                                
                                                                add_brother((yyval.ast_tree), (yyvsp[-1].ast_tree));
                                                                
                                                                }
#line 1728 "y.tab.c"
    break;

  case 29: /* VarDeclAux: COMMA ID VarDeclAux  */
#line 219 "expr.y"
                                                           { 
                                                                (yyval.ast_tree) = ast_node("VarDecl","");
                                                                add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-1].string)));                                                              
                                                                add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));
                                                                
                                                            }
#line 1739 "y.tab.c"
    break;

  case 30: /* VarDeclAux: %empty  */
#line 225 "expr.y"
                                                            {(yyval.ast_tree) = NULL;}
#line 1745 "y.tab.c"
    break;

  case 31: /* Statement: LBRACE StatementAux RBRACE  */
#line 228 "expr.y"
                                                                                {
                                                                              if((yyvsp[-1].ast_tree) != NULL && (yyvsp[-1].ast_tree)->brother != NULL){
                                                                                     (yyval.ast_tree) = ast_node("Block","");
                                                                                     add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));

                                                                               }else if((yyvsp[-1].ast_tree) != NULL && (yyvsp[-1].ast_tree)->brother == NULL){
                                                                                        (yyval.ast_tree) = (yyvsp[-1].ast_tree);
                                                                                    }else{(yyval.ast_tree) = NULL;}     

                                                                            }
#line 1760 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement  */
#line 241 "expr.y"
                                                                            {
                                                                               (yyval.ast_tree) = ast_node("If","");
                                                                               

                                                                               add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));


                                                                               if((yyvsp[0].ast_tree) == NULL){
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));
                                                                               }else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));
                                                                               }
                                                                            }
#line 1780 "y.tab.c"
    break;

  case 33: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 257 "expr.y"
                                                                            {
                                                                                (yyval.ast_tree) = ast_node("If","");
                                                                                add_childs((yyval.ast_tree),(yyvsp[-4].ast_tree));
                                                                                if((yyvsp[-2].ast_tree) == NULL){  //caso o primeiro satatement seja null
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));}
                                                                                else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));
                                                                                    }
                                                                                if((yyvsp[0].ast_tree) == NULL){ //caso o segundo statement seja null
                                                                                    add_childs((yyval.ast_tree),ast_node("Block",""));}
                                                                                else{
                                                                                    add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));
                                                                                    }

                                                                            }
#line 1800 "y.tab.c"
    break;

  case 34: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 272 "expr.y"
                                                                            {
                                                                             (yyval.ast_tree) = ast_node("While","");
                                                                             add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));

                                                                             if((yyvsp[0].ast_tree) != NULL){ //n tiver nd no statement
                                                                                    add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));
                                                                                }
                                                                             
                                                                            }
#line 1814 "y.tab.c"
    break;

  case 35: /* Statement: RETURN SEMICOLON  */
#line 282 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Return", "");}
#line 1820 "y.tab.c"
    break;

  case 36: /* Statement: RETURN Expr SEMICOLON  */
#line 283 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Return","");add_childs((yyval.ast_tree),(yyvsp[-1].ast_tree));}
#line 1826 "y.tab.c"
    break;

  case 37: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 284 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Print","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));}
#line 1832 "y.tab.c"
    break;

  case 38: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 285 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Print","");add_childs((yyval.ast_tree), ast_node("StrLit", (yyvsp[-2].string)));}
#line 1838 "y.tab.c"
    break;

  case 39: /* Statement: MethodInvocation SEMICOLON  */
#line 286 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 1844 "y.tab.c"
    break;

  case 40: /* Statement: Assignment SEMICOLON  */
#line 287 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 1850 "y.tab.c"
    break;

  case 41: /* Statement: ParseArgs SEMICOLON  */
#line 288 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 1856 "y.tab.c"
    break;

  case 42: /* Statement: SEMICOLON  */
#line 289 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;}
#line 1862 "y.tab.c"
    break;

  case 43: /* Statement: error SEMICOLON  */
#line 290 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 1868 "y.tab.c"
    break;

  case 44: /* StatementAux: Statement StatementAux  */
#line 293 "expr.y"
                                                                                    {if((yyval.ast_tree) != NULL){(yyval.ast_tree) = (yyvsp[-1].ast_tree); add_brother((yyvsp[-1].ast_tree),(yyvsp[0].ast_tree));}else{(yyval.ast_tree) = (yyvsp[0].ast_tree);}}
#line 1874 "y.tab.c"
    break;

  case 45: /* StatementAux: %empty  */
#line 294 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;}
#line 1880 "y.tab.c"
    break;

  case 46: /* MethodInvocation: ID LPAR Expr MethodInvocationaux RPAR  */
#line 297 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Call", "");add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-4].string)));add_childs((yyval.ast_tree), (yyvsp[-2].ast_tree));add_childs((yyval.ast_tree), (yyvsp[-1].ast_tree));}
#line 1886 "y.tab.c"
    break;

  case 47: /* MethodInvocation: ID LPAR RPAR  */
#line 298 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Call", "");add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-2].string)));}
#line 1892 "y.tab.c"
    break;

  case 48: /* MethodInvocation: ID LPAR error RPAR  */
#line 299 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 1898 "y.tab.c"
    break;

  case 49: /* MethodInvocationaux: COMMA Expr MethodInvocationaux  */
#line 302 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);add_brother((yyval.ast_tree), (yyvsp[0].ast_tree));}
#line 1904 "y.tab.c"
    break;

  case 50: /* MethodInvocationaux: %empty  */
#line 303 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;}
#line 1910 "y.tab.c"
    break;

  case 51: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 306 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("ParseArgs","");add_childs((yyval.ast_tree), ast_node("Id", (yyvsp[-4].string)));add_childs((yyval.ast_tree), (yyvsp[-2].ast_tree));}
#line 1916 "y.tab.c"
    break;

  case 52: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 307 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 1922 "y.tab.c"
    break;

  case 53: /* Assignment: ID ASSIGN Expr  */
#line 310 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Assign", "");add_childs((yyval.ast_tree),ast_node("Id", (yyvsp[-2].string)));add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 1928 "y.tab.c"
    break;

  case 54: /* Expr: Expr PLUS Expr  */
#line 313 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Add","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1934 "y.tab.c"
    break;

  case 55: /* Expr: Expr MINUS Expr  */
#line 314 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Sub","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1940 "y.tab.c"
    break;

  case 56: /* Expr: Expr STAR Expr  */
#line 315 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Mul","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1946 "y.tab.c"
    break;

  case 57: /* Expr: Expr DIV Expr  */
#line 316 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Div","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1952 "y.tab.c"
    break;

  case 58: /* Expr: Expr MOD Expr  */
#line 317 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Mod","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1958 "y.tab.c"
    break;

  case 59: /* Expr: Expr OR Expr  */
#line 318 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Or","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1964 "y.tab.c"
    break;

  case 60: /* Expr: Expr XOR Expr  */
#line 319 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Xor","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1970 "y.tab.c"
    break;

  case 61: /* Expr: Expr AND Expr  */
#line 320 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("And","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1976 "y.tab.c"
    break;

  case 62: /* Expr: Expr LSHIFT Expr  */
#line 321 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Lshift","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1982 "y.tab.c"
    break;

  case 63: /* Expr: Expr RSHIFT Expr  */
#line 322 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Rshift","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1988 "y.tab.c"
    break;

  case 64: /* Expr: Expr EQ Expr  */
#line 323 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Eq","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 1994 "y.tab.c"
    break;

  case 65: /* Expr: Expr NE Expr  */
#line 324 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Ne","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2000 "y.tab.c"
    break;

  case 66: /* Expr: Expr LT Expr  */
#line 325 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Lt","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2006 "y.tab.c"
    break;

  case 67: /* Expr: Expr GT Expr  */
#line 326 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Gt","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2012 "y.tab.c"
    break;

  case 68: /* Expr: Expr LE Expr  */
#line 327 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Le","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2018 "y.tab.c"
    break;

  case 69: /* Expr: Expr GE Expr  */
#line 328 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Ge","");add_childs((yyval.ast_tree),(yyvsp[-2].ast_tree));add_brother((yyvsp[-2].ast_tree),(yyvsp[0].ast_tree));}
#line 2024 "y.tab.c"
    break;

  case 70: /* Expr: MINUS Expr  */
#line 329 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Minus","");add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2030 "y.tab.c"
    break;

  case 71: /* Expr: NOT Expr  */
#line 330 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Not","");add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2036 "y.tab.c"
    break;

  case 72: /* Expr: PLUS Expr  */
#line 331 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Plus","");add_childs((yyval.ast_tree),(yyvsp[0].ast_tree));}
#line 2042 "y.tab.c"
    break;

  case 73: /* Expr: LPAR Expr RPAR  */
#line 332 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[-1].ast_tree);}
#line 2048 "y.tab.c"
    break;

  case 74: /* Expr: ID  */
#line 333 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Id",(yyvsp[0].string));}
#line 2054 "y.tab.c"
    break;

  case 75: /* Expr: ID DOTLENGTH  */
#line 334 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("Length",""); add_childs((yyval.ast_tree),ast_node("Id",(yyvsp[-1].string)));}
#line 2060 "y.tab.c"
    break;

  case 76: /* Expr: INTLIT  */
#line 335 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("DecLit",(yyvsp[0].string));}
#line 2066 "y.tab.c"
    break;

  case 77: /* Expr: REALLIT  */
#line 336 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("RealLit",(yyvsp[0].string));}
#line 2072 "y.tab.c"
    break;

  case 78: /* Expr: BOOLLIT  */
#line 337 "expr.y"
                                                                                    {(yyval.ast_tree) = ast_node("BoolLit",(yyvsp[0].string));}
#line 2078 "y.tab.c"
    break;

  case 79: /* Expr: MethodInvocation  */
#line 338 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[0].ast_tree);}
#line 2084 "y.tab.c"
    break;

  case 80: /* Expr: Assignment  */
#line 339 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[0].ast_tree);}
#line 2090 "y.tab.c"
    break;

  case 81: /* Expr: ParseArgs  */
#line 340 "expr.y"
                                                                                    {(yyval.ast_tree) = (yyvsp[0].ast_tree);}
#line 2096 "y.tab.c"
    break;

  case 82: /* Expr: LPAR error RPAR  */
#line 341 "expr.y"
                                                                                    {(yyval.ast_tree) = NULL;flag_erro = 1;}
#line 2102 "y.tab.c"
    break;


#line 2106 "y.tab.c"

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

#line 344 "expr.y"




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
