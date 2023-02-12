%{
	#include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
%}
%token NUMBER
%left '+' '-' 
%left '*' '/' 
%left '%'
%%
ArithmeticExpression: E {printf("\nResult=%d\n",$$);};
E: E'+'E {$$=$1+$3;}
| E'-'E {$$=$1-$3;}
| E'*'E {$$=$1*$3;}
| E'/'E {$$=$1/$3;}
| E'%'E {$$=$1%$3;}
| NUMBER {$$=$1;};
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