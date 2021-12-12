//Summer Poissonnier
//November 11, 2019
//COP2220 Prog 10 Pointers

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SPEEDLIMIT 70

//greet the user
void Greeting();

//Calculations for one roadtrip
void CalculateTheTotal();

//get input 1 to continue 0 to stop
//return by refernce the user's choice
void AnotherRoadTrip(int *againPtr);

//calculate cost of gas
//get price per gallon and mpg
//calculate and return by reference cost of gas
void GasCost(double miles, double *gasCostPtr);

//using 70 mph and miles passed to the function
//calculate and return by refernce total time as a double
//calculate and print number of hours and number of minutes
void TripTime(double miles, double *totalTimePtr);

int main()
{
	int yesOrNo;

	//call greeting function
	Greeting();

	//loop
	do {
		CalculateTheTotal();
		AnotherRoadTrip(&yesOrNo);
	} while (yesOrNo != 0); //loop test

	//say goodbye
	printf("\nHave a great trip\n\n");

	return 0;
}

void Greeting()
{
	//greet
	printf("\nWelcome to the road trip calculator!\n\n");
	printf("The calculations are based on an average speed of 70 MPH\n\n");
}

//Calculations for one roadtrip
void CalculateTheTotal()
{
	double mileInput, costOfGas, time;
	
	//ask and get miles
	printf("How many miles is your trip?\n\n");
	scanf("%lf", &mileInput);

	//gas cost
	GasCost(mileInput, &costOfGas);

	//time
	TripTime(mileInput, &time);
}

//get input 1 to continue 0 to stop
//return by refernce the user's choice
void AnotherRoadTrip(int *againPtr)
{
	printf("Another trip? (0) to stop (1) to continue:\n\n");
	scanf("%d", againPtr);
}

//calculate cost of gas
//get price per gallon and mpg
//calculate and return by reference cost of gas
void GasCost(double miles, double *gasCostPtr)
{
	double price, mpg;

	//ask and get price
	printf("\nWhat is the price of gas per gallon at the pump?\n\n");
	scanf("%lf", &price);

	//ask and get how many miles
	printf("\nHow many miles can you go on a gallon of gas?\n\n");
	scanf("%lf", &mpg);

	//loop for total gascost
	if (mpg > 0)
	{
		*gasCostPtr = (price*miles) / mpg;
	}
	printf("\nThe cost of gas is $ %.2lf\n\n", *gasCostPtr);
}

//using 70 mph and miles passed to the function
//calculate and return by refernce total time as a double
//calculate and print number of hours and number of minutes
void TripTime(double miles, double *totalTimePtr)
{
	int hours, minutesINT;
	double minutes;

	//calculate travel time
	*totalTimePtr = miles / SPEEDLIMIT;

	//get hours
	hours = (int)*totalTimePtr;

	//get minutes as a double
	minutes = (*totalTimePtr - (double)hours)*60.0;

	//change minutes to an integer
	minutesINT = (int)minutes;
	printf("It will take %d hours and %d minutes\n\n", hours, minutesINT);
}