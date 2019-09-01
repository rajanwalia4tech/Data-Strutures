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
void CreateList(int);
void InsertAfter(int ,int );
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



