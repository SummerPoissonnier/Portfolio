//Summer Poissonnier
//September 13, 2019
//COP2220 small program 3

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   //printf and scanf

int main()
{
	int number, number1, number2;
	int result,result1;
	char letter, letter1, letter2;

	printf("Hello, welcome to the number letter converter\n"); 
	//Ask what the user would like to do
	printf("\nWould you like to create a letter from a number (Enter 1)\n");   
	printf("\nOr would you like to create a number from a letter (Enter 2)\n\n");
	//scan a number (1 or 2) from the user
	scanf("%d", &number);

	//conditional statement
	if (number == 1)   
	{
		//ask for a number
		printf("\nEnter any number\n\n");
		//scan a number from the user
		scanf("%d", &number1);
		//convert number to letter
		letter = (char)number1;
		//display result
		printf("\n%d is the letter %c\n\n", number1, letter);
		//add ten to the number
		result = number1 + 10;
		//display the results
		printf("The result of %d + 10 is %d\n\n", number1, result);
		//convert the new number to a letter
		letter1 = (char)result;
		//display the result
		printf("%d is the letter %c\n\n", result, letter1);
	}
	else if (number == 2)
	{
		//ask for a letter
		printf("\nEnter any letter\n\n");
		//scan a letter from the user
		scanf(" %c", &letter2);
		//convert the letter to a number
		number2 = (int)letter2;
		//display result
		printf("\n%c is the number %d\n\n", letter2, number2);
		//add 15 to the new number
		result1 = number2 + 15;
		//display the results
		printf("The result of %d + 15 is %d\n\n", number2, result1);
		//convert new number to a letter
		letter2 = (char)result1;
		//display the result
		printf("%d is the letter %c\n\n", result1, letter2);
	}
	else
	{
		//if the user does not enter a 1 or 2
		printf("\nPlease enter a 1 or a 2\n\n");
	}
	return 0;
}