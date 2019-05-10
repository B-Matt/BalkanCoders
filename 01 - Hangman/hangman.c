/*
 *  Copyright Balkan Coders, 2019.
 *  Author: Matej Arlović
 *  Date: 09/05/2019.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int SearchGameWord(char inputChar, char gameWord[])
{
	for(int i = 0; i < 8; i++)
	{
		if(gameWord[i] == inputChar)
		{
			return i;
		}
	}
	return -1;
}



int main()
{
    char inputWord[8];
    char helpWord[8];
    char fullWord[8];
    
    char inputLetter;
    
    int playerHits = 0;
    int playerErrors = 0;
    
    bool isGameOver = false;
    bool isGameWon = false;
    
    // PRVI SEGMENT - Unos rijeci za igru
	do 
	{
	    printf("Unesite rijec za igru (max. 8 znakova): ");
	    scanf("%s", inputWord);
	} 
	while(strlen(inputWord) < 2 || strlen(inputWord) > 7);
	
	// DRUGI SEGMENT - Postavljanje pomocne rijeci
	for(int i = 0; i < 8; i++)
    {
        if(inputWord[i] != '\0')
        {
            helpWord[i] = '#';
            fullWord[i] = inputWord[i];
        }
    }
	
	// TRECI SEGMENT - Igracka petlja
	do
	{
	    system("cls");                                                        // system("clear") ukoliko koristite Linux!
	    PrintHangmanTree(playerErrors);
	    printf("POMOC: %s\n", helpWord);
	    
	    printf("Unesite slovo: ");
	    inputLetter = getchar();	    
	    if(inputLetter == 10)
	    {
	    	continue;
		}
		
	    int letterIndex = SearchGameWord(inputLetter, inputWord);		    
	    if(letterIndex != -1)
	    {
		   	helpWord[letterIndex] = inputWord[letterIndex];
	    	inputWord[letterIndex] = '#';
	    	playerHits++;
	    	if(playerHits >= strlen(fullWord))
	    	{
	    		isGameWon = true;
				isGameOver = true;
			}
		}
		else
		{
			playerErrors++;
		    if(playerErrors >= 6)
		    {
		        isGameOver = true;
		    }
		}
	}
	while(!isGameOver);
	
	// CETVRTI SEGMENT - Prikaz gotovog stabla
	system("cls");
	if(isGameWon)
	{
		printf("POBJEDILI STE!\n");
	}	
	PrintHangmanTree(playerErrors);
	printf("CIJELA RIJEC: %s\n", fullWord);
	return 0;
}
