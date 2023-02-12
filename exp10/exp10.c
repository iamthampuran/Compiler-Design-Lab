#include<stdio.h>
#include<string.h>
#include<ctype.h>

char res[23][23],result[10];
int check(char);
int k = 0;

void main()
{
    int i=0,j=0,counter = 0,r=0,n;
    char mat[23][23],r2[23][23];
    printf("Enter the no of expressions: ");
    scanf("%d",&n);
    printf("Enter the 3 address codes: ");
    for(i=0;i<n;i++)
        scanf("%s",mat[i]);
    for(i=0;i<n;i++)
        for(j=0;j<strlen(mat[i]);j++)
        {
            
            if(isalnum(mat[i][0]) && mat[i][1] == '=' && mat[i][2] == '-' && isalnum(mat[i][3]))
            {
                // printf("Inside normal \t%s\n",mat[i]);
                res[k][0] = mat[i][2];
                res[k][1] = mat[i][3];
                res[k][2] = mat[i][0];
                res[k][4]=counter++ + '0';
                result[r++]=mat[i][0];
                k++;
                break;
            }
            else 
            if(isalnum(mat[i][0]) && mat[i][1] == '=' && isalnum(mat[i][2]) && (mat[i][3]== '*'|| mat[i][3] == '/' || mat[i][3]=='+'
            || mat[i][3] == '-') && isalnum(mat[i][4]))
            {
                // printf("Inside operation\t%s\n",mat[i]);
                res[k][0] = mat[i][3];
                res[k][1] = mat[i][2];
                res[k][2] = mat[i][4];
                // printf("%c\n",mat[i][4]);
                res[k][3] = mat[i][0];
                // printf("Result = %s\n",res[k]);
                res[k][4]=counter++ + '0';
                result[r++]=mat[i][0];
                k++;
                break;
            }
            else 
            if(isalnum(mat[i][0]) && mat[i][1] == '=' && isalnum(mat[i][2]))
            {
                // printf("Inside normal2\t%s\n",mat[i]);
                res[k][0] = mat[i][1];
                res[k][1] = mat[i][2];
                res[k][2] = ' ';
                res[k][3] = mat[i][0];
                res[k][4]=counter++ + '0';
                result[r++]=mat[i][0];
                k++;
                break;
            } 
        }
    printf("The Quadruple: \n");
    printf("op\top1\top2\tresult\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<4;j++)
            printf("%c\t",res[i][j]);
        printf("\n");
    }
    printf("Triple: \n");
    printf("i\top\top1\top2\n");
    for(i=0;i<k;i++)
    {
        printf("%d\t",i+1);
        for(j=0;j<3;j++)
        {
            if(!check(res[i][j]))
            printf("%c\t",res[i][j]);
        }    
        printf("\n");
    }
}

int check(char c)
{
    // printf("inside check() %c\n",c);
    for(int i = 0; i< strlen(result); i++)
    {
        if(c == result[i])
        {
            for(int j = 0; j < k; j++)
            {
                if(res[j][3] == c)
                {
                    printf("%c\t",res[j][4]);
                    return 1;
                }
            }
        }
    }
    return 0;
}