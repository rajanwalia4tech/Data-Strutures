#include<stdio.h>
#include<conio.h>'
#include<stdlib.h>
struct Node{
int info;
struct Node* link;
};
struct Node* START=NULL;
void CreateList(int);
void ViewList();
void CreateList(int data)
{
    struct Node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct Node));
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
void delete(int key)
{
    struct Node *temp, *p=START,*head=START,*q;
    if(p->info==key)
    {
        temp=p;
        p=p->link;
        free(temp);
        START=head;
    }
    else
    {
        while(p!=0)
        {
            q=p->link;
            if(q->link->info==key)
            {
                temp=q;
                q=q->link;
                p->link=q;
                free(temp);
            }
            p=p->link;
        }

    }
    START=head;
    if(p->link ==0)
    printf("key is not found \n");
    else
        printf("key is deleted\n");
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
}
void main()
{
    int i,j,m,n,key;
    printf("enter the number of nodes you insert : ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        printf("enter an element ");
        scanf("%d",&m);
        CreateList(m);
    }
    printf("enter the element to be deleted from this list ");
    ViewList();
    scanf("%d",&key);
    delete(key);
    ViewList();
    getch();
}
