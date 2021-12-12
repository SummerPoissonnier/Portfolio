//Summer Poissonnier
//September 9,2019
//COP2220 small program 2 (prog2.c)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   //printf and scanf
#include <ctype.h>  //toupper and tolower

int main()
{
	char letter, letter1;
	int number, number2;
	int result, result2;

	printf("My name is Summer\n");

	//Ask the user for a letter
	printf("\nPlease enter a letter\n\n");  
	//Scan the letter from the user
	scanf(" %c", &letter);  

	//redisplay the original letter onto the screen
	printf("\nThe original letter is %c\n", letter);

	//Make the letter uppercase
	letter1 = toupper(letter);                         
	printf("\nThe uppercase letter is %c\n", letter1);

	//Change the uppercase letter to an integer
	number = (int)letter1;
	//Print what the integer is
	printf("\n%c as an integer is %d\n", letter1, number);
        //Calculate the result of the integer times 10
	result = 10 * (number);
	//Display the result onto the screen
	printf("\nThe result of 10*%d is %d\n", number, result);

	//Change the original letter to an integer
	number2 = (int)letter;
	//Display the new integer onto the screen
	printf("\n%c as an integer is %d\n", letter, number2);
	//Calculate the result of the new integer times 10
	result2 = 10 * (number2);
	//Display the result onto the screen
	printf("\nThe result of 10*%d is %d\n", number2, result2);

	return 0;
}