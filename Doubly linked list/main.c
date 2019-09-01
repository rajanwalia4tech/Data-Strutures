#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"doubly linked list.h"
#include"doubly linked list.c"
int main()
{
    int i,ch,n;
      while(1)
    {
        system("cls");
    printf("PRESS 1. TO INSERT THE NODE AT FRONT \n");
    printf("PRESS 2. TO INSERT A NODE IN MIDDLE\n");
    printf("PRESS 3. TO INSERT AT THE END \n");
    printf("PRESS 4. TO DELETE THE NODE FROM FRONT \n");
    printf("PRESS 5. TO DELETE THE NODE FROM END \n");
    printf("PRESS 6. TO VIEW THE LIST \n");
    printf("PRESS 7. TO EXIT\n");

    printf("\nENTER YOUR CHOICE ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("ENTER THE NUMBER TO INSERT IN NODE ");
        scanf("%d",&n);
        InsertAtFront(n);
        break;
    case 2:
        printf("enter the element to be inserted : ");
        scanf("%d",&n);
        insertatmiddle()
    case 4:
        DeleteAtFront();
        break;
    case 6:
        ViewList();
        getch();
        break;
    case 7:
        exit(1);
    default:
        printf("INVALID CHOICE\n");
        getch();
    }
    }

    getch();
return 0;
}

