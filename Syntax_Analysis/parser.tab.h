/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    T_EOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_PROGRAM = 258,               /* "program"  */
    T_CONST = 259,                 /* "const"  */
    T_TYPE = 260,                  /* "type"  */
    T_ARRAY = 261,                 /* "array"  */
    T_LIST = 262,                  /* "list"  */
    T_SET = 263,                   /* "set"  */
    T_OF = 264,                    /* "of"  */
    T_RECORD = 265,                /* "record"  */
    T_VAR = 266,                   /* "var"  */
    T_FUNCTION = 267,              /* "function"  */
    T_PROCEDURE = 268,             /* "procedure"  */
    T_INTEGER = 269,               /* "integer"  */
    T_REAL = 270,                  /* "real"  */
    T_BOOLEAN = 271,               /* "boolean"  */
    T_CHAR = 272,                  /* "char"  */
    T_FORWARD = 273,               /* "forward"  */
    T_LENGTH = 274,                /* "length"  */
    T_NEW = 275,                   /* "new"  */
    T_BEGIN = 276,                 /* "begin"  */
    T_END = 277,                   /* "end"  */
    T_IF = 278,                    /* "if"  */
    T_THEN = 279,                  /* "then"  */
    T_ELSE = 280,                  /* "else"  */
    T_WHILE = 281,                 /* "while"  */
    T_DO = 282,                    /* "do"  */
    T_CASE = 283,                  /* "case"  */
    T_OTHERWISE = 284,             /* "otherwise"  */
    T_FOR = 285,                   /* "for"  */
    T_TO = 286,                    /* "to"  */
    T_DOWNTO = 287,                /* "downto"  */
    T_WITH = 288,                  /* "with"  */
    T_READ = 289,                  /* "read"  */
    T_WRITE = 290,                 /* "write"  */
    T_ID = 291,                    /* "id"  */
    T_STRING = 292,                /* "string"  */
    T_LISTFUNC = 293,              /* "listfunc"  */
    T_ICONST = 294,                /* "integer constant"  */
    T_RCONST = 295,                /* "real constant"  */
    T_BCONST = 296,                /* "boolean constant"  */
    T_CCONST = 297,                /* "char constant"  */
    T_RELOP = 298,                 /* "> or >= or < or <= or <>"  */
    T_ADDOP = 299,                 /* "+ or -"  */
    T_OROP = 300,                  /* "OR"  */
    T_MULDIVANDOP = 301,           /* "* or / or DIV or AND or MOD"  */
    T_NOTOP = 302,                 /* "NOT"  */
    T_INOP = 303,                  /* "IN"  */
    T_LPAREN = 304,                /* "("  */
    T_RPAREN = 305,                /* ")"  */
    T_SEMI = 306,                  /* ";"  */
    T_DOT = 307,                   /* "."  */
    T_COMMA = 308,                 /* ","  */
    T_EQU = 309,                   /* "="  */
    T_COLON = 310,                 /* ":"  */
    T_LBRACK = 311,                /* "["  */
    T_RBRACK = 312,                /* "]"  */
    T_ASSIGN = 313,                /* ":="  */
    T_DOTDOT = 314,                /* ".."  */
    LOWER_THAN_ELSE = 315          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 23 "parser.y"

    char *strval;
    char charval;
    int intval;
    double realval;

#line 131 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
