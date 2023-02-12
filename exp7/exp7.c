#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 20

int n,m=0,i=0,j=0;
char a[MAX][MAX], f[MAX];

void first(char c)
{
    int k;
    if(!isupper(c))
        f[m++] = c;
    for(k=0;k<n;k++)
    {
        if(a[k][0]==c)
        {
            if(a[k][2]=='$')
                follow(a[k][0]);
            else if(islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
        }
    }
}

void follow(char c)
{
    if(a[0][0] == c)
        f[m++] = '$';
    for(int i = 0; i < n; i++)
    {
        for(int j = 2; j<strlen(a[i]);j++)
        {
            if(a[i][j] == c)
            {
                if(a[i][j+1]!='\0')
                    first(a[i][j+1]);
                if(a[i][j+1]=='\0' && c!= a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}


void main()
{
    int choice, i;
    char c,ch;
    printf("Enter the no of productions: ");
    scanf("%d",&n);
    printf("Enter %d productions: \n",n);
    for(i=0;i<n;i++)
        scanf("%s%c",a[i],&ch);
    do
    {
        /* code */
        m=0;
        printf("\nEnter the character to check for first and follow: ");
        scanf("%c",&c);
        printf("First of (%c): { ",c);
        first(c);
        for(i=0;i<m;i++)
            printf("%c ",f[i]);
        printf("}\n");
        strcpy(f,"");
        m = 0;
        printf("Follow of (%c): { ",c);
        follow(c);
        for(i=0;i<m;i++)
            printf("%c ",f[i]);
        printf("}\n");
        printf("Enter 1 to continue or 0 to exit: ");
        scanf("%d%c",&choice,&ch);
    } while (choice == 1);
    
}