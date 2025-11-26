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
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include "hashtbl.h"

extern int error_count;
HASHTBL *hashtbl;
int scope = 0;

extern FILE* yyin;
extern int yylineno;
extern int yylex();

extern void yyerror(const char* err);

#line 91 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_PROGRAM = 3,                  /* "program"  */
  YYSYMBOL_T_CONST = 4,                    /* "const"  */
  YYSYMBOL_T_TYPE = 5,                     /* "type"  */
  YYSYMBOL_T_ARRAY = 6,                    /* "array"  */
  YYSYMBOL_T_LIST = 7,                     /* "list"  */
  YYSYMBOL_T_SET = 8,                      /* "set"  */
  YYSYMBOL_T_OF = 9,                       /* "of"  */
  YYSYMBOL_T_RECORD = 10,                  /* "record"  */
  YYSYMBOL_T_VAR = 11,                     /* "var"  */
  YYSYMBOL_T_FUNCTION = 12,                /* "function"  */
  YYSYMBOL_T_PROCEDURE = 13,               /* "procedure"  */
  YYSYMBOL_T_INTEGER = 14,                 /* "integer"  */
  YYSYMBOL_T_REAL = 15,                    /* "real"  */
  YYSYMBOL_T_BOOLEAN = 16,                 /* "boolean"  */
  YYSYMBOL_T_CHAR = 17,                    /* "char"  */
  YYSYMBOL_T_FORWARD = 18,                 /* "forward"  */
  YYSYMBOL_T_LENGTH = 19,                  /* "length"  */
  YYSYMBOL_T_NEW = 20,                     /* "new"  */
  YYSYMBOL_T_BEGIN = 21,                   /* "begin"  */
  YYSYMBOL_T_END = 22,                     /* "end"  */
  YYSYMBOL_T_IF = 23,                      /* "if"  */
  YYSYMBOL_T_THEN = 24,                    /* "then"  */
  YYSYMBOL_T_ELSE = 25,                    /* "else"  */
  YYSYMBOL_T_WHILE = 26,                   /* "while"  */
  YYSYMBOL_T_DO = 27,                      /* "do"  */
  YYSYMBOL_T_CASE = 28,                    /* "case"  */
  YYSYMBOL_T_OTHERWISE = 29,               /* "otherwise"  */
  YYSYMBOL_T_FOR = 30,                     /* "for"  */
  YYSYMBOL_T_TO = 31,                      /* "to"  */
  YYSYMBOL_T_DOWNTO = 32,                  /* "downto"  */
  YYSYMBOL_T_WITH = 33,                    /* "with"  */
  YYSYMBOL_T_READ = 34,                    /* "read"  */
  YYSYMBOL_T_WRITE = 35,                   /* "write"  */
  YYSYMBOL_T_ID = 36,                      /* "id"  */
  YYSYMBOL_T_STRING = 37,                  /* "string"  */
  YYSYMBOL_T_LISTFUNC = 38,                /* "listfunc"  */
  YYSYMBOL_T_ICONST = 39,                  /* "integer constant"  */
  YYSYMBOL_T_RCONST = 40,                  /* "real constant"  */
  YYSYMBOL_T_BCONST = 41,                  /* "boolean constant"  */
  YYSYMBOL_T_CCONST = 42,                  /* "char constant"  */
  YYSYMBOL_T_RELOP = 43,                   /* "> or >= or < or <= or <>"  */
  YYSYMBOL_T_ADDOP = 44,                   /* "+ or -"  */
  YYSYMBOL_T_OROP = 45,                    /* "OR"  */
  YYSYMBOL_T_MULDIVANDOP = 46,             /* "* or / or DIV or AND or MOD"  */
  YYSYMBOL_T_NOTOP = 47,                   /* "NOT"  */
  YYSYMBOL_T_INOP = 48,                    /* "IN"  */
  YYSYMBOL_T_LPAREN = 49,                  /* "("  */
  YYSYMBOL_T_RPAREN = 50,                  /* ")"  */
  YYSYMBOL_T_SEMI = 51,                    /* ";"  */
  YYSYMBOL_T_DOT = 52,                     /* "."  */
  YYSYMBOL_T_COMMA = 53,                   /* ","  */
  YYSYMBOL_T_EQU = 54,                     /* "="  */
  YYSYMBOL_T_COLON = 55,                   /* ":"  */
  YYSYMBOL_T_LBRACK = 56,                  /* "["  */
  YYSYMBOL_T_RBRACK = 57,                  /* "]"  */
  YYSYMBOL_T_ASSIGN = 58,                  /* ":="  */
  YYSYMBOL_T_DOTDOT = 59,                  /* ".."  */
  YYSYMBOL_LOWER_THAN_ELSE = 60,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_program = 62,                   /* program  */
  YYSYMBOL_header = 63,                    /* header  */
  YYSYMBOL_declarations = 64,              /* declarations  */
  YYSYMBOL_constdefs = 65,                 /* constdefs  */
  YYSYMBOL_constant_defs = 66,             /* constant_defs  */
  YYSYMBOL_expression = 67,                /* expression  */
  YYSYMBOL_variable = 68,                  /* variable  */
  YYSYMBOL_expressions = 69,               /* expressions  */
  YYSYMBOL_constant = 70,                  /* constant  */
  YYSYMBOL_setlistexpression = 71,         /* setlistexpression  */
  YYSYMBOL_typedefs = 72,                  /* typedefs  */
  YYSYMBOL_type_defs = 73,                 /* type_defs  */
  YYSYMBOL_type_def = 74,                  /* type_def  */
  YYSYMBOL_75_1 = 75,                      /* $@1  */
  YYSYMBOL_76_2 = 76,                      /* $@2  */
  YYSYMBOL_dims = 77,                      /* dims  */
  YYSYMBOL_limits = 78,                    /* limits  */
  YYSYMBOL_limit = 79,                     /* limit  */
  YYSYMBOL_sign = 80,                      /* sign  */
  YYSYMBOL_typename = 81,                  /* typename  */
  YYSYMBOL_standard_type = 82,             /* standard_type  */
  YYSYMBOL_fields = 83,                    /* fields  */
  YYSYMBOL_field = 84,                     /* field  */
  YYSYMBOL_identifiers = 85,               /* identifiers  */
  YYSYMBOL_vardefs = 86,                   /* vardefs  */
  YYSYMBOL_variable_defs = 87,             /* variable_defs  */
  YYSYMBOL_subprograms = 88,               /* subprograms  */
  YYSYMBOL_subprogram = 89,                /* subprogram  */
  YYSYMBOL_sub_header = 90,                /* sub_header  */
  YYSYMBOL_formal_parameters = 91,         /* formal_parameters  */
  YYSYMBOL_parameter_list = 92,            /* parameter_list  */
  YYSYMBOL_pass = 93,                      /* pass  */
  YYSYMBOL_comp_statement = 94,            /* comp_statement  */
  YYSYMBOL_statements = 95,                /* statements  */
  YYSYMBOL_statement = 96,                 /* statement  */
  YYSYMBOL_assignment = 97,                /* assignment  */
  YYSYMBOL_if_statement = 98,              /* if_statement  */
  YYSYMBOL_99_3 = 99,                      /* $@3  */
  YYSYMBOL_100_4 = 100,                    /* $@4  */
  YYSYMBOL_if_tail = 101,                  /* if_tail  */
  YYSYMBOL_102_5 = 102,                    /* $@5  */
  YYSYMBOL_case_statement = 103,           /* case_statement  */
  YYSYMBOL_cases = 104,                    /* cases  */
  YYSYMBOL_single_case = 105,              /* single_case  */
  YYSYMBOL_label_list = 106,               /* label_list  */
  YYSYMBOL_label = 107,                    /* label  */
  YYSYMBOL_case_tail = 108,                /* case_tail  */
  YYSYMBOL_while_statement = 109,          /* while_statement  */
  YYSYMBOL_110_6 = 110,                    /* $@6  */
  YYSYMBOL_for_statement = 111,            /* for_statement  */
  YYSYMBOL_112_7 = 112,                    /* $@7  */
  YYSYMBOL_iter_space = 113,               /* iter_space  */
  YYSYMBOL_with_statement = 114,           /* with_statement  */
  YYSYMBOL_115_8 = 115,                    /* $@8  */
  YYSYMBOL_subprogram_call = 116,          /* subprogram_call  */
  YYSYMBOL_io_statement = 117,             /* io_statement  */
  YYSYMBOL_read_list = 118,                /* read_list  */
  YYSYMBOL_read_item = 119,                /* read_item  */
  YYSYMBOL_write_list = 120,               /* write_list  */
  YYSYMBOL_write_item = 121                /* write_item  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  292

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   315


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   124,   125,   126,   127,   130,   133,   134,
     135,   138,   139,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   160,
     161,   162,   163,   164,   167,   168,   170,   171,   172,   173,
     176,   177,   179,   180,   183,   184,   187,   188,   189,   190,
     191,   191,   191,   192,   195,   196,   199,   200,   203,   204,
     205,   206,   207,   210,   211,   214,   215,   218,   219,   220,
     221,   224,   225,   228,   231,   232,   235,   236,   239,   240,
     245,   246,   249,   250,   253,   254,   255,   256,   257,   258,
     261,   262,   265,   266,   269,   270,   273,   276,   277,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   292,
     293,   296,   296,   296,   299,   299,   300,   303,   306,   307,
     309,   310,   313,   314,   317,   318,   321,   322,   325,   325,
     328,   328,   331,   332,   335,   335,   338,   339,   342,   343,
     346,   347,   350,   353,   354,   357,   358
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"program\"",
  "\"const\"", "\"type\"", "\"array\"", "\"list\"", "\"set\"", "\"of\"",
  "\"record\"", "\"var\"", "\"function\"", "\"procedure\"", "\"integer\"",
  "\"real\"", "\"boolean\"", "\"char\"", "\"forward\"", "\"length\"",
  "\"new\"", "\"begin\"", "\"end\"", "\"if\"", "\"then\"", "\"else\"",
  "\"while\"", "\"do\"", "\"case\"", "\"otherwise\"", "\"for\"", "\"to\"",
  "\"downto\"", "\"with\"", "\"read\"", "\"write\"", "\"id\"",
  "\"string\"", "\"listfunc\"", "\"integer constant\"",
  "\"real constant\"", "\"boolean constant\"", "\"char constant\"",
  "\"> or >= or < or <= or <>\"", "\"+ or -\"", "\"OR\"",
  "\"* or / or DIV or AND or MOD\"", "\"NOT\"", "\"IN\"", "\"(\"", "\")\"",
  "\";\"", "\".\"", "\",\"", "\"=\"", "\":\"", "\"[\"", "\"]\"", "\":=\"",
  "\"..\"", "LOWER_THAN_ELSE", "$accept", "program", "header",
  "declarations", "constdefs", "constant_defs", "expression", "variable",
  "expressions", "constant", "setlistexpression", "typedefs", "type_defs",
  "type_def", "$@1", "$@2", "dims", "limits", "limit", "sign", "typename",
  "standard_type", "fields", "field", "identifiers", "vardefs",
  "variable_defs", "subprograms", "subprogram", "sub_header",
  "formal_parameters", "parameter_list", "pass", "comp_statement",
  "statements", "statement", "assignment", "if_statement", "$@3", "$@4",
  "if_tail", "$@5", "case_statement", "cases", "single_case", "label_list",
  "label", "case_tail", "while_statement", "$@6", "for_statement", "$@7",
  "iter_space", "with_statement", "$@8", "subprogram_call", "io_statement",
  "read_list", "read_item", "write_list", "write_item", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-137)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,    35,    15,    45,    53,    52,    93,    16,  -173,    98,
    -173,    76,    42,    50,    90,  -173,    88,    20,    18,   111,
     140,  -173,  -173,  -173,   252,  -173,   127,    17,   141,   295,
     133,   134,   152,   163,   167,   178,  -173,   171,   193,   204,
     205,  -173,  -173,  -173,  -173,   252,   252,   252,   126,   149,
     -19,  -173,  -173,   189,   222,   151,   212,   252,   252,   252,
     238,   172,   220,   231,   147,    81,  -173,     3,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,    24,  -173,
     180,   248,  -173,   160,   234,   252,   252,   252,   252,   243,
    -173,    69,  -173,   149,    65,   252,   252,   252,   252,   252,
     252,   264,   252,   252,   212,   284,     6,  -173,    54,   259,
       4,   257,  -173,   -12,   172,   192,   252,   226,  -173,   295,
    -173,  -173,   250,   308,   310,  -173,  -173,  -173,  -173,   286,
    -173,   265,   287,   273,   296,   138,   178,   233,   291,    -7,
      82,  -173,  -173,   252,  -173,   303,   243,   243,  -173,   303,
     303,  -173,    91,   149,   283,  -173,   -31,   178,   285,   142,
    -173,  -173,    99,   252,  -173,   -19,    29,  -173,  -173,   149,
      57,  -173,   128,  -173,   149,  -173,    18,   165,   138,   138,
     178,  -173,   215,  -173,   180,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,   170,  -173,  -173,  -173,  -173,  -173,   149,
    -173,   344,  -173,   284,   182,   344,  -173,  -173,   295,   295,
    -173,   314,   292,  -173,   185,  -173,   266,   315,   295,  -173,
     172,  -173,   192,  -173,  -173,   293,    11,  -173,   304,  -173,
    -173,   311,  -173,   194,  -173,  -173,   138,  -173,   178,   138,
    -173,  -173,  -173,  -173,  -173,    87,   322,   320,   295,   252,
     252,  -173,  -173,  -173,  -173,   356,   165,   357,   215,   178,
     345,   138,  -173,   197,  -173,   343,   316,  -173,  -173,  -173,
    -173,   149,   149,   295,   138,  -173,   138,  -173,  -173,  -173,
    -173,   138,  -173,  -173,   295,  -173,  -173,  -173,  -173,   295,
    -173,  -173
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    10,     0,     0,     0,     1,     0,
      81,    43,     0,     0,     0,     3,     0,     0,     0,     0,
      77,     4,     5,     6,     0,     9,     8,     0,     0,   108,
       0,     0,     0,     0,     0,     0,     7,     0,     0,    29,
       0,    36,    37,    38,    39,     0,     0,     0,     0,    12,
      21,    25,    28,     0,     0,    91,    91,     0,     0,     0,
       0,     0,     0,     0,    29,     0,   107,     0,    98,    99,
     100,   101,   102,   103,   104,   105,   106,    80,    10,     2,
      64,    42,    75,     0,     0,     0,     0,     0,     0,    19,
      20,     0,    41,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    91,    95,     0,    86,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,    96,   108,
      82,    81,     0,     0,     0,    50,    62,    60,    59,    63,
      45,     0,     0,     0,     0,     0,    76,     0,     0,     0,
       0,    27,    26,     0,    40,    13,    17,    16,    18,    15,
      14,    30,     0,    11,     0,    94,     0,     0,     0,     0,
     111,   128,    64,     0,   134,   142,     0,   141,   146,   145,
       0,   144,     0,   110,   109,    97,     0,    64,     0,     0,
       0,    61,    64,    58,    64,    74,    67,    68,    69,    70,
      66,    79,    65,     0,    23,    24,    22,    33,    32,    34,
      31,     0,    90,    95,     0,     0,    85,    84,   108,   108,
      63,     0,   127,   119,     0,   123,     0,     0,   108,   138,
       0,   139,     0,   137,    83,    57,     0,    55,     0,    48,
      49,    51,    72,     0,    53,    44,     0,    88,     0,     0,
      89,   112,   129,   125,   124,    64,     0,    64,   108,     0,
       0,   130,   135,   140,   143,     0,    64,     0,    64,     0,
       0,     0,    78,     0,    93,   116,     0,   118,   117,   122,
     120,   132,   133,   108,     0,    54,     0,    56,    71,    52,
      73,     0,   114,   113,   108,   131,    47,    46,    92,   108,
     126,   115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,  -173,   294,  -173,  -173,   -23,   -29,   -61,   158,
    -173,  -173,  -173,   186,  -173,  -173,  -173,   117,  -172,  -158,
    -170,  -145,  -173,   115,   -33,  -173,  -173,   254,  -173,  -173,
     -45,  -173,   173,   -15,  -173,  -113,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,   132,  -173,   131,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,   159,  -173,
     161
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     3,     4,    10,    11,    17,    93,    50,    94,    51,
      52,    20,    34,   130,   180,   260,   226,   227,   131,   132,
     191,   192,   231,   232,   233,    36,    84,    18,    30,    31,
     106,   156,   157,    66,    67,    68,    69,    70,   208,   265,
     283,   289,    71,   212,   213,   214,   215,   246,    72,   209,
      73,   273,   217,    74,   218,    75,    76,   166,   167,   170,
     171
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    49,    83,    32,   211,   228,   175,   158,   229,   230,
     234,   107,   255,   162,   207,   164,     6,    14,    54,   202,
     203,    25,    89,    90,    91,   118,   139,     1,     9,     2,
      27,    28,   113,   101,   108,   109,   110,   102,     5,    29,
     101,   152,   120,   196,   102,     8,   143,    95,    96,    97,
      98,     7,    99,    55,   119,   172,   237,     9,   100,   154,
     240,   159,   137,   138,   256,   140,   262,    15,   257,   264,
     141,    26,   145,   146,   147,   148,   149,   150,   160,   219,
     153,    19,   220,   197,   228,   165,   277,   211,    12,   211,
      65,   280,   169,    21,   174,   241,   242,    95,    96,    97,
      98,    22,    99,   193,   286,   252,   287,   221,   100,  -121,
     222,   288,    95,    96,    97,    98,   266,    99,   143,   142,
     199,  -121,   144,   100,   204,    95,    96,    97,    98,    13,
      99,   210,   198,   101,    16,   270,   100,   102,  -121,   117,
     216,    23,    24,   210,   143,    37,    38,    33,   200,   206,
    -121,    35,   186,   187,   188,   189,   186,   187,   188,   189,
     285,   224,    39,    53,    40,    41,    42,    43,    44,  -136,
      45,   290,  -136,    46,   190,    47,   291,    56,   223,    65,
      65,   143,    48,    92,    77,    78,   122,   123,   124,    65,
     125,   165,    95,    96,    97,    98,   116,    99,  -136,   169,
     105,   225,   -87,   100,    79,   263,   127,   128,   112,   129,
      40,    37,    38,   134,    82,   135,   126,    80,    81,    65,
      85,   127,   128,   134,   129,   236,   271,   272,    39,   168,
      40,    41,    42,    43,    44,   134,    45,   239,   247,    46,
     248,    47,    86,   103,    65,    37,    38,   134,    48,   261,
     134,   126,   281,    87,    88,    65,   127,   128,   104,   129,
      65,   105,    39,   173,    40,    41,    42,    43,    44,   114,
      45,    37,    38,    46,   111,    47,    95,    96,    97,    98,
     115,    99,    48,   194,   133,   136,   161,   100,    39,    98,
      40,    41,    42,    43,    44,   155,    45,   249,   250,    46,
     151,    47,    95,    96,    97,    98,   177,    99,    48,    95,
      96,    97,    98,   100,    99,   163,    29,   178,    57,   179,
     100,    58,   181,    59,   182,    60,   183,   184,    61,    62,
      63,    64,   185,    40,    95,    96,    97,    98,   201,    99,
     205,   195,   251,   245,   268,   100,  -137,    96,    97,    98,
     243,  -137,   -62,    41,    42,    43,    44,  -137,   186,   187,
     188,   189,   259,   258,   210,   274,   276,   279,   282,   244,
     235,   284,   121,   275,   278,   176,   238,   267,   269,   253,
       0,     0,     0,   254
};

static const yytype_int16 yycheck[] =
{
      29,    24,    35,    18,   162,   177,   119,     1,   178,   179,
     182,    56,     1,     9,   159,    27,     1,     1,     1,    50,
      51,     1,    45,    46,    47,    22,    87,     1,     4,     3,
      12,    13,    61,    52,    57,    58,    59,    56,     3,    21,
      52,   102,    18,    50,    56,     0,    53,    43,    44,    45,
      46,    36,    48,    36,    51,   116,   201,     4,    54,   104,
     205,    55,    85,    86,    53,    88,   236,    51,    57,   239,
       1,    51,    95,    96,    97,    98,    99,   100,    24,    50,
     103,     5,    53,     1,   256,   114,   258,   245,    36,   247,
     119,   261,   115,    51,   117,   208,   209,    43,    44,    45,
      46,    51,    48,   136,   274,   218,   276,    50,    54,    22,
      53,   281,    43,    44,    45,    46,    29,    48,    53,    50,
     143,    22,    57,    54,   157,    43,    44,    45,    46,    36,
      48,    44,    50,    52,    36,   248,    54,    56,    51,    58,
     163,    51,    54,    44,    53,    19,    20,    36,    57,     7,
      51,    11,    14,    15,    16,    17,    14,    15,    16,    17,
     273,   176,    36,    36,    38,    39,    40,    41,    42,    22,
      44,   284,    25,    47,    36,    49,   289,    36,    50,   208,
     209,    53,    56,    57,    51,    51,     6,     7,     8,   218,
      10,   220,    43,    44,    45,    46,    49,    48,    51,   222,
      49,    36,    51,    54,    52,   238,    41,    42,    36,    44,
      38,    19,    20,    53,    36,    55,    36,    54,    51,   248,
      49,    41,    42,    53,    44,    55,   249,   250,    36,    37,
      38,    39,    40,    41,    42,    53,    44,    55,    53,    47,
      55,    49,    49,    54,   273,    19,    20,    53,    56,    55,
      53,    36,    55,    49,    49,   284,    41,    42,    36,    44,
     289,    49,    36,    37,    38,    39,    40,    41,    42,    49,
      44,    19,    20,    47,    36,    49,    43,    44,    45,    46,
      49,    48,    56,    50,    36,    51,    27,    54,    36,    46,
      38,    39,    40,    41,    42,    11,    44,    31,    32,    47,
      36,    49,    43,    44,    45,    46,    56,    48,    56,    43,
      44,    45,    46,    54,    48,    58,    21,     9,    23,     9,
      54,    26,    36,    28,    59,    30,    39,    54,    33,    34,
      35,    36,    36,    38,    43,    44,    45,    46,    55,    48,
      55,    50,    27,    51,    22,    54,    43,    44,    45,    46,
      36,    48,    59,    39,    40,    41,    42,    54,    14,    15,
      16,    17,    51,    59,    44,     9,     9,    22,    25,   211,
     184,    55,    78,   256,   259,   121,   203,   245,   247,   220,
      -1,    -1,    -1,   222
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    62,    63,     3,     1,    36,     0,     4,
      64,    65,    36,    36,     1,    51,    36,    66,    88,     5,
      72,    51,    51,    51,    54,     1,    51,    12,    13,    21,
      89,    90,    94,    36,    73,    11,    86,    19,    20,    36,
      38,    39,    40,    41,    42,    44,    47,    49,    56,    67,
      68,    70,    71,    36,     1,    36,    36,    23,    26,    28,
      30,    33,    34,    35,    36,    68,    94,    95,    96,    97,
      98,   103,   109,   111,   114,   116,   117,    51,    51,    52,
      54,    51,    36,    85,    87,    49,    49,    49,    49,    67,
      67,    67,    57,    67,    69,    43,    44,    45,    46,    48,
      54,    52,    56,    54,    36,    49,    91,    91,    67,    67,
      67,    36,    36,    68,    49,    49,    49,    58,    22,    51,
      18,    64,     6,     7,     8,    10,    36,    41,    42,    44,
      74,    79,    80,    36,    53,    55,    51,    67,    67,    69,
      67,     1,    50,    53,    57,    67,    67,    67,    67,    67,
      67,    36,    69,    67,    91,    11,    92,    93,     1,    55,
      24,    27,     9,    58,    27,    68,   118,   119,    37,    67,
     120,   121,    69,    37,    67,    96,    88,    56,     9,     9,
      75,    36,    59,    39,    54,    36,    14,    15,    16,    17,
      36,    81,    82,    85,    50,    50,    50,     1,    50,    67,
      57,    55,    50,    51,    85,    55,     7,    82,    99,   110,
      44,    80,   104,   105,   106,   107,    67,   113,   115,    50,
      53,    50,    53,    50,    94,    36,    77,    78,    79,    81,
      81,    83,    84,    85,    79,    74,    55,    82,    93,    55,
      82,    96,    96,    36,    70,    51,   108,    53,    55,    31,
      32,    27,    96,   119,   121,     1,    53,    57,    59,    51,
      76,    55,    81,    85,    81,   100,    29,   105,    22,   107,
      96,    67,    67,   112,     9,    78,     9,    79,    84,    22,
      81,    55,    25,   101,    55,    96,    81,    81,    81,   102,
      96,    96
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    63,    64,    65,    65,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    70,
      71,    71,    72,    72,    73,    73,    74,    74,    74,    74,
      75,    76,    74,    74,    77,    77,    78,    78,    79,    79,
      79,    79,    79,    80,    80,    81,    81,    82,    82,    82,
      82,    83,    83,    84,    85,    85,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    90,    90,    90,    90,    90,
      91,    91,    92,    92,    93,    93,    94,    95,    95,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    99,   100,    98,   102,   101,   101,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   110,   109,
     112,   111,   113,   113,   115,   114,   116,   116,   117,   117,
     118,   118,   119,   120,   120,   121,   121
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     4,     4,     4,     3,     3,     3,
       0,     5,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     4,     4,     4,     1,     3,     3,     1,     1,
       3,     4,     4,     4,     3,     1,     1,     1,     1,     1,
       3,     2,     3,     0,     5,     3,     6,     6,     3,     3,
       0,     0,     5,     3,     3,     1,     3,     1,     2,     1,
       1,     2,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     3,     1,     3,     3,     1,     3,     0,     5,     3,
       3,     0,     3,     5,     5,     5,     3,     2,     6,     6,
       3,     0,     6,     4,     1,     0,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     3,
       3,     0,     0,     7,     0,     3,     0,     6,     3,     1,
       3,     0,     3,     1,     2,     2,     4,     0,     0,     5,
       0,     7,     3,     3,     0,     5,     1,     4,     4,     4,
       3,     1,     1,     3,     1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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

  if (yychar <= T_EOF)
    {
      yychar = T_EOF;
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
  case 3: /* header: "program" "id" ";"  */
