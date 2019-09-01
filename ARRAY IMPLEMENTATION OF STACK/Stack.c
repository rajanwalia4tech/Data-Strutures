struct arrayStack
{
    int top;
    int capacity;
    int *array;
};

struct arrayStack* createStack(int cap)  //size of stack or size of array
{
 struct arrayStack *stack;
 stack->capacity=cap;
 stack->top=-1;
 stack->array=(int *)malloc(sizeof(int)*(stack->capacity));
 return stack;
}

int isFull(struct arrayStack* stack)
{
    if(stack->top==stack->capacity-1)
        return 1;
    else
        return 0;
}

int isEmpty(struct arrayStack* stack)
{
    if(stack->top==-1)
        return 1;
    else
        return 0;
}

void Push(int data,struct arrayStack* stack)
{
 if(!isFull(stack))
 {
     stack->top++;
     stack->array[stack->top]=data;
 }
 else
    printf("STACK IS FULL\n");
}
int Pop(struct arrayStack* stack)
{
    int item;
    if(!isEmpty(stack))
    {
    item=stack->array[stack->top];
    stack->top--;
    return item;
    }
    return -1;

}

void view(struct arrayStack* stack)
{
    int t;
    if(stack->top==-1)
        printf("STACK IS EMPTY\n");
    else
    {
        t=0;
        printf("ELEMENT OF THE STACK ARE :-  ");
        while((t-1)!=stack->top)
        {
        printf("%d  ",stack->array[t]);
        t++;
        }
    }
}
