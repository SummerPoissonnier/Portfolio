//Summer Poissonnier
//October 9,2019
//COP2220 Prog6 Functions

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> //printf and scanf

//Greeting fucntion, takes no arguments and void return type
void Function1();
//Takes no arguments and returns an integer
int Function2();
//takes one argument, the number input by the user and has a void return type
void Function3(int input1);
//takes one argument, the character input by the user and has a void return type
void Function4(char input2);

int main()
{
	int numberInput,input; 
	char letterInput;

	//call to function1
	Function1();
	//assign function2 a value because it returns an integer
	numberInput = Function2();

	//if statement to test the user input
	if (numberInput == 1)
	{
		printf("\nEnter a number: ");
		scanf("%d", &input);
		//call to function3
		Function3(input);
	}
	//tests the user input
	else if (numberInput == 2)
	{
		printf("\nEnter a character: ");
		scanf(" %c", &letterInput);
		//call to function4
		Function4(letterInput);
	}
	else
	{
		//if the user enters anything other than 1 or 2
		printf("Please enter a 1 or a 2");
	}
	
	return 0;
}

//Greeting
void Function1()
{
	//move the greeting code to function 1
	printf("Hello, welcome to the number letter converter\n\n");
}

//asks and gets what the user wants to do
int Function2()
{
	int userChoice;
	printf("(ENTER 1) -- To enter a number and find the corresponding character\n");
	printf("(ENTER 2) --To enter a character and find the numerical value\n");
	scanf("%d", &userChoice);
	//return the number that was entered by the user
	return userChoice;
}

//converts numbers to letters
void Function3(int input1)
{
	char let, let1;
	int number2;
	let = (char)input1;
	number2 = input1 + 10;
	let1 = (char)number2;
	printf("\nThe number entered was %d and the corresponding character is %c", input1, let);
	printf("\nThe new number (plus 10) is %d and the corresponding character is %c", number2, let1);
}

//converts letters to numbers
void Function4(char input2)
{
	char newLetter;
	int newNum, newNum2;
	newNum = (int)input2;
	newNum2 = newNum + 15;
	newLetter = (char)newNum2;
	printf("\nThe letter entered was %c and the corresponding number is %d", input2, newNum);
	printf("\nThe new number (plus 15) is %d and the corresponding character is %c", newNum2, newLetter);
}
