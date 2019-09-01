#include<stdio.h>
#include<stdlib.h>
#include"doubly linked list.h"
struct node
{
    int info;
    struct node *prev,*next;
};
struct node* START=NULL;
void InsertAtFront(int x)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    struct node* n;
    temp->info=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(START==NULL)
        START=temp;
    else
    {
        START->prev=temp;
        temp->next=START;
        START=temp;

    }
}
void DeleteAtFront()
{
    struct node *temp;
    if(START==NULL)
        printf("LIST IS EMPTY ");
    else
    {
        temp=START;
        START=START->next;
        START->prev==NULL;
        free(temp);
    }
}
void ViewList()
{
    struct node* temp;
    if(START==NULL)
        printf("LIST IS EMPTY");
    else
    {
        printf("LIST IS:-");
        temp=START;
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->next;
        }
    }
}
