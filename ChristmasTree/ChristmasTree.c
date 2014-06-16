#include <stdio.h>


//funtion to print out the lines of stars 
void printLine(int row)
{
	int blanks = 4 - row;
	int stars = row + (row - 1);

	for(int j = 0; j < blanks; j++)
	{
		printf(" ");
	}

	for (int k = 0; k < stars; k++)
	{
		printf("*");
	}
}

//function to create the triangles
void triangleMake(int magn)
{
	for (int l = 1; l <= magn+1; l++)
	{
		printLine(l);
		printf("\n");
	}
}

int main()
{
	//variables
	int counter = 1;
	int triangle = 1;
	//main code

	while(triangle < 4)
	{
		triangleMake(triangle);
		triangle++;
	}


	for (int m = 0; m < 3; ++m)
	{
		printf(" ");
	}

	printf("|\n");

	printf("=======\n");
    getchar();
    getchar();

	return 0;
}