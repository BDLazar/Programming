
/*Fibonacci series using for loops
Author:Lazar Bianca-Denise
Date:21/02/2013
*/
#include<stdio.h>
int main()
{
    int k,r;
    int i=0,j=1,sum;

    //Taking maximum numbers from the user
    printf("Enter the number range:");
    scanf("%d",&r);

    printf("\nFirst %d terms of Fibonacci series are:\n",r);
    printf("%d %d",i,j); //printing first two values.

    for(k=2;k<r;k++)
    {
        sum=i+j;
        i=j;
        j=sum;
        printf(" %d",j);
    }
    getchar();
    getchar();
  
    return 0;
}

