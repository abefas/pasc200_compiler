%{
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
%}

%define parse.error verbose

%union {
    char *strval;
    char charval;
    int intval;
    double realval;
}


%token  <strval>    T_PROGRAM   "program"
%token  <strval>    T_CONST     "const"
%token  <strval>    T_TYPE      "type"
%token  <strval>    T_ARRAY     "array"
%token  <strval>    T_LIST      "list"
%token  <strval>    T_SET       "set"
%token  <strval>    T_OF        "of"
%token  <strval>    T_RECORD    "record"
%token  <strval>    T_VAR       "var"
%token  <strval>    T_FUNCTION  "function"
%token  <strval>    T_PROCEDURE "procedure"
%token  <strval>    T_INTEGER   "integer"
%token  <strval>    T_REAL      "real"
%token  <strval>    T_BOOLEAN   "boolean"
%token  <strval>    T_CHAR      "char"
%token  <strval>    T_FORWARD   "forward"
%token  <strval>    T_LENGTH    "length"
%token  <strval>    T_NEW       "new"
%token  <strval>    T_BEGIN     "begin"
%token  <strval>    T_END       "end"
%token  <strval>    T_IF        "if"
%token  <strval>    T_THEN      "then"
%token  <strval>    T_ELSE      "else"
%token  <strval>    T_WHILE     "while"
%token  <strval>    T_DO        "do"
%token  <strval>    T_CASE      "case"
%token  <strval>    T_OTHERWISE "otherwise"
%token  <strval>    T_FOR       "for"
%token  <strval>    T_TO        "to"
%token  <strval>    T_DOWNTO    "downto"
%token  <strval>    T_WITH      "with"
%token  <strval>    T_READ      "read"
%token  <strval>    T_WRITE     "write"


%token  <strval>    T_ID        "id"
%token  <strval>    T_STRING    "string"
%token  <strval>    T_LISTFUNC  "listfunc"

%token  <intval>    T_ICONST    "integer constant"
%token  <realval>   T_RCONST    "real constant"
%token  <strval>    T_BCONST    "boolean constant"
%token  <charval>   T_CCONST    "char constant"


%token  <strval>    T_RELOP         "> or >= or < or <= or <>"
%token  <strval>    T_ADDOP         "+ or -"
%token  <strval>    T_OROP          "OR"
%token  <strval>    T_MULDIVANDOP   "* or / or DIV or AND or MOD"
%token  <strval>    T_NOTOP         "NOT"
%token  <strval>    T_INOP          "IN"

%token  <strval>    T_LPAREN    "("
%token  <strval>    T_RPAREN    ")"
%token  <strval>    T_SEMI      ";"
%token  <strval>    T_DOT       "."
%token  <strval>    T_COMMA     ","
%token  <strval>    T_EQU       "="
%token  <strval>    T_COLON     ":"
%token  <strval>    T_LBRACK    "["
%token  <strval>    T_RBRACK    "]"
%token  <strval>    T_ASSIGN    ":="
%token  <strval>    T_DOTDOT    ".."

%token  <strval>    T_EOF   0   "end of file"

%type <strval> program header declarations constdefs constant_defs expression variable expressions
%type <strval> setlistexpression typedefs type_defs type_def dims limits limit sign typename
%type <strval> standard_type fields field identifiers vardefs variable_defs subprograms subprogram
%type <strval> sub_header formal_parameters parameter_list pass comp_statement statements statement
%type <strval> assignment if_statement if_tail case_statement cases single_case label_list label
%type <strval> case_tail while_statement for_statement iter_space with_statement subprogram_call
%type <strval> io_statement read_list read_item write_list write_item
%type <strval> constant

%nonassoc   T_INOP T_RELOP T_EQU
%left       T_ADDOP T_OROP
%left       T_MULDIVANDOP
%precedence T_NOTOP
/*%left       T_DOT T_LBRACK T_RBRACK T_LPAREN T_RPAREN*/

%precedence LOWER_THAN_ELSE 
%precedence T_ELSE



%start      program

%%

program :   header declarations subprograms comp_statement T_DOT
        ;

