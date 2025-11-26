%{
//include "lexer.h"		//use to run flex standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "parser.tab.h" 
#include "settings.h"

int error_count = 0;
char str_buffer[256]; //restrict strings to 256 chars
char *str_buf_ptr;
char cconst_buffer[3];
char *s;							//pointer to emulate fflush

void Keyword_Print(char *keyword_id);
void CCONST_Print(char *token);
void CCONST_Print1(char token);
void Token_Print(char *t);
void Number_Print(int base);
void double_print(int base);
int string_to_int(char *str);
int HexToInt(char *str);
int BinToInt(char *str);
float HexToDouble(char *str);
float BinToDouble(char *str);
void yyerror(const char *err);
%}

%option case-insensitive
%option yylineno
%option noyywrap

/* INITIAL STATES */
%x COMMENT
%x STRING

LETTER 			[a-zA-Z]
DIGIT 			[0-9]
CHARACTER 		({LETTER}|{DIGIT})
CHARACTER_      ({CHARACTER}|_)
NZNUMBER 		[1-9]{DIGIT}*
HEXDIGIT 		[0-9A-F]
BINDIGIT        [01]
HEXNUMBER		[1-9A-F]{HEXDIGIT}*
EXPONENT    	E[+-]?(0|{NZNUMBER})
ASCII 			[ !"#$%&'()*+,-./:;<=>?@\[\\\]^_`{|}~]]
SPACE			[ \t]
NEWLINE			[\n]
STR				({ASCII}|{LETTER}|{DIGIT}|{SPACE})+
ID 				\_?{LETTER}{CHARACTER}*(_{CHARACTER}+)*

%% //Separator

"PROGRAM"						{Keyword_Print("PROGRAM"); return T_PROGRAM;}
"CONST"							{Keyword_Print("CONST"); return T_CONST;}
"TYPE"							{Keyword_Print("TYPE"); return T_TYPE;}
"ARRAY"							{Keyword_Print("ARRAY"); return T_ARRAY;}
"LIST"						    {Keyword_Print("LIST"); return T_LIST;}
"SET"							{Keyword_Print("SET"); return T_SET;}
"OF"							{Keyword_Print("OF"); return T_OF;}
"RECORD"						{Keyword_Print("RECORD"); return T_RECORD;}
"VAR"							{Keyword_Print("VAR"); return T_VAR;}
"FUNCTION"						{Keyword_Print("FUNCTION"); return T_FUNCTION;}
"PROCEDURE"						{Keyword_Print("PROCEDURE"); return T_PROCEDURE;}
"INTEGER"						{Keyword_Print("INTEGER"); return T_INTEGER;}
"REAL"							{Keyword_Print("REAL"); return T_REAL;}
"BOOLEAN"						{Keyword_Print("BOOLEAN"); return T_BOOLEAN;}
"CHAR"							{Keyword_Print("CHAR"); return T_CHAR;}
"FORWARD"						{Keyword_Print("FORWARD"); return T_FORWARD;}
"LENGTH"						{Keyword_Print("LENGTH"); return T_LENGTH;}
"NEW"							{Keyword_Print("NEW"); return T_NEW;}
"BEGIN"							{Keyword_Print("BEGIN"); return T_BEGIN;}
"END"							{Keyword_Print("END"); return T_END;}
"IF"							{Keyword_Print("IF"); return T_IF;}
"THEN"							{Keyword_Print("THEN"); return T_THEN;}
"ELSE"							{Keyword_Print("ELSE"); return T_ELSE;}
"WHILE"							{Keyword_Print("WHILE"); return T_WHILE;}
"DO"							{Keyword_Print("DO"); return T_DO;}
"CASE"							{Keyword_Print("CASE"); return T_CASE;}
"OTHERWISE"						{Keyword_Print("OTHERWISE"); return T_OTHERWISE;}
"FOR"							{Keyword_Print("FOR"); return T_FOR;}
"TO"							{Keyword_Print("TO"); return T_TO;}
"DOWNTO"						{Keyword_Print("DOWNTO"); return T_DOWNTO;}
"WITH"							{Keyword_Print("WITH"); return T_WITH;}
"READ"							{Keyword_Print("READ"); return T_READ;}
"WRITE"							{Keyword_Print("WRITE"); return T_WRITE;}


"OR"							{Token_Print("OROP"); return T_OROP;}
"NOT"							{Token_Print("NOTOP"); return T_NOTOP;}
"IN"							{Token_Print("INOP"); return T_INOP;}


"TRUE"|"FALSE"				    {printf("Found BOOLEAN -> %s",yytext); return T_BCONST;}

C(AD*|D+)R                      {printf("Found LISTFUNC -> %s",yytext); return T_LISTFUNC;}

">"|">="|"<"|"<="|"<>"			{Token_Print("RELOP"); return T_RELOP;}
"+"|"-"							{Token_Print("ADDOP"); return T_ADDOP;}
"*"|"/"|"DIV"|"MOD"|"AND"		{Token_Print("MULDIVANDOP"); return T_MULDIVANDOP;}

<INITIAL><<EOF>>                {Token_Print("T_EOF"); yylval.strval = strdup(yytext); return T_EOF;}

{ID}							{Token_Print("ID"); yylval.strval = strdup(yytext); return T_ID;}




(0|{NZNUMBER})?\.({DIGIT}*[1-9]|0){EXPONENT}?		{double_print(10); yylval.realval = atof(yytext); return T_RCONST;}

[1-9]{DIGIT}*{EXPONENT}							{double_print(10); yylval.realval = atof(yytext); return T_RCONST;}

0X{HEXNUMBER}?\.({HEXDIGIT}*[1-9A-F]|0)			{double_print(16); yylval.realval = HexToDouble(yytext); return T_RCONST;}

0B(1{BINDIGIT}*)?\.(0*1+{BINDIGIT}*|0)          {double_print(2); yylval.realval = BinToDouble(yytext); return T_RCONST;}

{NZNUMBER}|0									{Number_Print(10); yylval.intval = atoi(yytext); return T_ICONST;}

0X{HEXNUMBER}									{Number_Print(16); yylval.intval = HexToInt(yytext); return T_ICONST;}

0B1{BINDIGIT}*                                  {Number_Print(2); yylval.intval = BinToInt(yytext); return T_ICONST;}


\'\\n\'						{strcpy(cconst_buffer, "\\n"); CCONST_Print(cconst_buffer); yylval.strval = strdup(cconst_buffer); return T_CCONST;}
\'\\f\'						{strcpy(cconst_buffer, "\\f"); CCONST_Print(cconst_buffer); yylval.strval = strdup(cconst_buffer); return T_CCONST;}
\'\\t\'					    {strcpy(cconst_buffer, "\\t"); CCONST_Print(cconst_buffer); yylval.strval = strdup(cconst_buffer); return T_CCONST;}	
\'\\r\'						{strcpy(cconst_buffer, "\\r"); CCONST_Print(cconst_buffer); yylval.strval = strdup(cconst_buffer); return T_CCONST;}
\'\\b\'						{strcpy(cconst_buffer, "\\b"); CCONST_Print(cconst_buffer); yylval.strval = strdup(cconst_buffer); return T_CCONST;}
\'\\v\'						{strcpy(cconst_buffer, "\\v"); CCONST_Print(cconst_buffer); yylval.strval = strdup(cconst_buffer); return T_CCONST;}

\'{ASCII}\'					{CCONST_Print1(yytext[1]); yylval.charval = yytext[1]; return T_CCONST;}
\'{CHARACTER}\'             {CCONST_Print1(yytext[1]); yylval.charval = yytext[1]; return T_CCONST;}


\"							{BEGIN(STRING); str_buf_ptr = str_buffer;}
<STRING>\"					{BEGIN(INITIAL); *str_buf_ptr = '\0';
                                yylval.strval = strdup(str_buffer); 
                                printf("\nFound String -> %s | TOKEN NUMBER: %d | LINE: %d\n", str_buffer, T_STRING, yylineno);
                                return (T_STRING);}