#line 124 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope); }
#line 1700 "parser.tab.c"
    break;

  case 4: /* header: error "program" "id" ";"  */
#line 125 "parser.y"
                                                                { yyerrok; }
#line 1706 "parser.tab.c"
    break;

  case 5: /* header: "program" error "id" ";"  */
#line 126 "parser.y"
                                                                { yyerrok; }
#line 1712 "parser.tab.c"
    break;

  case 6: /* header: "program" "id" error ";"  */
#line 127 "parser.y"
                                                                { yyerrok; }
#line 1718 "parser.tab.c"
    break;

  case 9: /* constdefs: "const" constant_defs error  */
#line 134 "parser.y"
                                                                { yyerrok; }
#line 1724 "parser.tab.c"
    break;

  case 10: /* constdefs: %empty  */
#line 135 "parser.y"
                         {}
#line 1730 "parser.tab.c"
    break;

  case 11: /* constant_defs: constant_defs ";" "id" "=" expression  */
#line 138 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[-2].strval), NULL, scope); }
#line 1736 "parser.tab.c"
    break;

  case 12: /* constant_defs: "id" "=" expression  */
#line 139 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope); }
#line 1742 "parser.tab.c"
    break;

  case 22: /* expression: "id" "(" expressions ")"  */
#line 151 "parser.y"
                                                            { hashtbl_insert(hashtbl, (yyvsp[-3].strval), NULL, scope); }
