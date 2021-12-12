//Summer Poissonnier
//November 22, 2019
//COP 2220 Prog 11 Pointers, Strings, Structs

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define SIZE 25
#define INVENTORYSIZE 100
#define SPEEDLIMIT 70.0

//struct type
typedef struct {
	int vin;
	char vehicleclass[SIZE];
	char make[SIZE];
	char model[SIZE];
	double mpg;
}car;

//function prototypes

//Greets the user
void Greeting(char fname[], char lname[]);

//fill the inventory with 4 cars
void FourCars(car inventory[]);

//input: car with data
//displays all the information of one car
void DisplayCar(car anyCar);

//prints the inventory of cars onto the screen
//use the Display car function
void PrintInventory(car inventory[], int count);

//prints the Menu options onto the screen
void MenuOptions();

//declare a temp car
//fills the data fields of a car one by one with user input
//return the filled car
car FillCar();

//Ask the user how many cars they want to add 
//add the cars to the inventory
//Use the Fillcar function
//update the count (by reference)
void AddCars(car inventory[], int *count);

//Display the VIN numbers and the car model
//ask the user which car they want to access
//find and return the location (index) by reference
//if the VIN number is not found in the array the index returned will be -1
void LocateCar(car inventory[], int count, int *index);


//Ask and get the number of miles for the trip
//Ask and get the price of gas at the pump
//Using the mpg field of the car,  calculate and print the 
//time it will take and the cost of gas
void RoadTrip(car inventory[], int index);


//remove the car from the inventory (3 POINT BONUS only if it is successful)
//update count (by reference) if a car was successfully removed
void RemoveCars(car inventory[], int index, int *count);

int main()
{
	//declare variables
	car inventory[INVENTORYSIZE];
	int count = 0;
	char option;
	int index;
	char fname[20],lname[20];
	FourCars(inventory);
	count = 4;

	//greet the user
	Greeting(fname, lname);

	//DisplayCar(inventory[3]);

	//PrintInventory(inventory, count);

	//present the menu choices
	MenuOptions();
	//ask and get menu choice
	scanf(" %c", &option);
	option = toupper(option);
	//printf("The option was %c", option);

	while (option!='Q')
	{
		//conditions for each choice
		if (option == 'P')
		{
			//displau cars in inventory
			printf("\nThese are the cars in the inventory:\n\n");
			PrintInventory(inventory, count);
		}
		else if (option == 'A')
		{
			printf("\nCar(s) have been returned\n\n");
			//printf("\nCall AddCars\n\n");
			AddCars(inventory, &count);
		}
		else if (option == 'R')
		{
			printf("\nA car has been rented\n\n");
		}
		else if (option == 'K')
		{
			//printf("\nCall locatecar\n\n");
			LocateCar(inventory, count, &index);
			//printf("\nCall roadtrip\n\n");
			RoadTrip(inventory, index);
		}
		else
		{
			printf("\n%s Please enter a (P) (A) (R) (K) or (Q)\n\n", fname);
		}
		//present the menu choices
		MenuOptions();
		//ask and get menu choice
		printf("\nWhat would you like to do?\n\n");
		scanf(" %c", &option);
		option = toupper(option);
	}
	printf("\nHave a nice day\n\n");
	return 0;
}

//function definitions

//Greets the user
void Greeting(char fname[], char lname[])
{
	printf("\nPlease enter your first name:\t");
	scanf(" %s", fname);
	printf("Please enter your last name:\t");
	scanf(" %s", lname);
	printf("\n\nWelcome %s %s to the rental car inventory\n\n", fname, lname);
	//describe the program
	printf("\nThis program manages an inventory of cars\n\n");
	printf("\nEach car has a unique integer VIN number\n\n");
	printf("\nThere are four cars already loaded into the array\n\n");
	printf("\nSelect (P) to see them\n\n");
	printf("\n***************************************************\n\n");
}

