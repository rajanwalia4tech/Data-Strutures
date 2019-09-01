#include<stdio.h>
#include<conio.h>
#include"Stack.h"
#include"Stack.c"
void main()
{
    int ch,n,item;
    while(1)
    {
    system("cls");
    printf("press 1. To push an element in Stack\n");
    printf("press 2. To pop an element from the Stack\n");
    printf("press 3. To check Peek or Top element on the Stack\n");
    printf("press 4. To Display all the element of the Stack\n");
    printf("press 5. Quit\n");
    printf("Enter your choice : ");
    scanf("%d",&ch);
    switch(ch)
      {
        case 1:
        printf("Enter the element to be pushed : ");
        scanf("%d",&item);
        push(item);
        break;
        case 2:
          if(top==NULL)
            {
                printf("STACK UNDERFLOW\n");
            }
          else
            {
                n=pop();
                printf("popped element is %d \n",n);
            }
            getch();
            break;
        case 3:
              if(top==NULL)
                {
                printf("STACK UNDERFLOW\n");
                }
                else
                {
                item=peek();
                printf("The top element on the stack is %d \n",item);
                }

            getch();
            break;
        case 4:
            display();
            getch();
            break;
        case 5:
            exit(0);
        default:
            printf("---INVALID CHOICE---\n");
            getch();
      }
    }
getch();
}


