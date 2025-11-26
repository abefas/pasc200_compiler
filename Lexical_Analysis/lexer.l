%{
#define FLEX_DEBUG 0
#include "lexer.h"		//use to run flex standalone
//include "syntax.tab.h" //use this after compiling bison
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int lineno=1;
int error_count=0;
char str_buffer[256]; //restrict strings to 256 chars
char *s;							//pointer to emulate fflush

void Keyword_Print(char* keyword_id);
void CCONST_Print(char* token);
void Token_Print(char* t);
void Number_Print(int base);
void Float_Print(int base);
int HexToInt(char* str);
int BinToInt(char* str);
float HexToFloat(char* str);
float BinToFloat(char* str);
void yyerror(char* err);
%}

%option case-insensitive
%option yylineno
%option noyywrap

%x COMMENT
%x STRING

LETTER 			[a-zA-Z]
DIGIT 			[0-9]
CHARACTER 		({LETTER}|{DIGIT})
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
"LIST"							{Keyword_Print("LIST"); return T_LIST;}
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

C(AD*|D+)R                      {printf("Found LISTFUNC -> %s",yytext); return T_LIST;}

">"|">="|"<"|"<="|"<>"			{Token_Print("RELOP"); return T_RELOP;}
"+"|"-"							{Token_Print("ADDOP"); return T_ADDOP;}
"*"|"/"|"DIV"|"MOD"|"AND"		{Token_Print("MULDIVANDOP"); return T_MULDIVANDOP;}

{ID}							{Token_Print("ID"); return T_ID;}




{NZNUMBER}|0									{Number_Print(10); return T_ICONST;}

0X{HEXNUMBER}									{Number_Print(16); return T_ICONST;}

0B1{BINDIGIT}*                                  {Number_Print(2); return T_ICONST;}


{NZNUMBER}?\.({DIGIT}*[1-9]|0){EXPONENT}?		{Float_Print(10); return T_RCONST;}

[1-9]{DIGIT}*{EXPONENT}							{Float_Print(10); return T_RCONST;}

0X{HEXNUMBER}?\.({HEXDIGIT}*[1-9A-F]|0)			{Float_Print(16); return T_RCONST;}

0B(1{BINDIGIT}*)?\.(0*1+{BINDIGIT}*|0)          {Float_Print(2); return T_RCONST;}



\'.\'						{CCONST_Print(yytext); return T_CCONST;}
\'\\n\'						{CCONST_Print(yytext); return T_CCONST;}
\'\\t\'						{CCONST_Print(yytext); return T_CCONST;}
\'\\f\'						{CCONST_Print(yytext); return T_CCONST;}
\'\\r\'						{CCONST_Print(yytext); return T_CCONST;}
\'\\b\'						{CCONST_Print(yytext); return T_CCONST;}
\'\\v\'						{CCONST_Print(yytext); return T_CCONST;}


\"							{strcpy(str_buffer,""); BEGIN(STRING);}
<STRING>\"					{printf("\nSCONST -> %s\n",str_buffer); BEGIN(INITIAL); return (T_STRING);}
<STRING>\n					{yyerror("Illegal input in string"); exit(1);}
<STRING>\\\n				{}
<STRING>(\\.|[^"])			{strcat(str_buffer,yytext);}
<STRING><<EOF>>				{yyerror("EOF in String");}



"{"								{s=str_buffer; BEGIN(COMMENT);}
<COMMENT>[}]+					{*s='\0'; printf("\nFound Comment\n"); BEGIN(INITIAL);}
<COMMENT>[^}]*					{}




"("								{Token_Print("LPAREN"); return T_LPAREN;}
")"								{Token_Print("RPAREN"); return T_RPAREN;}
";"								{Token_Print("SEMI"); return T_SEMI;}
"."								{Token_Print("DOT"); return T_DOT;}
","								{Token_Print("COMMA"); return T_DOT;}
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

int main(int argc, char *argv[]){
	int token;
	yyin=fopen(argv[1],"r");
	if(yyin==NULL){
        perror("Error opening file!\n");
        return -1;
	}
	do{
		token = yylex();    //Read every word in file
	}while(token!=T_EOF);   //Until EOF
    fclose(yyin);
	return 0;
	}

void Keyword_Print(char* keyword_id){printf("\nKEYWORD -> %s\n",keyword_id);}

void Token_Print(char* token){printf("\nFound token %s -> %s\n",token,yytext);}

void CCONST_Print(char* token){printf("\nFound CCONST -> %s\n", token);}

int BinToInt(char *str){ return (int) strtol(&str[2], NULL, 2); }

int HexToInt(char *str){ return (int) strtol(&str[2], NULL, 16); }

float HexToFloat(char* str){
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

float BinToFloat(char* str){
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

void Float_Print(int base){
    float number;
    if(base==16){
		number=HexToFloat(yytext);
    }else if(base==2){
        number=BinToFloat(yytext);
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

void yyerror(char* msg){
	error_count++;
	printf("\n%s\n%d error(s) found with token %s in line %d",msg,error_count,yytext,yylineno);
		if(error_count==MAX_ERRORS){
			printf("Max errors detected");
			exit(-1);
		}
}
