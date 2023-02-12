%{
#include<stdio.h>
#include<stdlib.h>
#include "y.tab.h"
%}
%token identifier
%%
ArithmeticExpression: E {printf("\n It is a Valid identfier\n");};
E: identifier 
;
%%
void main()
{
printf("\n Enter the identfier:  \n");
yyparse();
}
yyerror()
{
printf("\n It is an Invalid identifier\n");
}