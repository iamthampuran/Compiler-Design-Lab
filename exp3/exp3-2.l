%{
#include<stdio.h>
#include "y.tab.c"
%}
%%
[_|a-z|A-Z][_|a-z|A-Z|0-9]* {return identifier;}
[\t] ;
[\n] return 0;
. return yytext[0];
%%
yywrap()
{}
