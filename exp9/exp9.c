#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define SIZE 50
char infix[SIZE],postfix[SIZE],stack[SIZE],st[23],a,b,cntr,res, mat[23][23];
int l,s,cnt,top=-1, temp = 0;
int precedence(char);
void convert();
int pop();
void push(char);

void main()
{
    int i,d = 0;
    printf("Enter the infix expression: ");
    gets(infix);
    convert();
    printf("Postfix expression: ");
    puts(postfix);
    top = -1;
    for(i=0;i<strlen(postfix);i++)
    {
        cnt = 0;
        if(isalnum(postfix[i]))
        {
            top++;
            st[top] = postfix[i];
        }
        else
        if(postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '/')
        {
            b = st[top];
            top--;
            a = st[top];
            top--;
            s++;
            cntr = s+'0';
            mat[l][0] = cntr;
            mat[l][1] = '=';
            mat[l][2] = a;
            mat[l][3] = postfix[i];
            mat[l][4] = b;
            l++;
            top++;
            st[top] = cntr;

        }
    }
    cntr = s+ '0';
    s++;
    mat[l][0] = res;
    mat[l][1] = '=';
    mat[l][2] = cntr;
    l++;
    printf("\nThe three address code is:\n");
    for(i=0;i<l;i++)
    {
        printf("%s\n",mat[i]);
        
    }
}


void convert(){
    int i;
    char next,symbol;
    for(i=0;i<strlen(infix);i++)
    {
        symbol = infix[i];
        if(isalpha(infix[i])&&infix[i+1]== '=')
            res = infix[i];
        switch((symbol))
        {
            case '(': push(symbol);
                      break;
            case ')': while((next=pop())!='(')
                        postfix[temp++] = next;
                      break;
            case '+':
            case '-':
            case '*':
            case '/': while(precedence(symbol)<precedence(stack[top]))
                      postfix[temp++] = pop();
                      if(precedence(stack[top])== precedence(symbol))
                      {
                        postfix[temp++] = pop();
                        push(symbol);
                      }
                      else
                        push(symbol);
                     break;
            default: postfix[temp++] = symbol;
                      
        }
    }
    while(top!=-1)
        postfix[temp++] = pop();
    postfix[temp] = '\0';
}

int precedence(char ch)
{
    switch(ch)
    {
        case '(': return 0;
        case '+': 
        case '-': return 1;
        case '*':
        case '/': return 2;
        default : return 0;
    }
}

void push(char c)
{
    top++;
    stack[top] = c;
}

int pop()
{
    return (stack[top--]);
}


/*

Enter the infix expression: x=a+a*a-a
Postfix expression: x=aaa*+a-

The three address code is:
1=a*a
2=a+1
3=2-a
x=3
*/