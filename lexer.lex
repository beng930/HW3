%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "truthval.tab.hpp"


static void show_error(char * token);

%}

%option yylineno
%option noyywrap

relop                           (==|!=|<|>|<=|>=)
binop                           (\+|\-|\*|\/)
id                              ([a-zA-Z][a-zA-Z0-9]*)
num                             (0|[1-9][0-9]*)
string                          (\"([^\n\r\"\\]|\\[rnt"\\])+\")
white_space                     ([\r\n\t ])

%%

void                            return VOID;
int                             return INT;
byte                            return BYTE;
b                               return B;
bool                            return BOOL;
and                             return AND;
or                              return OR;
not                             return NOT;
true                            return TRUE;
false                           return FALSE;
return                          return RETURN;
if                              return IF;
else                            return ELSE;
while                           return WHILE;
break                           return BREAK;
continue                        return CONTINUE;
@pre                            return PRECOND;
;                               return SC;
,                               return COMMA;
\(                              return LPAREN;
\)                              return RPAREN;
\{                              return LBRACE;
\}                              return RBRACE;
=                               return ASSIGN;
{relop}                         return RELOP;
{binop}                         return BINOP;
{id}                            return ID;
{num}                           return NUM;
{string}                        return STRING;

\/\/[^\r\n]*[\r|\n|\r\n]?       ;
{white_space}                   ;

.                               show_error(yytext);

%%

static void show_error(char * token) {
  printf("Error %s\n", token);
  exit(0);
}

