%{
#include "q3.tab.h"
%}
%%
"+" {return ADD;}
"-" {return SUB;}
"*" {return MUL;}
"/" {return DIV;}
[0-9]+ {yylval = atoi(yytext); return NUM;}
"\n" {return EOL;}
. {return yytext[0];}
";" {return SC;}
%%
int yywrap(){return 1;}