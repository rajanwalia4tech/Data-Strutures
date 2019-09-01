#include<stdio.h>
#include<conio.h>
#include<time.h>
void main()
{
    long Starttime,Endtime;
    long i,j=0;
    float start,end;
    double t1,t2;
    printf("---- Performance of FOR LOOP ----\n\n");

    Starttime = clock();     /* start time for while loop */
    for(i=0;i<100000000;i++);
    Endtime = clock();      /* End time for for loop */
    t1= Endtime -Starttime; /* Total time of for loop */
    printf("\n %f seconds\n\n",((double)t1)/CLOCKS_PER_SEC);

    printf("----Performance of WHILE LOOP -----\n\n");
    Starttime = clock();    /* start time for while loop */
    while(j<100000000)
    {
        j++;
    }
    Endtime=clock();        /* endtime for while loop */
    t2= Endtime -Starttime; /* Total time of while loop */
    printf("\n %f seconds\n\n",((double)t2)/CLOCKS_PER_SEC);
    printf("\n");
}
