#include<stdio.h>
#include<conio.h>'
#include<stdlib.h>
struct Node{
int info;
struct Node* link;
};
struct Node* START=NULL;
void InsertFront(int);
void ViewList();
void InsertFront(int data)
{
    struct Node *q,*temp;
    temp=(struct node*)malloc(sizeof(struct Node));
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
}
void main()
{
    int i,j,m,n;
    printf("enter the number of nodes you insert : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("enter an element ");
        scanf("%d",&m);
        InsertFront(m);
    }
    ViewList();
    getch();
}

