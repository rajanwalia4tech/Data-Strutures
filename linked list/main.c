#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"LinkedList.h"
#include"LinkedList.c"
int main()
{
    int i,j,m,n,ch,pos;
    while(1)
    {
        system("cls");
    printf("press 1. create list or add elements at end of the list\n");
    printf("press 2. add elements at the front of list \n");
    printf("press 3. add elements in between list \n");
    printf("press 4. To view the list \n");
    printf("press 5. exit");
    printf("\n\nenter your choice  ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("enter the number of nodes you insert : ");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("enter an element ");
                scanf("%d",&m);
                CreateList(m);
            }
            break;
        case 2:
            printf("enter the number of nodes you insert : ");
            scanf("%d",&n);
            for(i=1;i<=n;i++)
            {
                printf("enter an element ");
                scanf("%d",&m);
                InsertFront(m);
            }
            break;
        case 3:
            printf("enter the data and the position where the node will be inserted  ");
            scanf("%d%d",&m,&pos);
            InsertAfter(m,pos);
            break;
        case 4:
            ViewList();
            break;
        case 5:
            exit(1);
        default:
            printf("invalid choice \n");
            printf("DO YOU PERFORM OTHER OPERATION ");
            scanf("%d",&ch);
    }
    }
    getch();
}
