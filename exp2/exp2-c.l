%{
    #include<stdio.h>
%}
letter [A-Z|a-z]
digit [0-9]

%%
"#" {printf("\n%s is a preprocessor directive",yytext);}
"void"|"main"|"int"|"float"|"char"|"double"|"if"|"else"|"for"|"switch"|"while"|"#include"|"stdio.h"|"printf"|"scanf"  {printf("\n%s is a keyword",yytext);}
("_"|{letter})({letter}|{digit})*   {printf("\n%s is a valid identifier",yytext);}
"-"|"+"|"*"|"/"|"%"|"^"|"="     {printf("\n%s is an operator",yytext);}
"{"|"}"|","|";"|")"|"("|"\""    {printf("\n%s is a punctuator",yytext);}
">="|"<="|"=="|"<"|">"      {printf("\n%s is a relational operator",yytext);}
({digit})({digit})*         {printf("\n%s is a digit",yytext);}
("_"|{letter}|{digit})*     {printf("\n%s is not a valid identifier",yytext);}

%%

int yywrap(){}

void main()
{
    yyin = fopen("lex.txt","r");
    yylex();
    printf("\n");
}