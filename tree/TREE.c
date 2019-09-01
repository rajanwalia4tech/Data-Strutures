#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

struct BSTnode{
struct BSTnode* left;
int data;
struct BSTnode* right ;
};

void gotoxy(int x,int y)                // For printing at console position
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


struct BSTnode* getnode(int info)
{
    struct BSTnode* newnode=(struct BSTnode*)malloc(sizeof(struct BSTnode));
    newnode->data=info;
    newnode->left=0;
    newnode->right=0;
    return newnode;
}
struct BSTnode* insert(struct BSTnode* root,int item)
{
    struct BSTnode* t;
    if(root==NULL)
    {
        root=getnode(item);

    }
    else
    {
        t=root;
        while(t!=0)
        {
            if(t->data > item)
            {
                if(t->left==0)
                    {
                      t->left=getnode(item);
                      break;
                    }

                t=t->left;
            }
            else if(t->data < item)
            {
                if(t->right == 0)
                {
                    t->right=getnode(item);;
                    break;
                }

                t=t->right;
            }
            else
            {
                printf(" !!!!!!!!!!!!    Duplicate Element    !!!!!!!!!!!");
                getch();
                return root;
            }

        }   //END OF WHILE
    } // END OF ELSE
    return root;
} // END OF INSERT

void search(struct BSTnode*p,int key)
{
    while(p!=NULL)
    {
        if(p->data>key)
           p=p->left;
        else if(p->data<key)
            p=p->right;
        else if(key == p->data)
        {
            printf("key is found\n");
            break;
        }
    }
    if(p==0)
        printf("key is not found\n");
}

struct BSTnode* Min(struct BSTnode* root)
{
        while(root->left!=0)
        root=root->left;
    return root;
}

struct BSTnode* Max(struct BSTnode* root)
{
    while(root->right!=0)
        root=root->right;
    return root;
}

