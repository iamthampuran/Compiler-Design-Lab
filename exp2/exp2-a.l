%{
    #include<stdio.h>
    int line = 0, word = 0, chars = 0;

%}

%%
[A-Z|a-z|0-9] {chars++;}
["\n"]+ {line+=1;word++;}
[" "]+ {word++;}
%%

int yywrap(){}

void main()
{
    yyin = fopen("input.txt","r");
    yylex();
    printf("No of words = %d\nNo of characters = %d\nNo of lines = %d\n",word,chars,line+1);
}