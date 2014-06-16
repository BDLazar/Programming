/*Fibonacci series using  recursion
Author:Lazar Bianca-Denise
Date:21/02/2013
*/

#include<stdio.h>
 
int Fibonacci(int);
 
main()
{
    int n,c;
    int i=0;
 
    printf("Enter the number range followed by the Fibonacci sequence : ");
    scanf("%d",&n);
    for( c=1;c <=n;c++ )
    {
      //printf("\nThe Fibonacci sequence is:%d", Fibonacci(i));
        printf("%d\n",Fibonacci(i));
        i++;
    } 
    //printf("\nThe %d term of the Fibonacci sequence is:%d");
    
   
    getchar();
    getchar();
 
   return 0;
}
 
int Fibonacci(int n)
{
   if ( n == 0 )
   {
      return 0;
   }
   else if ( n == 1 )
   {
      return 1;
   }
   else
   {
      return ( Fibonacci(n-1) + Fibonacci(n-2) );
   }
} 