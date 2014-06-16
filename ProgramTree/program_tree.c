#include <stdio.h>


int main()
{
	
	//variables declaration
	int i,space,rows,m;
    m=0;

	//initialisation size
	printf("Enter the number of rows that the tree will have : ");
    scanf("%d",&rows);
	
	printf("\n");
    
	//loop for spaces
	for(i=1;i<=rows;++i)
    {
        for(space=1;space<=rows-i;++space)
        {
           printf("  ");
        }
        //loop for stars
        while(m!=2*i-1)
        {
           printf("* ");
           ++m;
        }
        m=0;
        printf("\n");
    }
	//put in the trunk
	int d=(rows*2)-1;

	for(int i=0;i<d;i++)
	{
		if(i==d/2)
		
		{
		printf("*");
		}
		
		else
		
		{
		printf("  ");
		}
		
	
	}
	
	printf("\nPress ENTER to Exit ");
	
	getchar();
	getchar();
	
	return 0;

}