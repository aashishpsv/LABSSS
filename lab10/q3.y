%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
int result;
%}
%token ADD SUB MUL DIV NUM SC EOL
%%
program: expr {printf("Result: %d\n", result);}
;
expr: term {result = $1;}
| term ADD term {result = $1 + $3;}
| term SUB term {result = $1 - $3;}
;
term: factor {result = $1;}
| factor MUL factor {result = $1 * $3;}
| factor DIV factor {result = $1 / $3;}
;
factor:NUM {result = $1;}
;
%%
int yyerror(char * msg)
{
 if (msg != NULL) {
        printf("Invalid arithmetic expression!\n");
    }
    return 1;
}
int main()
{
printf("Enter arithmetic expression:\n");
yyparse();
}
