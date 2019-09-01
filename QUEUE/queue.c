#include<stdio.h>
#include<conio.h>
#define SIZE 10
int que[SIZE];
int rear = -1;
int front = -1;
void insert(int item)
{
    if(isfull())
    {
        printf("QUEUE IS full\n");
        return ;
    }
    if(front == -1)
        front = 0;
    rear++;
    que[rear]=item;
}

int delete()
{
    int item;
    if(isempty())
    {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    item=que[front];
    front++;
    return item;
}
int peek()
{
    if(isempty())
    {
        printf("QUEUE IS EMPTY\n");
        return ;
    }
    return que[front];
}
void display()
{ int f=front;
    if(isempty())
    {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    printf("QUEUE ELEMENTS ARE : ");

    while(f<=rear)
    {
        printf("%d ",que[f]);
        f++;
    }
}
int isfull()
{
    if(rear==SIZE-1)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(front == -1 || rear == -1)
        return 1;
    else
        return 0;
}
void main()
{
    int ch,item;
    while(1)
    {
    system("cls");
    printf("PRESS 1. TO INSERT AN ELEMENT IN QUEUE\n");
    printf("PRESS 2. TO DELETE AN ELEMENT FROM QUEUE\n");
    printf("PRESS 3. TO DISPLAY ELEMENT AT THE FRONT\n");
    printf("PRESS 4. TO DISPLAY ALL THE ELEMENT OF THE QUEUE\n");
    printf("PRESS 5. TO EXIT\n\n");
    printf("ENTER YOUR CHOICE : ");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&item);
        insert(item);
        break;
    case 2:
        item=delete();
        printf("Deleted element is %d\n",item);
        getch();
        break;
    case 3:
        printf("Element at the front is : %d\n",peek());
        getch();
        break;
    case 4:
        display();
        getch();
        break;
    case 5:
        exit(1);
    default :
        printf("*****INVALID CHOICE******\n");
        getch();
    };
    }
    getch();
}
