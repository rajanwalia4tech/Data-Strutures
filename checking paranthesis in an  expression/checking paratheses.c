#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 30
int stack[MAX];
int top= -1;
void push(char);
char pop();
int match(char,char);
int check(char []);
void main()
{
    char exp[MAX];
    int valid;
    printf("ENTER A ALGEBRAIC EXPRESSION : ");
    gets(exp);
    valid=check(exp);
    if(valid==1)
        printf("\nEXPRESSION IS VALID");
    else
        printf("\nEXPRESION IS INVALID");
    getch();
}

int check(char exp[])
{
    int i;
    char temp;
    for(i=0;i<strlen(exp);i++)
    {
        if( exp[i]=='['||exp[i]=='{'||exp[i]=='(' )
            push(exp[i]);
        if( exp[i]=='}'||exp[i]==')'||exp[i]==']')
            {
                if(top== -1)
                {
                     printf("\nRight parantheses are more than left \n");
                     return 0;
                }
                else
                {
                    temp=pop();
                        if(!match(temp,exp[i]))
                        {
                            printf(" \nMISMATCHED PARANTHEIS ARE : %c and %c \n",temp,exp[i]);
                            return 0;
                        }

                }

            }


    }
    if(top==-1)
    {
        return 1;
    }
    else
    {
        printf("\nLeft parenthesis more than right paranthesis\n");
        return 0;
    }
}

void push(char ch)
{
    if(top==(MAX-1))
    {
        printf("\nSTACK OVERFLOW\n");
        return;
    }
        top=top+1;
        stack[top]=ch;
}

char pop()
{
    if(top==-1)
    {
        printf("\nSTACK UNDERFLOW\n");
        return;
    }
    return(stack[top--]);
}
int match(char ch1,char ch2)
{
    if(ch1=='['&&ch2==']')
        return 1;
    if(ch1=='{'&&ch2=='}')
        return 1;
    if(ch1=='('&&ch2==')')
        return 1;
    return 0;
}
