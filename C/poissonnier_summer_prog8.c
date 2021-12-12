//Summer Poissonnier
//October 28, 2019
//COP2220 Prog 8, functions, arrays, and strings

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Greet the user and explain the game
void Greeting(char name[]);

//Get the guess
int GetGuess(char scrambled[], char solution[], char name[]);


//compare if the guess matches or not
int Compare(char solution[], char guess[], char name[]);

//change word to uppercase
void UpperCaseWord(char word[]);

int main()
{
	char solution[25], scrambled[25];
	char name[25];
	FILE *inPtr;
	char let;
	int num;

	//ask and get the name
	printf("What is your name?\n\n");
	scanf(" %s", name);
	//greet the user
	Greeting(name);
	//open the file
	inPtr = fopen("input.txt", "r");

	//loop to have the user play the game
	do{
		//scan into the file
		fscanf(inPtr, "%s", scrambled);
		//change scrambled work to uppercase
		UpperCaseWord(scrambled);
		fscanf(inPtr, "%s", solution);
		//change soluton word to uppercase
		UpperCaseWord(solution);

		//compare to see if they guessed correctly
		num = GetGuess(scrambled, solution, name);

		//if they did not guess correctly if statement
		if (num == 2)
		{
			//give a hint
			printf("\nHere is a hint, the first letter is: %c\n", solution[0]);
			//call to guess function again
			num = GetGuess(scrambled, solution, name);
			//display solution
			printf("\nThe solution is %s\n\n", solution);
		}

		//ask if they want to play again
		printf("Again?\n\n");

		//update
		scanf(" %c", &let);
		let = toupper(let);
	} while (let == 'Y');

	//say goodbye
	printf("\nGoodbye\n\n");
	return 0;
}

//greeting function takes in one argument (name) and returns nothing
//explain the game
void Greeting(char name[])
{
	printf("\nHello %s \n", name);
	printf("\nToday we will be playing a game where you will try to guess a scrambled word\n");
	return 0;
}

//guess function takes in three arguments and returns an integer
//gets the guess and compares it to solution
int GetGuess(char scrambled[], char solution[], char name[])
{
	char guess[25];
	int num;
	printf("\nGuess this word:\n\n");
	printf("%s\n\n", scrambled);
	scanf(" %s", guess);
	UpperCaseWord(guess);
	UpperCaseWord(solution);
	num = Compare(solution, guess,name);
	return num;
}

//compare function takes in three arguments and returns an integer
//compares the solution with guess
int Compare(char solution[], char guess[], char name[])
{
	if (strcmp(solution, guess) == 0)
	{
		printf("\nCorrect\n\n");
		return 1;
	}
	else
	{
		return 2;
	}
}

//uppercase function takes in one argument and returns nothing
//changes words to uppercase
void UpperCaseWord(char word[])
{
	int i, len;
	len = strlen(word);
	for (i = 0; i < len; i++)
	{
		word[i] = toupper(word[i]);
	}
}