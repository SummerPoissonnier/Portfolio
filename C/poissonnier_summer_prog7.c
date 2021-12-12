//Summer Poissonnier
//October 18,2019
//Small Prog 7 Arrays and File Processing

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //printf and scanf
#include <ctype.h> //upper and lower
#include <string.h> //strlen and strcmp

//Greet user and explain game
//input: the user's first name
void Greeting(char name[]);

//input: 2 char arrays (solution, guess)
//returns (1) if match and (2) if they don't match
int CheckTheGuess(char solutionWord[], char guess[]);

//input: char array
//result (by reference): char array with all uppercase letters
void UpperCaseWord(char word[]);

int main()
{
	char solutionWord[25],scrambledWord[25];
	char guess[25];
	char name[25];
	FILE *inPtr;
	int num;

	//Ask and get name
	printf("Please enter your name\n\n");
	scanf(" %s", name);
	//call the greeting function
	Greeting(name);

	//connect to the file
	inPtr = fopen("input.txt", "r");
	//get the solution word using fscanf
	fscanf(inPtr, "%s", solutionWord);
	//call to uppercase function
	UpperCaseWord(solutionWord);
	//ask to guess the scrambled word
	printf("Try to guess this word:\n");
	//scan in the scrambled word from the file
	fscanf(inPtr, "%s", scrambledWord);
	UpperCaseWord(scrambledWord);
	printf("\n%s\n\n", scrambledWord);
	//close the file
	fclose(inPtr);
	//get for the guess
	scanf(" %s", guess);
	//call to uppercase function
	UpperCaseWord(guess);
	printf("\nYou guessed %s\n", guess);

	//call to the guess-solution comparison function
	num = CheckTheGuess(solutionWord, guess);
	printf("\nGoodbye\n");
	return 0;
}

//greet user and explain the game
void Greeting(char name[])
{
	printf("\nHello %s\n", name);
	printf("\nToday we will be playing a game\n");
	printf("\nYou will have only one try to guess a scrambled word\n\n");
}

//return a 1 or a 2 if the answer matches or not
int CheckTheGuess(char solutionWord[], char guess[])
{
	//compare the solution with the guess
	if (strcmp(solutionWord, guess) == 0)
	{
		printf("\nYou are correct\n");
		return 1;
	}
	else
	{
		printf("\nYou are wrong\n");
		printf("\nThe solution word was %s\n", solutionWord);
		return 2;
	}
}

//char array with all capital letters
void UpperCaseWord(char word[])
{
	//change the word to an uppercase word
	int len,i;
	len = strlen(word);
	for (i = 0; i < len; i++)
	{
		word[i] = toupper(word[i]);
	}
}