<STRING>\n					{yyerror("Illegal input in string"); exit(1);}
<STRING>\\n                 {*str_buf_ptr++ = '\n';}
<STRING>\\f                 {*str_buf_ptr++ = '\f';}
<STRING>\\t                 {*str_buf_ptr++ = '\t';}
<STRING>\\r                 {*str_buf_ptr++ = '\r';}
<STRING>\\b                 {*str_buf_ptr++ = '\b';}
<STRING>\\v                 {*str_buf_ptr++ = '\v';}
<STRING>\\\\                {*str_buf_ptr++ = '\\';}
<STRING>\\\"                {*str_buf_ptr++ = '"';}
<STRING>\\\n				{ printf("\nMultiple line string!\n"); } 
<STRING>\\{CHARACTER_}?     {*str_buf_ptr++ = yytext[1];}
<STRING>[^\\\n\"]+          {char *yptr = yytext;
                                while(*yptr) *str_buf_ptr++ = *yptr++;
                            }
<STRING><<EOF>>				{yyerror("EOF in String"); exit(1);}




"{"								{s=str_buffer; BEGIN(COMMENT);}
<COMMENT>[}]+					{*s='\0'; printf("\nFound Comment\n"); BEGIN(INITIAL);}
<COMMENT>"\n"                   { printf("\nMultiple line Comment!\n"); }
<COMMENT>[^\n}]*				{}