void inorder(struct BSTnode* root)
{
    if(root==NULL)
        return ;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

void preorder(struct BSTnode* root)
{
if(root == NULL)
    return ;
printf("%d ",root->data);
preorder(root->left);
preorder(root->right);
}

void PREORDER_USING_STACK(struct BSTnode* root)                 // Preorder Traversal Using Stack
{
    int STACK[50],TOP=0;
    STACK[TOP]=NULL;
    struct BSTnode *PTR = root;
    while(PTR!=NULL)
    {
        printf("%d ",PTR->data);
        if(PTR->right!=NULL)
        {
            STACK[++TOP]=PTR->right;
        }
        if( PTR->left != NULL)
            PTR = PTR->left;
        else{
            PTR = STACK[TOP--];
        }
    }

}

INORDER_USING_STACK(struct BSTnode* root)
{
    int STACK[50],TOP=0;
    STACK[TOP]=NULL;
    struct BSTnode* PTR=root;
    start :
    while(PTR!=NULL)
    {
        STACK[++TOP]=PTR;
        PTR=PTR->left;
    }
    PTR=STACK[TOP--];
    while(PTR!=NULL)
    {
        printf("%d ",PTR->data);
        if(PTR->right!=NULL)
            {
                PTR=PTR->right;
                goto start;
            }
        else{
            PTR=STACK[TOP--];
        }
    }

}

void postorder(struct BSTnode* root)
{
    if(root== NULL)
        return ;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

/*POSTORDER_USING_STACK(struct BSTnode* root)
{

    int STACK[50],TOP=0;
    STACK[TOP]=NULL;
    struct BSTnode* PTR=root;
    start :
        while(PTR!=NULL)
        {
            STACK[++TOP]=PTR;
            if(PTR->right!=NULL)
                STACK[++TOP] = - (PTR->right);
            PTR = PTR->left;
        }
        PTR=STACK[TOP--];
        while(PTR>0)
        {
            printf("%d ",PTR->data);
            PTR = STACK[TOP--];
        }
        if(PTR<0)
        {
            PTR = -PTR;
            goto start;
        }
}
*/
struct node* delete(struct BSTnode* root,int key)//To Delete a node from BST
{
    if(root == NULL)
        return root;
    else if(key < root->data)
        root->left = delete(root->left,key);
    else if(key > root->data)
        root->right=delete(root->right,key);
    else{
        if(root->left== 0 && root->right == 0) // case 1: no child
        {
            free(root);
            root= NULL;
        }
        else if(root->left== 0)         // case 2: only 1 child
        {
            struct node* temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right == 0)
        {
            struct node* temp=root;
            root = root->left;
            free(temp);
        }
        else  //case 3: 2 child
        {
            struct BSTnode* temp = Min(root->right);
            root->data=temp->data;
            root->right= delete(root->right,temp->data);
        }
    }
    return root;
}
int main()
{
    struct BSTnode* root=NULL;
    int info,ch,key;
    while(1)
    {

        system("cls");
        gotoxy(10,5);
        {

        printf("##### PROGRAM TO PERFORM OPERATIONS ON BINARY SEARCH TREE #####\n\n");
        printf("PRESS 1. TO INSERT AN ELEMENT IN BST\n");
        printf("PRESS 2. TO SEARCH AN ELEMENT IN BST\n");
        printf("PRESS 3. TO DELETE AN ELEMENT FROM BST\n");
        printf("PRESS 4. TO VIEW ELEMENTS ,INORDER TRAVERSAL USING RECURSION\n");
        printf("PRESS 5. TO VIEW ELEMENTS ,PREORDER TRAVERSAL USING RECURSION \n");
        printf("PRESS 6. TO VIEW ELEMENTS ,POSTORDER TRAVERSAL USING RECURSION \n");
        printf("PRESS 7. TO VIEW ELEMENTS ,PREORDER USING STACK\n");
        printf("PRESS 8. TO VIEW ELEMENTS ,INORDER USING STACK\n");
        printf("PRESS 9. TO VIEW ELEMENTS ,POSTORDER USING STACK\n");
        printf("PRESS 10.FIND MINIMUM AND MAXIMUM ELEMENT IN BST \n");
        printf("PRESS 11. TO EXIT\n");
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d",&ch);
        }
        switch(ch)
        {
        case 1:
            printf("\nENTER THE ELEMENT TO BE INSERTED : ");
            scanf("%d",&info);
            root = insert(root,info);     //to insert an element in the tree
            break;
        case 2:
            if(root==0)
                printf("tree is empty \n");
            else
            {
            printf("\nENTER THE ELEMENT TO BE SEARCHED : "); // to search an element from the tree
            scanf("%d",&key);
            search(root,key);
            }
            break;
        case 3:
            printf("Enter the the element to be deleted : ");
            scanf("%d",&key);
            root=delete(root,key);
            break;
        case 4:
            if(root == NULL)
            {
                printf("TREE IS EMPTY!");
                break;
            }
            inorder(root);
            getch();
            break;
        case 5:
            if(root ==NULL)
            {
                printf("TREE IS EMPTY!");
                break;
            }

            preorder(root);
            getch();
            break;
        case 6:
            if(root ==NULL)
            {
                printf("TREE IS EMPTY!");
                break;
            }
            postorder(root);
            getch();
            break;

        case 7:
            PREORDER_USING_STACK(root);
            getch();
            break;

        case 8:
            INORDER_USING_STACK(root);
            getch();
            break;
        case 9:
            /*POSTORDER_USING_STACK(root);*/
            getch();
            break;
        case 10:
            if(root!=0)
            {
            struct BSTnode* temp =Min(root);
            printf("MINIMUM ELEMENT IS %d \n",temp->data);
            temp=Max(root);
            printf("MAXIMUM ELEMENT IS %d \n",temp->data);
            }
            else
                printf("tree is empty");
            break;

        case 11:
            exit(1);
        default:
            printf("!!!!! OOPS !!!!!! INVALID CHOICE\n");

        }
    }
return 0;
}
