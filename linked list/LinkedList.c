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