//fill the inventory with 4 cars
void FourCars(car inventory[])
{
	car temp1 = { 56, "Compact","Hyundai", "Accent",40.2 };
	inventory[0] = temp1;
	car temp2 = { 13,"Convertible","Ford","Mustang",30.3 };
	inventory[1] = temp2;
	car temp3 = { 17,"Premium","Mercedes","Benz",22.9 };
	inventory[2] = temp3;
	car temp4 = { 34,"Select_Series","Chevrolet","Corvette",19.1 };
	inventory[3] = temp4;
}

//input: car with data
//displays all the information of one car
void DisplayCar(car anyCar)
{
	printf("\nVIN number:\t %d", anyCar.vin);
	printf("\nVehicle class:\t %s", anyCar.vehicleclass);
	printf("\nMake:\t\t %s", anyCar.make);
	printf("\nModel:\t\t %s", anyCar.model);
	printf("\nMPG:\t\t %.2f\n\n", anyCar.mpg);
}


//prints the inventory of cars onto the screen
//use the Display car function
void PrintInventory(car inventory[], int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		DisplayCar(inventory[i]);
	}
}

//prints the Menu options onto the screen
void MenuOptions()
{
	printf("\nSelect an option:\n");
	printf("\n(P):\t Print the rental car inventory onto the screen\n\n");
	printf("\n(A):\t Add car(s) to the inventory\n\n");
	printf("\n(R):\t Remove a car from the inventory\n\n");
	printf("\n(K):\t Calculate the gas and time for a Road trip in the current inventory\n\n");
	printf("\n(Q):\t QUIT\n\n");
}

//declare a temp car
//fills the data fields of a car one by one with user input
//return the filled car
car FillCar()
{
	car temp;
	printf("\nEnter a VIN\n\n");
	scanf("%d",&temp.vin);
	printf("\nEnter a vehicle class\n\n");
	scanf(" %s", temp.vehicleclass);
	printf("\nEnter a make\n\n");
	scanf(" %s", temp.make);
	printf("\nEnter a model\n\n");
	scanf(" %s", temp.model);
	printf("\nEnter MPG\n\n");
	scanf("%lf", &temp.mpg);
	return temp;
}

//Ask the user how many cars they want to add 
//add the cars to the inventory
//Use the Fillcar function
//update the count (by reference)
void AddCars(car inventory[], int *count)
{
	int num, i;
	printf("\nHow many cars would you like to add?\n\n");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		inventory[*count] = FillCar();
		*count = *count + 1;
	}
}

//Display the VIN numbers and the car model
//ask the user which car they want to access
//find and return the location (index) by reference
//if the VIN number is not found in the array the index returned will be -1
void LocateCar(car inventory[], int count, int *index)
{
	printf("\nHere are the VIN numbers and car models available:\n\n");
	int i;
	for (i = 0; i < count; i++)
	{
		printf("\nModel: %s\t\t VIN: %d", inventory[i].model, inventory[i].vin);
	}
	printf("\nEnter the VIN number of the car you are trying to locate\t");
	scanf("%d", index);
	printf("\n%d\n\n",*index);
}

//Ask and get the number of miles for the trip
//Ask and get the price of gas at the pump
//Using the mpg field of the car,  calculate and print the 
//time it will take and the cost of gas
void RoadTrip(car inventory[], int index)
{
	double miles,price,gascost,time,minutes;
	int hours,minutes1;
	printf("\nHow many miles is your trip?\n\n");
	scanf("\n%lf", &miles);
	printf("\nWhat is the price of gas at the pump?\n\n");
	scanf("\n%lf", &price);
	gascost = (price*miles) / inventory[index].mpg;
	printf("\nThe cost of gas is %f", gascost);
	time = miles / SPEEDLIMIT;
	hours = (int)time;
	minutes = (time - (double)hours)*60.0;
	minutes1 = (int)minutes;
	printf("\nThe total time is %d hours and %d minutes", hours, minutes1);
}