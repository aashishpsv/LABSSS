%{
int vow = 0;
int con = 0;
%}
%%
[a,e,i,o,u,A,E,I,O,U] {vow++;}
[a-zA-Z] {con++;}

%%
main(int argc, char **argv)
{
yylex();
printf("%d %d\n",con,vow); }
int yywrap()
{
return 1;
}