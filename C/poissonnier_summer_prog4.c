//Summer Poissonnier
//September 9,2019
//COP2220 Prog 4

#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

int main()
{
	int num,num1,num2;
	int count = 0;
        int sum = 0;
	char letter,letter1,letter2;

	printf("Hello, let's find out the numerical value of lower and uppercase letters\n");  
	printf("and/or keyboard characters\n\n");
	printf("How many characters would you like to enter?\n\n");   //ask the user
	scanf("%d", &num);   //get number from user

	for (count=1; count<=num; ++count ) //creates a counting loop
	{
		printf("\nPlease enter a letter\n\n");   //asks for letter
		scanf(" %c", &letter);     //gets a letter from user
		letter1 = toupper(letter); //changes original letter to uppercase
		printf("\nThe uppercase version of the letter is %c\n", letter1);   //displays new letter on screen
		num1 = (int)letter1;   //changes new letter to integer
		printf("\n%c is %d as an integer\n", letter1, num1);   //displays the new letter as an integer
		letter2 = tolower(letter);   //changes original letter to lowercase
		printf("\nThe lowercase version of the letter is %c\n", letter2); //displays new letter on screen
		num2 = (int)letter2;  //changes new letter to an integer
		printf("\n%c is %d as an integer\n", letter2, num2);  //displays new letter as an integer
		printf("\n%c is %d as an integer and %c is %d as an integer\n", letter1, num1, letter2, num2);
	}
	return 0;
}