header  :   T_PROGRAM T_ID T_SEMI                               { hashtbl_insert(hashtbl, $2, NULL, scope); }
        |   error T_PROGRAM T_ID T_SEMI                         { yyerrok; }
        |   T_PROGRAM error T_ID T_SEMI                         { yyerrok; }
        |   T_PROGRAM T_ID error T_SEMI                         { yyerrok; }
        ;

declarations  :   constdefs typedefs vardefs
              ;

constdefs     :   T_CONST constant_defs T_SEMI 
              |   T_CONST constant_defs error                   { yyerrok; }
              |   %empty {}
              ;

constant_defs :   constant_defs T_SEMI T_ID T_EQU expression    { hashtbl_insert(hashtbl, $3, NULL, scope); }
              |   T_ID T_EQU expression                         { hashtbl_insert(hashtbl, $2, NULL, scope); }
              ;

expression    :   expression T_RELOP expression
              |   expression T_EQU expression
              |   expression T_INOP expression
              |   expression T_OROP expression
              |   expression T_ADDOP expression
              |   expression T_MULDIVANDOP expression
              |   T_ADDOP expression
              |   T_NOTOP expression
              |   variable
              |   T_ID T_LPAREN expressions T_RPAREN        { hashtbl_insert(hashtbl, $1, NULL, scope); }
              |   T_LENGTH T_LPAREN expression T_RPAREN
              |   T_NEW T_LPAREN expression T_RPAREN  
              |   constant
              |   T_LPAREN expression T_RPAREN
              |   T_LPAREN expression error                 {yyerrok;}
              |   setlistexpression
              ;

variable      :   T_ID                                      { hashtbl_insert(hashtbl, $1, NULL, scope); }
              |   variable T_DOT T_ID                       { hashtbl_insert(hashtbl, $3, NULL, scope); }
              |   variable T_LBRACK expressions T_RBRACK
              |   T_LISTFUNC T_LPAREN expression T_RPAREN
              |   T_LISTFUNC T_LPAREN expression error      {yyerrok;}
              ;

expressions   :   expressions T_COMMA expression
              |   expression

constant      :   T_ICONST      { $<intval>$ = $1; }
              |   T_RCONST      { $<realval>$ = $1; } 
              |   T_BCONST
              |   T_CCONST      { $<charval>$ = $1; }
              ;

setlistexpression : T_LBRACK expressions T_RBRACK
                  | T_LBRACK T_RBRACK

typedefs      :   T_TYPE type_defs T_SEMI
              |   %empty {}
              ;

type_defs     :   type_defs T_SEMI T_ID T_EQU type_def          { hashtbl_insert(hashtbl, $3, NULL, scope); }
              |   T_ID T_EQU type_def                           { hashtbl_insert(hashtbl, $1, NULL, scope); }
              ;

type_def      :   T_ARRAY T_LBRACK dims T_RBRACK T_OF typename
              |   T_ARRAY T_LBRACK dims error T_OF typename     {yyerrok;}
              |   T_LIST T_OF typename
              |   T_SET T_OF typename
              |   T_RECORD {scope++;} fields {hashtbl_get(hashtbl, scope); scope--;} T_END
              |   limit T_DOTDOT limit
              ;

dims          :   dims T_COMMA limits
              |   limits
              ;

limits        :   limit T_DOTDOT limit
              |   T_ID                                          { hashtbl_insert(hashtbl, $1, NULL, scope); }
              ;

limit         :   sign T_ICONST
              |   T_CCONST                                      { $<charval>$ = $1; }
              |   T_BCONST
              |   T_ADDOP T_ID                                  { hashtbl_insert(hashtbl, $2, NULL, scope); }
              |   T_ID                                          { hashtbl_insert(hashtbl, $1, NULL, scope); }
              ;

sign          :   T_ADDOP
              |   %empty {}
              ;

typename      :   standard_type
              |   T_ID                                          { hashtbl_insert(hashtbl, $1, NULL, scope); }
              ;

standard_type :   T_INTEGER
              |   T_REAL
              |   T_BOOLEAN
              |   T_CHAR
              ;

fields        :   fields T_SEMI field
              |   field
              ;

field         :   identifiers T_COLON typename
              ;

identifiers   :   identifiers T_COMMA T_ID                      { hashtbl_insert(hashtbl, $3, NULL, scope); }
              |   T_ID                                          { hashtbl_insert(hashtbl, $1, NULL, scope); }
              ;              

