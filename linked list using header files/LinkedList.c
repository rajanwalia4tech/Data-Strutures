#include"LinkedList.h"
struct Node{
int info;
struct Node* link;
};
struct Node* START=NULL;
void InsertAfter(int data,int position)
{
    int i;
    struct Node* q=START;
    for(i=0;i<position-1;i++)
    {
        q=q->link;
        if(q==NULL)
        {
            printf("list is less than the %d postion you entered ",position);
            getch();
            return;
        }
    }

    struct Node* temp=(struct Node *)malloc(sizeof(struct Node));
    temp->info=data;
    temp->link=q->link;
    q->link=temp;

}
void InsertFront(int data)
{
    struct Node *q,*temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->info=data;
    temp->link=START;
    START=temp;
}

void ViewList()
{
    struct Node* ptr_START;
  if(START==NULL)
        printf("LIST IS EMPTY");
  else
  {
      printf("list is : \n");
      ptr_START=START;
      while(ptr_START!=NULL)
        {
          printf("%d  ",ptr_START->info);
          ptr_START=ptr_START->link;
        }
  }
  getch();
}
void CreateList(int data)
{
    struct Node *q,*temp;
    temp=(struct Node*)malloc(sizeof(struct Node));
    temp->info=data;
    temp->link=NULL;
    if(START==NULL)
        START=temp;
    else
    {
        q=START;
        while(q->link!=NULL)
            q=q->link;
        q->link=temp;
    }
}
void deleteNode(int data)
{
    struct Node *q,*temp;
    if(START->info==data)
    {
        temp=START;
        START=START->link;  //first element deleted
        free(temp);
        return;
    }
    q=START;
    while(q->link->link!=NULL)
    {
        if(q->link->info==data)
        {
            temp=q->link;
            q->link=temp->link; //Element deleted in between list
            free(temp);
            return;
        }
        q=q->link;
    }

    if(q->link->info==data)      //Last element deleted
    {
        temp=q->link;
        free(temp);
        q->link=NULL;
        return;
    }
    printf("Element %d has not found in the list\n",data);
    getch();
}
void ReverseList()
{
    struct Node *temp,*next,*prev;
    temp=START;

    if(temp==NULL)
        printf("LIST IS EMPTY\n");
    else
    {
        prev=NULL;
        while(temp!=NULL)
        {
            next=temp->link;
            temp->link=prev;
            prev=temp;
            temp=next;
        }
        START=prev;
    }
}