#line 1748 "parser.tab.c"
    break;

  case 27: /* expression: "(" expression error  */
#line 156 "parser.y"
                                                            {yyerrok;}
#line 1754 "parser.tab.c"
    break;

  case 29: /* variable: "id"  */
#line 160 "parser.y"
                                                            { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1760 "parser.tab.c"
    break;

  case 30: /* variable: variable "." "id"  */
#line 161 "parser.y"
                                                            { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1766 "parser.tab.c"
    break;

  case 33: /* variable: "listfunc" "(" expression error  */
#line 164 "parser.y"
                                                            {yyerrok;}
#line 1772 "parser.tab.c"
    break;

  case 36: /* constant: "integer constant"  */
#line 170 "parser.y"
                                { (yyval.intval) = (yyvsp[0].intval); }
#line 1778 "parser.tab.c"
    break;

  case 37: /* constant: "real constant"  */
#line 171 "parser.y"
                                { (yyval.realval) = (yyvsp[0].realval); }
#line 1784 "parser.tab.c"
    break;

  case 39: /* constant: "char constant"  */
#line 173 "parser.y"
                                { (yyval.charval) = (yyvsp[0].charval); }
#line 1790 "parser.tab.c"
    break;

  case 43: /* typedefs: %empty  */
#line 180 "parser.y"
                         {}
#line 1796 "parser.tab.c"
    break;

  case 44: /* type_defs: type_defs ";" "id" "=" type_def  */
#line 183 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[-2].strval), NULL, scope); }
#line 1802 "parser.tab.c"
    break;

  case 45: /* type_defs: "id" "=" type_def  */
#line 184 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[-2].strval), NULL, scope); }
#line 1808 "parser.tab.c"
    break;

  case 47: /* type_def: "array" "[" dims error "of" typename  */
#line 188 "parser.y"
                                                                {yyerrok;}
#line 1814 "parser.tab.c"
    break;

  case 50: /* $@1: %empty  */
#line 191 "parser.y"
                           {scope++;}
#line 1820 "parser.tab.c"
    break;

  case 51: /* $@2: %empty  */
#line 191 "parser.y"
                                             {hashtbl_get(hashtbl, scope); scope--;}
#line 1826 "parser.tab.c"
    break;

  case 57: /* limits: "id"  */
#line 200 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1832 "parser.tab.c"
    break;

  case 59: /* limit: "char constant"  */
#line 204 "parser.y"
                                                                { (yyval.charval) = (yyvsp[0].charval); }
#line 1838 "parser.tab.c"
    break;

  case 61: /* limit: "+ or -" "id"  */
#line 206 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1844 "parser.tab.c"
    break;

  case 62: /* limit: "id"  */
#line 207 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1850 "parser.tab.c"
    break;

  case 64: /* sign: %empty  */
#line 211 "parser.y"
                         {}
#line 1856 "parser.tab.c"
    break;

  case 66: /* typename: "id"  */
#line 215 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1862 "parser.tab.c"
    break;

  case 74: /* identifiers: identifiers "," "id"  */
#line 231 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1868 "parser.tab.c"
    break;

  case 75: /* identifiers: "id"  */
#line 232 "parser.y"
                                                                { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1874 "parser.tab.c"
    break;

  case 77: /* vardefs: %empty  */
#line 236 "parser.y"
                         {}
#line 1880 "parser.tab.c"
    break;

  case 80: /* subprograms: subprograms subprogram ";"  */
#line 245 "parser.y"
                                                                                {hashtbl_get(hashtbl, scope); scope--;}
#line 1886 "parser.tab.c"
    break;

  case 81: /* subprograms: %empty  */
#line 246 "parser.y"
                         {}
#line 1892 "parser.tab.c"
    break;

  case 84: /* sub_header: "function" "id" formal_parameters ":" standard_type  */
#line 253 "parser.y"
                                                                                { hashtbl_insert(hashtbl, (yyvsp[-3].strval), NULL, scope); scope++; }
#line 1898 "parser.tab.c"
    break;

  case 85: /* sub_header: "function" "id" formal_parameters ":" "list"  */
#line 254 "parser.y"
                                                                                { hashtbl_insert(hashtbl, (yyvsp[-3].strval), NULL, scope); scope++; }
#line 1904 "parser.tab.c"
    break;

  case 86: /* sub_header: "procedure" "id" formal_parameters  */
#line 255 "parser.y"
                                                                                { hashtbl_insert(hashtbl, (yyvsp[-1].strval), NULL, scope); scope++; }
#line 1910 "parser.tab.c"
    break;

  case 87: /* sub_header: "function" "id"  */
#line 256 "parser.y"
                                                                                { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); scope++; }
#line 1916 "parser.tab.c"
    break;

  case 88: /* sub_header: "function" error "id" formal_parameters ":" standard_type  */
#line 257 "parser.y"
                                                                                { yyerrok; }
#line 1922 "parser.tab.c"
    break;

  case 89: /* sub_header: "function" "id" formal_parameters error ":" standard_type  */
#line 258 "parser.y"
                                                                                { yyerrok; }
#line 1928 "parser.tab.c"
    break;

  case 91: /* formal_parameters: %empty  */
#line 262 "parser.y"
                           {}
#line 1934 "parser.tab.c"
    break;

  case 95: /* pass: %empty  */
#line 270 "parser.y"
                           {}
#line 1940 "parser.tab.c"
    break;

  case 108: /* statement: %empty  */
#line 289 "parser.y"
                           {}
#line 1946 "parser.tab.c"
    break;

  case 111: /* $@3: %empty  */
#line 296 "parser.y"
                                           {scope++;}
#line 1952 "parser.tab.c"
    break;

  case 112: /* $@4: %empty  */
#line 296 "parser.y"
                                                                {hashtbl_get(hashtbl, scope); scope--;}
#line 1958 "parser.tab.c"
    break;

  case 114: /* $@5: %empty  */
#line 299 "parser.y"
                           {scope++;}
#line 1964 "parser.tab.c"
    break;

  case 115: /* if_tail: "else" $@5 statement  */
#line 299 "parser.y"
                                                {hashtbl_get(hashtbl, scope); scope--;}
#line 1970 "parser.tab.c"
    break;

  case 116: /* if_tail: %empty  */
#line 300 "parser.y"
                                                 {}
#line 1976 "parser.tab.c"
    break;

  case 121: /* single_case: %empty  */
#line 310 "parser.y"
                           {}
#line 1982 "parser.tab.c"
    break;

  case 125: /* label: sign "id"  */
#line 318 "parser.y"
                                                                        { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 1988 "parser.tab.c"
    break;

  case 127: /* case_tail: %empty  */
#line 322 "parser.y"
                           {}
#line 1994 "parser.tab.c"
    break;

  case 128: /* $@6: %empty  */
#line 325 "parser.y"
                                            {scope++;}
#line 2000 "parser.tab.c"
    break;

  case 129: /* while_statement: "while" expression "do" $@6 statement  */
#line 325 "parser.y"
                                                                 {hashtbl_get(hashtbl, scope); scope--;}
#line 2006 "parser.tab.c"
    break;

  case 130: /* $@7: %empty  */
#line 328 "parser.y"
                                                        {scope++;}
#line 2012 "parser.tab.c"
    break;

  case 131: /* for_statement: "for" "id" ":=" iter_space "do" $@7 statement  */
#line 328 "parser.y"
                                                                                { hashtbl_insert(hashtbl, (yyvsp[-5].strval), NULL, scope); hashtbl_get(hashtbl, scope); scope--; }
#line 2018 "parser.tab.c"
    break;

  case 134: /* $@8: %empty  */
#line 335 "parser.y"
                                         {scope++;}
#line 2024 "parser.tab.c"
    break;

  case 135: /* with_statement: "with" variable "do" $@8 statement  */
#line 335 "parser.y"
                                                              {hashtbl_get(hashtbl, scope); scope--;}
#line 2030 "parser.tab.c"
    break;

  case 136: /* subprogram_call: "id"  */
#line 338 "parser.y"
                                                                        { hashtbl_insert(hashtbl, (yyvsp[0].strval), NULL, scope); }
#line 2036 "parser.tab.c"
    break;

  case 137: /* subprogram_call: "id" "(" expressions ")"  */
#line 339 "parser.y"
                                                                        { hashtbl_insert(hashtbl, (yyvsp[-3].strval), NULL, scope); }
#line 2042 "parser.tab.c"
    break;


#line 2046 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= T_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == T_EOF)
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 362 "parser.y"


int main(int argc, char* argv[]) {
    
    if(!(hashtbl = hashtbl_create(10, NULL))){
        perror("Could not create hashtbl!\n");
        exit(1);
    }


    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            printf("Could not open file!\n", argv[1]);
            exit(1);
        }
    }

    printf("\n[Line 1]\n");
    yyparse();
    
    hashtbl_get(hashtbl, scope);
    hashtbl_destroy(hashtbl);

    fclose(yyin);

    if(error_count > 0){
        printf("Syntax Analysis failed due to %d errors\n", error_count);
    }else{
        printf("Syntax Analysis completed successfully\n");
    }

    exit(0);

}

