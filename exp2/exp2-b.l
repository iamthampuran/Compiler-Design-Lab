%{
    #include<stdio.h>
    int vowel = 0, cons = 0;
%}

%%
[AEIOUaeiou] {vowel++;}
[A-Z|a-z]   {cons++;}
%%

int yywrap(){}

void main()
{
    yyin = fopen("text.txt","r");
    yylex();
    printf("\nNo of vowels: %d",vowel);
    printf("\nNo of consonants: %d\n",cons);
}