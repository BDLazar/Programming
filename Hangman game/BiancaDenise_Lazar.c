#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#define wa 6
#define wb 5
#define wc 5
#define wd 5
#define we 5
#define wx 6 

int main()
{ //declaring and initializing 
    char word1 [wa] = {'b', 'o', 'o', 'k', 's', '\0' }; 
    char word2 [wb] = {'b', 'e', 'a', 'r', '\0' };
    char word3 [wc] = {'j', 'o', 'i', 'n', '\0' };
    char word4 [wd] = {'y', 'a', 'r', 'd', '\0' };
    char word5 [we] = {'z', 'o', 'n', 'e', '\0' };    
    char wordx [wx] = {'_', '_', '_', '_', '_', '\0' }; // word found...
    
    char guessletters[27],l;
    
    int choice, status,rn,lives,i,n,guesscount,x,k,ver;
    status = 1;//a variable to know when to get out of while
    //menu driven
	printf("\nWelcome to Hangman game\n");
    printf("...................\n");
    printf("Please choose one of the options:\n");
    printf("1.Start the game\n");
    printf("2.Exit the game\n");
	scanf("%d",&choice);
while(status) {
    //waits the order from the user
   
   //  choose the action who must be fulfilled:play or exit
   switch(choice) {
	case 1:
        //for add number of lives
        srand(time(NULL));
		rn=(rand() % 4);// random number between 0 and 4
		rn++; //add a unity that the random will be between 1 and 5
		printf("\n rn = %d \n",rn);//to check what word we choose
        lives = 6;
        guesscount = -1;// number of elements for the vector guessedletters
        guessletters[0]= '\0';//a convection in c;end of string
        n = 0;// number of letters input
        x = 0;// if found the word or not
        switch (rn) {//switch 2
        case 1 : // word 1
          for (i=0;i<=wa-1;i++)
             if (isalpha(word1[i])) //check if character is alphabetic
                wordx[i]='_';
             else
                wordx[i]=word1[i];        
		  for (i=0;i<=wa-1;i++) //rewrite word 1 with uppercase
             word1[i] = toupper(word1[i]) ;
          while((lives > 0) && (x == 0)){ // check if you ran out of lives and you didn't find the word yet
                    k = 0; //auxiliary variable to see if the value read from keyboard is in word
                    printf("Lives: %d \n", lives);
                    printf("Word:");
                    for (i=0;i<=wa-1;i++)
                        printf("%c ",wordx[i]);//prints the guessed word
                    printf("\n");
                    printf("Letters guessed so far :");
                    for (i=0;i<=guesscount;i++)
                        printf("%c, ",guessletters[i]);//display letters entered
                    printf("\n");
                    printf("Guess a Letter :");
                    // read character from keyboard - with validation - only letters                
      		        ver = 0;
		            while(ver==0)
		            {
                      l = getch();
		              if (isalpha(l))
                         ver = 1;
                      else
                          printf("\nPlease insert only letters.\n");   
                    }
                   	l = toupper(l);
                    for (i=0;i<=wa-1;i++)
                    {
                    if (word1[i] == l) {
                            wordx[i] = l;
                            k = 1;//if I found a letter in  the word i add it in wordx on correct position and i remember k
                            x = 1;//to see if he  have reached at the end
                            }
                    }
                    guesscount++;
					guessletters[guesscount] = l;
					if (k==0) 
						lives--;
                    for (i=0;i<=wa-1;i++) // check if my word = guessed word 
                    {
                        if (wordx[i] != word1[i]) x=0;
                    }
                    printf("\n");                  
                }
          if ((x == 0) || (lives <= 0)) 
			{
                        printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=wa-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");     
			printf("Sorry you lost.\n");
			printf("The word was: ");
			for (i=0;i<=wa-1;i++)
                    {
                        printf("%c ",word1[i]);
                    }
			printf("\nPlay again Y/N?\n");
			}
		  if (x == 1) 
		  {
            printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=wa-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");    
			printf("You Won!\n");
			printf("Play again Y/N?\n");
		  }
		  ver = 0;
		  while(ver==0)
		  {
		     l = getch();
		     if (((l != 'y') && (l != 'Y')) && ((l != 'n') && (l != 'N'))) 
             {
               printf("Please enter Y or N.\n");
             }
		     else {ver = 1;}
          }
		  
		  if ((l=='y')||(l=='Y')) {choice=1;}
		  if ((l=='n')||(l=='N')) {choice=2;}
        break;       
        
        case 2 : //word 2       
          for (i=0;i<=wb-1;i++)
             if (isalpha(word2[i])) 
                wordx[i]='_';
             else
                wordx[i]=word2[i];    
		  for (i=0;i<=wb-1;i++) //rewrite word 2 with uppercase
             word2[i] = toupper(word2[i]) ;
          while((lives > 0) && (x == 0)){  // check if you ran out of lives and you didn't find the word yet
                    k = 0; //auxiliary variable to see if the value read from keyboard is in word
                    printf("Lives: %d \n", lives);
                    printf("Word:");
                    for (i=0;i<=wb-1;i++)
                        printf("%c ",wordx[i]);//prints the guessed word
                    printf("\n");
                    printf("Letters guessed so far :");
                    for (i=0;i<=guesscount;i++)
                        printf("%c, ",guessletters[i]);//display letters entered
                    printf("\n");
                    printf("Guess a Letter :");
                    //  read character from keyboard - with validation - only letters                
      		        ver = 0;
		            while(ver==0)
		            {
                      l = getch();
		              if (isalpha(l))
                         ver = 1;
                      else
                          printf("\nPlease insert only letters.\n");   
                    }
                   	l = toupper(l);
                    for (i=0;i<=wb-1;i++)
                    {
                    if (word2[i] == l) {
                            wordx[i] = l;
                            k = 1;// if I found a letter in  the word i add it in wordx on correct position and i remember k
                            x = 1;
                            }
                    }
                    guesscount++;
					guessletters[guesscount] = l;
					if (k==0) 
						lives--;
                    for (i=0;i<=wb-1;i++) // check if my word = guessed word 
                    {
                        if (wordx[i] != word2[i]) x=0;
                    }
                    printf("\n");                  
                }
          if ((x == 0) || (lives <= 0)) 
			{
                        printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=wb-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");     
			printf("Sorry you lost.\n");
			printf("The word was: ");
			for (i=0;i<=wb-1;i++)
                    {
                        printf("%c ",word2[i]);
                    }
			printf("\nPlay again Y/N?\n");
			}
		  if (x == 1) 
		  {
            printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=wb-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");    
			printf("You Won!\n");
			printf("Play again Y/N?\n");
		  }
		  ver = 0;
		  while(ver==0)
		  {
		     l = getch();
		     if (((l != 'y') && (l != 'Y')) && ((l != 'n') && (l != 'N'))) 
             {
               printf("Please enter Y or N.\n");
             }
		     else {ver = 1;}
          }
		  
		  if ((l=='y')||(l=='Y')) {choice=1;}
		  if ((l=='n')||(l=='N')) {choice=2;}               
        break;
        
        case 3 : //word 3       
          for (i=0;i<=wc-1;i++)
             if (isalpha(word3[i])) 
                wordx[i]='_';
             else
                wordx[i]=word3[i];    
		  for (i=0;i<=wc-1;i++) //rewrite word 3 with uppercase
             word3[i] = toupper(word3[i]) ;
          while((lives > 0) && (x == 0)){ //  check if you ran out of lives and you didn't find the word yet
                    k = 0; //auxiliary variable to see if the value read from keyboard is in word
                    printf("Lives: %d \n", lives);
                    printf("Word:");
                    for (i=0;i<=wc-1;i++)
                        printf("%c ",wordx[i]);//prints the guessed word
                    printf("\n");
                    printf("Letters guessed so far :");
                    for (i=0;i<=guesscount;i++)
                        printf("%c, ",guessletters[i]);//display letters entered
                    printf("\n");
                    printf("Guess a Letter :");
                    //  read character from keyboard - with validation - only letters                   
      		        ver = 0;
		            while(ver==0)
		            {
                      l = getch();
		              if (isalpha(l))
                         ver = 1;
                      else
                          printf("\nPlease insert only letters.\n");   
                    }
                   	l = toupper(l);
                    for (i=0;i<=wc-1;i++)
                    {
                    if (word3[i] == l) {
                            wordx[i] = l;
                            k = 1;// if I found a letter in  the word i add it in wordx on correct position and i remember k
                            x = 1;
                            }
                    }
                    guesscount++;
					guessletters[guesscount] = l;
					if (k==0) 
						lives--;
                    for (i=0;i<=wc-1;i++) // check if my word = guessed word 
                    {
                        if (wordx[i] != word3[i]) x=0;
                    }
                    printf("\n");                  
                }
          if ((x == 0) || (lives <= 0)) 
			{
                        printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=wc-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");     
			printf("Sorry you lost.\n");
			printf("The word was: ");
			for (i=0;i<=wc-1;i++)
                    {
                        printf("%c ",word3[i]);
                    }
			printf("\nPlay again Y/N?\n");
			}
		  if (x == 1) 
		  {
            printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=wc-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");    
			printf("You Won!\n");
			printf("Play again Y/N?\n");
		  }
		  ver = 0;
		  while(ver==0)
		  {
		     l = getch();
		     if (((l != 'y') && (l != 'Y')) && ((l != 'n') && (l != 'N'))) 
             {
               printf("Please enter Y or N.\n");
             }
		     else {ver = 1;}
          }
		  
		  if ((l=='y')||(l=='Y')) choice=1;
		  if ((l=='n')||(l=='N')) choice=2;                              
        break;
        
        case 4 : //word  4       
          for (i=0;i<=wd-1;i++)
             if (isalpha(word4[i])) 
                wordx[i]='_';
             else
                wordx[i]=word4[i];    
		  for (i=0;i<=wd-1;i++) //rewrite word 4 with uppercase
             word4[i] = toupper(word4[i]) ;
          while((lives > 0) && (x == 0)){ // check if you ran out of lives and you didn't find the word yet
                    k = 0; //auxiliary variable to see if the value read from keyboard is in word
                    printf("Lives: %d \n", lives);
                    printf("Word:");
                    for (i=0;i<=wd-1;i++)
                        printf("%c ",wordx[i]);//prints the guessed word
                    printf("\n");
                    printf("Letters guessed so far :");
                    for (i=0;i<=guesscount;i++)
                        printf("%c, ",guessletters[i]);//display letters entered
                    printf("\n");
                    printf("Guess a Letter :");
                    //  read character from keyboard - with validation - only letters                  
      		        ver = 0;
		            while(ver==0)
		            {
                      l = getch();
		              if (isalpha(l))
                         ver = 1;
                      else
                          printf("\nPlease insert only letters.\n");   
                    }
                   	l = toupper(l);
                    for (i=0;i<=wd-1;i++)
                    {
                    if (word4[i] == l) {
                            wordx[i] = l;
                            k = 1;//if I found a letter in  the word i add it in wordx on correct position and i remember k
                            x = 1;
                            }
                    }
                    guesscount++;
					guessletters[guesscount] = l;
					if (k==0) 
						lives--;
                    for (i=0;i<=wd-1;i++) // check if my word = guessed word 
                    {
                        if (wordx[i] != word4[i]) x=0;
                    }
                    printf("\n");                  
                }
          if ((x == 0) || (lives <= 0)) 
			{
                        printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=wd-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");     
			printf("Sorry you lost.\n");
			printf("The word was: ");
			for (i=0;i<=wd-1;i++)
                    {
                        printf("%c ",word4[i]);
                    }
			printf("\nPlay again Y/N?\n");
			}
		  if (x == 1) 
		  {
            printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=wd-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");    
			printf("You Won!\n");
			printf("Play again Y/N?\n");
		  }
		  ver = 0;
		  while(ver==0)
		  {
		     l = getch();
		     if (((l != 'y') && (l != 'Y')) && ((l != 'n') && (l != 'N'))) 
             {
               printf("Please enter Y or N.\n");
             }
		     else {ver = 1;}
          }
		  
		  if ((l=='y')||(l=='Y')) {choice=1;}
		  if ((l=='n')||(l=='N')) {choice=2;}               
        break;
                
        case 5 : //word 5       
          for (i=0;i<=we-1;i++)
             if (isalpha(word5[i])) 
                wordx[i]='_';
             else
                wordx[i]=word5[i];    
		  for (i=0;i<=we-1;i++) //rewrite word 5 with uppercase
             word5[i] = toupper(word5[i]) ;
          while((lives > 0) && (x == 0)){ //check if you ran out of lives and you didn't find the word yet
                    k = 0; //auxiliary variable to see if the value read from keyboard is in word
                    printf("Lives: %d \n", lives);
                    printf("Word:");
                    for (i=0;i<=we-1;i++)
                        printf("%c ",wordx[i]);//prints the guessed word
                    printf("\n");
                    printf("Letters guessed so far :");
                    for (i=0;i<=guesscount;i++)
                        printf("%c, ",guessletters[i]);//display letters entered
                    printf("\n");
                    printf("Guess a Letter :");
                    //  read character from keyboard - with validation - only letters                   
      		        ver = 0;
		            while(ver==0)
		            {
                      l = getch();
		              if (isalpha(l))
                         ver = 1;
                      else
                          printf("\nPlease insert only letters.\n");   
                    }
                   	l = toupper(l);
                    for (i=0;i<=we-1;i++)
                    {
                    if (word5[i] == l) {
                            wordx[i] = l;
                            k = 1;// if I found a letter in  the word i add it in wordx on correct position and i remember k
                            x = 1;
                            }
                    }
                    guesscount++;
					guessletters[guesscount] = l;
					if (k==0) 
						lives--;
                    for (i=0;i<=we-1;i++) // check if my word = guessed word 
                    {
                        if (wordx[i] != word5[i]) x=0;
                    }
                    printf("\n");                  
                }
          if ((x == 0) || (lives <= 0)) 
			{
                        printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=we-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");     
			printf("Sorry you lost.\n");
			printf("The word was: ");
			for (i=0;i<=we-1;i++)
                    {
                        printf("%c ",word5[i]);
                    }
			printf("\nPlay again Y/N?\n");
			}
		  if (x == 1) 
		  {
            printf("Lives: %d \n", lives);
            printf("Word:");
            for (i=0;i<=we-1;i++)
                printf("%c ",wordx[i]);//prints the guessed word
            printf("\n");
            printf("Letters guessed so far :");
            for (i=0;i<=guesscount;i++)
                printf("%c, ",guessletters[i]);//display letters entered
            printf("\n");    
			printf("You Won!\n");
			printf("Play again Y/N?\n");
		  }
		  ver = 0;
		  while(ver==0)
		  {
		     l = getch();
		     if (((l != 'y') && (l != 'Y')) && ((l != 'n') && (l != 'N'))) 
             {
               printf("Please enter Y or N.\n");
             }
		     else {ver = 1;}
          }
		  
		  if ((l=='y')||(l=='Y')) {choice=1;}
		  if ((l=='n')||(l=='N')) {choice=2;}               
               
        break;       
        }//end switch2
		
	break;
		
	case 2: // exit
        status = 0;
	break;
}// end switch
}// end while
}// end main()
