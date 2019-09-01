#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node* top=NULL;

void push(int item)
{
    struct node* temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    temp->info=item;
    temp->link=top;
    top=temp;
}

int pop()
{
    struct node* temp;
    int item;
    if(top==NULL)
    {
        printf("STACK UNDERFLOW\n");
        return 0;
    }
    item=top->info;
    temp=top;
    top=top->link;
    free(temp);
    return(item);
}

int peek()
{
    int item;
    item=top->info;
    return (item);
}

void display()
{
    struct node* temp;
    temp=top;
    if(top==NULL)
    {
        printf("STACK IS EMPTY\n");
        return;
    }
    printf("STACK ELEMENTS : ");

    while(temp!=NULL)
    {
        printf("%d ",temp->info);
        temp=temp->link;
    }
    printf("\n");
}
