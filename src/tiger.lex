%{
#define YY_NO_UNISTD_H

#include <string.h>
#include "util.h"
#include "errormsg.h"
#include "absyn.h"
#include "y.tab.h"

int charPos=1;

int yywrap(void) {
 charPos=1;
 return 1;
}

void adjust(void) {
 EM_tokPos=charPos;
 charPos+=yyleng;
}

%}

/* lex defintions */
id [A-Za-z]([A-Za-z0-9]|"_")*


%x COMMENT
%%

"/*"          { BEGIN(COMMENT);}
<COMMENT>"*/" { BEGIN(INITIAL);}
<COMMENT>\n   { }
<COMMENT>.    { }

" "    {adjust(); continue;}
\t     {adjust(); continue;}
(\n|\r\n) {adjust(); EM_newline(); continue;}
","    {adjust(); return COMMA;}
":"    {adjust(); return COLON;}
";"    {adjust(); return SEMICOLON;}
"("    {adjust(); return LPAREN;}
")"    {adjust(); return RPAREN;}
"["    {adjust(); return LBRACK;}
"]"    {adjust(); return RBRACK;}
"{"    {adjust(); return LBRACE;}
"}"    {adjust(); return RBRACE;}
"."    {adjust(); return DOT;}
"+"    {adjust(); return PLUS;}
"-"    {adjust(); return MINUS;}
"*"    {adjust(); return TIMES;}
"/"    {adjust(); return DIVIDE;}
"="    {adjust(); return EQ;}
"<>"   {adjust(); return NEQ;}
"<"    {adjust(); return LT;}
"<="   {adjust(); return LE;}
">"    {adjust(); return GT;}
">="   {adjust(); return GE;}
"&"    {adjust(); return AND;}
"|"    {adjust(); return OR;}
":="   {adjust(); return ASSIGN;}
while    {adjust(); return WHILE;}
for      {adjust(); return FOR;}
array    {adjust(); return ARRAY;}
if       {adjust(); return IF;}
then     {adjust(); return THEN;}
else     {adjust(); return ELSE;}
to       {adjust(); return TO;}
do       {adjust(); return DO;}
let      {adjust(); return LET;}
in       {adjust(); return IN;}
end      {adjust(); return END;}
of       {adjust(); return OF;}
break    {adjust(); return BREAK;}
nil      {adjust(); return NIL;}
function {adjust(); return FUNCTION;}
var      {adjust(); return VAR;}
type     {adjust(); return TYPE;}

{id}               {adjust(); yylval.sval=yytext; return ID;}
\"(\\.|[^\\\"])*\" {adjust(); yylval.str.sval=yytext; yylval.str.ssiz=yyleng; return STRING;}
[0-9]+             {adjust(); yylval.ival=atoi(yytext); return INT;}
.                  {adjust(); EM_error(EM_tokPos,"illegal token");}
