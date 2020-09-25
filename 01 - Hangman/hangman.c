/*
 *  Copyright Balkan Coders, 2020.
 *  Author: Matej Arlović
 *  Date: 25/09/2019.
 *  Web: themastergames.com
 */

// Link Section
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global Declaration Section
void PrintHangmanTree(int errors);

int SearchGameWord(char inputChar, char gameWord[]);

// Main Function Section
int main()
{
    char inputWord[8];
    char helpWord[8];
    char fullWord[8];
    
    char inputLetter;
    
    int playerHits = 0;
    int playerErrors = 0;
    
    int isGameOver = 0;
    int isGameWon = 0;
    
    // Game word input
	do 
	{
	    printf("Input game word (max. 8 chars): ");
	    scanf("%s", inputWord);
	} 
	while(strlen(inputWord) < 2 || strlen(inputWord) > 7);
	
	// Rendering help word
	for(int i = 0; i < 8; i++)
    {
        if(inputWord[i] != '\0')
        {
            helpWord[i] = '#';
            fullWord[i] = inputWord[i];
        }
    }
	
	// Game loop
	do
	{
	    system("cls");                                                        // system("clear") if you use Linux!
	    PrintHangmanTree(playerErrors);
	    printf("HELP: %s\n", helpWord);
	    
	    printf("Input character: ");
	    inputLetter = getchar();	    
	    if(inputLetter == 10)
	    {
	    	continue;
		}
		
	    int letterIndex = SearchGameWord(inputLetter, inputWord, strlen(inputWord));		    
	    if(letterIndex != -1)
	    {
		   	helpWord[letterIndex] = inputWord[letterIndex];
	    	inputWord[letterIndex] = '#';
	    	playerHits++;
			
	    	if(playerHits >= strlen(fullWord))
	    	{
	    		isGameWon = 1;
				isGameOver = 1;
			}
		}
		else
		{
			playerErrors++;
			
		    if(playerErrors >= 6)
		    {
		        isGameOver = 1;
		    }
		}
	}
	while(isGameOver == 0);
	
	// After game ends
	system("cls");
	if(isGameWon == 1)
	{
		printf("You won!\n");
	}	
	PrintHangmanTree(playerErrors);
	printf("WHOLE WORD: %s\n", fullWord);
	return 0;
}

// Subprogram Section
void PrintHangmanTree(int errors)
{
	printf("__________________\n");
	printf("|\t\t |\n");
	printf("|\t\t |\n");
	
	switch(errors)
	{
	    case 0:
	    {
        	printf("|\n|\n|\n|\n|\n|\n");
        	break;
	    }
	    case 1:
		{
			printf("|\t\t O\n");
			printf("|\n|\n|\n|\n|\n\n");
			break;
		}
		case 2:
		{
			printf("|\t\t O\n");
			printf("|\t\t/\n");
			printf("|\n|\n|\n|\n");
			break;
		}
		case 3:
		{
			printf("|\t\t O\n");
			printf("|\t\t/X\n");
			printf("|\n|\n|\n|\n");
			break;
		}
		case 4:
		{
			printf("|\t\t O\n");
			printf("|\t\t/X\\\n");
			printf("|\n|\n|\n|\n");
			break;
		}
		case 5:
		{
			printf("|\t\t O\n");
			printf("|\t\t/X\\\n");
			printf("|\t\t/\n");
			printf("|\n|\n|\n");
			break;
		}
		case 6:
		{
			printf("|\t\t O\n");
			printf("|\t\t/X\\\n");
			printf("|\t\t/ \\\n");
			printf("|\n|\n|\n");
			break;
		}
	}
}

int SearchGameWord(char inputChar, char gameWord[], int wordSize)
{
	for(int i = 0; i < wordSize; i++)
	{
		if(gameWord[i] == inputChar)
		{
			return i;
		}
	}
	return -1;
}
