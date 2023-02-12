#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void main()
{
    char ch[10][10],result[10][10],opr[5],str[10];
    int i=0,j;
    printf("Enter the codes(enter exit to stop):\n");
    do
    {
        /* code */
        scanf("%s",ch[i]);
    } while (strcmp(ch[i++],"exit")!=0);
    printf("Target code generation: \n");
    i=0;
    do{
        strcpy(str,ch[i]);
        switch(str[3])
        {
            case '+': strcpy(opr,"ADD");
                        break;
            case '-': strcpy(opr,"SUB");
                        break;
            case '*': strcpy(opr,"MUL");
                        break;
            case '/': strcpy(opr,"DIV");
                        break;
        }
        if(isdigit(str[2]))
            printf("MOV R%d,#%c\n",i,str[2]);
        else
            printf("MOV R%d,%c\n",i,str[2]);
        if(isdigit(str[4]))
                printf("%s R%d,#%c\n",opr,i,str[4]);
        else
            printf("%s R%d,%c\n",opr,i,str[4]);
        printf("MOV %c,R%d\n",str[0],i);
    }while(strcmp(ch[++i],"exit")!=0);
    
}