#include<stdio.h>
#include<string.h>
#include<ctype.h>
int i = 0, error = 0;
char ch[100];

void E()
{
    T();
    Eprime();
}

void Eprime()
{
    if(ch[i]=='+')
    {
        i++;
        T();
        Eprime();
    }
}

void T()
{
    F();
    Tprime();
}

void Tprime()
{
    if(ch[i] == '*')
    {
        i++;
        F();
        Tprime();
    }
}

void F()
{
    if(isalnum(ch[i]))
        i++;
    else if(ch[i] == '(')
    {
        i++;
        E();
        if(ch[i]== ')')
            i++;
        else
            error = 1;
    }
    else error = 1;
}


void main()
{
    printf("Enter the string: ");
    scanf("%s",ch);
    E();
    if(strlen(ch)==i && error == 0)
        printf("\nThe string is acceptable!!!\n");
    else
        printf("\nString is not accepted!!\n");
}