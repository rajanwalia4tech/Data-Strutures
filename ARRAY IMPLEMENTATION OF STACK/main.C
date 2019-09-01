#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Stack.h"
#include"Stack.c"

int main()
{
    int n,ch,item;
    struct arrayStack* stack=createStack(10);
    while(1)
    {
        system("cls");
    printf("press 1. TO PUSH AN ELEMENT IN STACK\n");
    printf("press 2. TO POP AN ELEMENT FROM STACK\n");
    printf("press 3. TO VIEW ELEMENTS OF STACK\n");
    printf("press 4. TO EXIT \n\n");
        printf("ENTER YOUR CHOICE ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter the element ");
            scanf("%d",&n);
            Push(n,stack);
            break;
        case 2:

            item=Pop(stack);
            if(item==-1)
                printf("STACK IS EMPTY\n");
            else
            printf("popped element is %d\n",item);
            getch();
            break;
        case 3:
            view(stack);
            getch();
            break;
        case 4:
            exit(0);
        default :
            printf("-----INVALID CHOICE-----\n");
            getch();
        }
    }

return 0;
}
