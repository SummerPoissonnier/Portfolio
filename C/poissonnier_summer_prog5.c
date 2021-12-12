//Summer Poissonnier
//September 26,2019
//COP2220 Large prog 5

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h> //for toupper and tolower

int main()
{
	int num, i, input, input1, count, sum = 0;
	double avg, avg1;
	char let, let2, let3;
	//Greet the user
	printf("Hello, welcome to the number/character converter\n\n");
	//Tell the user what will happen
	printf("ENTER 1 if you want to enter a number and find the corresponding character\n\n");
	printf("ENTER 2 if you want to enter a character and find the corresponding number\n\n");
	printf("ENTER 0 if you would like to quit\n\n");
	//Ask the user for a number
	scanf("%d", &num);
	while (num != 0) //loop to test if the user wants to continue
	{
		//if statement for when the user enters a 1
		if (num == 1)
		{
			printf("\nYou entered a 1\n\n");
			//ask and get how many times the user wants to do the program
			printf("How many numbers would you like to enter?\n\n");
			scanf("%d", &count);
			//counting loop for the number of times they want to do this
			for (i = 0; i < count; i++)
			{
				//get and ask a number to turn into a character
				printf("\nEnter a number to see the corresponding character\n\n");
				scanf("%d", &input);
				//convert number to character
				let = (char)input;
				printf("\n%d corresponds to %c\n\n", input, let);
				//calculate sum
				sum = sum + input;
			}
			//display sum on screen
			printf("The sum is %d\n\n", sum);
			//calculate average
			avg = ((double)sum) / count;
			//display average on screen
			printf("The average is %f\n\n", avg);
		}
		//if the user enters a 2
		else if (num == 2)
		{
			printf("\nYou entered a 2\n\n");
			//ask and get how many times they want to do the program
			printf("How many characters would you like to enter?\n\n");
			scanf("%d", &count);
			//counting loop for the amount of times they want to do it
			for (i = 0; i < count; i++)
			{
				//ask and get a character to turn into a number
				printf("\nEnter a character to see the corresponding number\n\n");
				scanf(" %c", &let);
				//convert character to upper and lowercase
				let2 = toupper(let);
				let3 = tolower(let2);
				printf("\nThe uppercase is %c and the lowercase is %c\n", let2, let3);
				//convert characters to integers
				input = (int)let2;
				input1 = (int)let3;
				printf("\n%c corresponds to %d\n\n", let2, input);
				printf("%c corresponds to %d\n\n", let3, input1);
				//calculate the sum of lowercase characters
				sum = sum + input1;
			}
			printf("The sum of the lowercase characters is %d\n\n", sum);
			//calculate average of lowercase characters
			avg = ((double)sum) / count;
			printf("The average of the lowercase characters is %f\n\n", avg);
		}
		//if the user does not enter a 0, 1, or 2
		else
		{
			printf("\nPlease enter a 0, 1, or 2\n\n");
		}
		//update
		printf("ENTER 1 if you want to enter a number and find the corresponding character\n\n");
		printf("ENTER 2 if you want to enter a character and find the corresponding number\n\n");
		printf("ENTER 0 if you would like to quit\n\n");
		//Ask the user for a number
		scanf("%d", &num);
	}
	//if the user enters a 0, program is done
	printf("\nGoodbye\n");
	return 0;
}
