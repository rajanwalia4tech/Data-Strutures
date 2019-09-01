/*Program for array rotation
Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements */
#include<stdio.h>
#include<conio.h>
int rotation(int b[],int n,int d)
{
    int i,temp[n],j;
    for(i=0;i<d;i++)
        temp[i]=b[i];
    for(i=d;i<n;i++)
        b[i-d]=b[i];
    for(i=n-d,j=0;i<n;i++,j++)
        b[i]=temp[j];
    for(i=0;i<n;i++)
    printf("%d\t",b[i]);
}
main()
{
    int x,y,i,j,num,a[20];
    printf("enter the number of elements of array to be entered ");
    scanf("%d",&num);
    printf("enter the %d elements of array ",num);
    for(i=0;i<num;i++)
    scanf("%d",&a[i]);
    printf("enter the number of elements to be rotate : ");
    scanf("%d",&x);
    for(i=0;i<num;i++)
        printf("%d\t",a[i]);
    printf("\n");
    rotation(a,num,x);


getch();
}


