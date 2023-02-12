%{
	#include<stdio.h>
	#include<stdlib.h>
	#include "y.tab.c"
	extern int yylval;
%}
%%
[0-9]+ {
		yylval=atoi(yytext);
		return NUMBER;
	  }
[\t] ;
[\n] return 0;
. return yytext[0];
%%
int yywrap() {}