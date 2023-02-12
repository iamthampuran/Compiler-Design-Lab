%{
	#include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
%}
%token NUMBER
%token id
%left '+' '-' 
%left '*' '/' 
%left '%'
%%
ArithmeticExpression: E {printf("\nVALID\n",$$);};
E: E'+'E 
| E'-'E 
| E'*'E 
| E'/'E 
| E'%'E 
| NUMBER
|id 
%%
void main()
{
    printf("\nEnter the expresssion:");
    yyparse();
}
void yyerror()
{
    printf("\nerror\n");   
}