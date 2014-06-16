/*Program Towers of Hanoi
Author:Lazar Bianca-Denise
Date:21/02/2013
*/

#include <stdio.h>
#include<math.h>
#include<conio.h> 

void towers(int n,char source,char dest,char spare)
{ 
    if(n==1)
    {
        printf("\nMovedisk1 from source:%c to dest:%c",source,dest);
    }
    else
    {
        towers(n-1,source,spare,dest);
        printf("\nMovedisk%d from source:%c to dest:%c",n,source,dest);
        towers(n-1,spare,dest,source);
    }
}
int main(void)
{ 
    int n;
    int moves;
    clrscr();
 
    printf("Enter the number of disks you want to play with:");
    scanf("%d",&n);
    printf("\n");
    moves=pow(2,n)-1;
    printf("\nThe number of moves required is=%d \n",moves);
    towers(n,'a','c','b');
    getch();
    return 0;

}