"("								{Token_Print("LPAREN"); return T_LPAREN;}
")"								{Token_Print("RPAREN"); return T_RPAREN;}
";"								{Token_Print("SEMI"); return T_SEMI;}
"."								{Token_Print("DOT"); return T_DOT;}
","								{Token_Print("COMMA"); return T_COMMA;}
"="								{Token_Print("EQU"); return T_EQU;}
":"								{Token_Print("COLON"); return T_COLON;}
"["								{Token_Print("LBRACK"); return T_LBRACK;}
"]"								{Token_Print("RBRACK"); return T_RBRACK;}
":="							{Token_Print("ASSIGN"); return T_ASSIGN;}
".."							{Token_Print("DOTDOT"); return T_DOTDOT;}

\n							{printf("\n[Line %d]\n",yylineno);}
{SPACE}						{}
.							{yyerror("Unrecognised character");}
<<EOF>>						{printf("\nEOF\n"); return T_EOF;}


%% //Separator

void Keyword_Print(char *keyword_id){printf("\nKEYWORD -> %s\n",keyword_id);}

void Token_Print(char *token){printf("\nFound token %s -> %s\n",token,yytext);}

void CCONST_Print(char *token){printf("\nFound CCONST -> %s\n", token);}

void CCONST_Print1(char token){printf("\nFound CCONST -> %c\n", token);}

int BinToInt(char *str){ return (int) strtol(&str[2], NULL, 2); }

int HexToInt(char *str){ return (int) strtol(&str[2], NULL, 16); }

float HexToDouble(char* str){
    float number = 0.0;
    int i,length_real;
    char *character;
    character = strchr(str,'.');
    length_real = strlen(character)-1;
    number = (int)strtol(&str[2],&character,16);
    for(i=1;i<=length_real;i++){
        if(character[i] <= '9'){
            number += (character[i] - '0') * (1/pow(16,i));
        }else{
            number += (character[i] + 10 - 'A') * (1/pow(16,i)); /** TODO: CASE SENSITIVE **/
        }
    }
    return number;
}

float BinToDouble(char* str){
    float number = 0.0;
    int i,length_real;
    char *character;
    character = strchr(str,'.');
    length_real = strlen(character)-1;
    number = (int)strtol(&str[2],&character,2);
    for(i=1;i<length_real;i++){
        number += (character[i] - '0') * (1/pow(2,i));
    }
    return number;
}

void double_print(int base){
    float number;
    if(base==16){
		number=HexToDouble(yytext);
    }else if(base==2){
        number=BinToDouble(yytext);
    }else{
		number=atof(yytext);
	}
    printf("\nRCONST FOUND: %lf (%s)\n",number,yytext);
}

void Number_Print(int base){
	int number;
    if(base==16){
		number=HexToInt(yytext);
    }else if(base==2){
        number=BinToInt(yytext);
    }else{
		number=atoi(yytext);
	}
	printf("\nICONST FOUND: %d (%s)\n",number,yytext);
}

void yyerror(const char* err) {

    error_count++;

    fprintf(stderr, "\n[ERROR - Line %d]: %s\n", yylineno, err);

    if (error_count == MAX_ERRORS) {
        printf("\nError count limit reached. Exiting...\n");
        fprintf(stderr, "\nError limit reached!\n");
        exit(EXIT_FAILURE);
    }

}