vardefs       :   T_VAR variable_defs T_SEMI
              |   %empty {}
              ;

variable_defs :   variable_defs T_SEMI identifiers T_COLON typename
              |   identifiers T_COLON typename
              ;



subprograms   :   subprograms subprogram T_SEMI                                 {hashtbl_get(hashtbl, scope); scope--;}
              |   %empty {}
              ;

subprogram    :   sub_header T_SEMI T_FORWARD                                   
              |   sub_header T_SEMI declarations subprograms comp_statement     
              ;

sub_header    :   T_FUNCTION T_ID formal_parameters T_COLON standard_type       { hashtbl_insert(hashtbl, $2, NULL, scope); scope++; }
              |   T_FUNCTION T_ID formal_parameters T_COLON T_LIST              { hashtbl_insert(hashtbl, $2, NULL, scope); scope++; } 
              |   T_PROCEDURE T_ID formal_parameters                            { hashtbl_insert(hashtbl, $2, NULL, scope); scope++; }
              |   T_FUNCTION T_ID                                               { hashtbl_insert(hashtbl, $2, NULL, scope); scope++; }
              |   T_FUNCTION error T_ID formal_parameters T_COLON standard_type { yyerrok; }
              |   T_FUNCTION T_ID formal_parameters error T_COLON standard_type { yyerrok; }
              ;

formal_parameters : T_LPAREN parameter_list T_RPAREN
                  | %empty {}
                  ;

parameter_list    : parameter_list T_SEMI pass identifiers T_COLON typename
                  | pass identifiers T_COLON typename
                  ;

pass              : T_VAR
                  | %empty {}
                  ;

comp_statement    : T_BEGIN statements T_END       
                  ;

statements        : statements T_SEMI statement
                  | statement
                  ;

statement         : assignment
                  | if_statement
                  | case_statement
                  | while_statement
                  | for_statement
                  | with_statement
                  | subprogram_call
                  | io_statement
                  | comp_statement
                  | %empty {}
                  ;

assignment        : variable T_ASSIGN expression
                  | variable T_ASSIGN T_STRING
                  ;

if_statement      : T_IF expression T_THEN {scope++;} statement {hashtbl_get(hashtbl, scope); scope--;} if_tail 
                  ;

if_tail           : T_ELSE {scope++;} statement {hashtbl_get(hashtbl, scope); scope--;}
                  | %empty %prec LOWER_THAN_ELSE {}
                  ;

case_statement    : T_CASE expression T_OF cases case_tail T_END
                  ;

cases             : cases T_SEMI single_case
                  | single_case

single_case       : label_list T_COLON statement
                  | %empty {}
                  ;

label_list        : label_list T_COMMA label
                  | label 
                  ;

label             : sign constant 
                  | sign T_ID                                           { hashtbl_insert(hashtbl, $2, NULL, scope); }
                  ;

case_tail         : T_SEMI T_OTHERWISE T_COLON statement
                  | %empty {}
                  ;

while_statement   : T_WHILE expression T_DO {scope++;} statement {hashtbl_get(hashtbl, scope); scope--;}
                  ;

for_statement     : T_FOR T_ID T_ASSIGN iter_space T_DO {scope++;} statement    { hashtbl_insert(hashtbl, $2, NULL, scope); hashtbl_get(hashtbl, scope); scope--; }
                  ;

iter_space        : expression T_TO expression
                  | expression T_DOWNTO expression
                  ;

with_statement    : T_WITH variable T_DO {scope++;} statement {hashtbl_get(hashtbl, scope); scope--;}
                  ;                  

subprogram_call   : T_ID                                                { hashtbl_insert(hashtbl, $1, NULL, scope); }
                  | T_ID T_LPAREN expressions T_RPAREN                  { hashtbl_insert(hashtbl, $1, NULL, scope); }
                  ;

io_statement      : T_READ T_LPAREN read_list T_RPAREN
                  | T_WRITE T_LPAREN write_list T_RPAREN
                  ;

read_list         : read_list T_COMMA read_item
                  | read_item
                  ;

read_item         : variable
                  ;

write_list        : write_list T_COMMA write_item
                  | write_item
                  ;

write_item        : expression
                  | T_STRING
                  ;


%%

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

