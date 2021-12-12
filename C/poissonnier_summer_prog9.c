//Summer Poissonnier
//November 8, 2019
//COP2220 Prog 9 Structs

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> //printf and scanf
#include <string.h> //strlen and strcmp

typedef struct {
	char name[20];
	char color[10];
	double price;
	int id;
}vegetable;

//ask and get name
//explain program
void Greeting(char name[]);

//declare a temp vegetable
//fills the data fields of vegetable one by one
//return the filled vegetable
vegetable FillVegetable();

//input: vegetable with data
//displays all info
void DisplayVegetable(vegetable temp);

int main()
{
	//declare struct data type
	vegetable v1, v2, v3, v4;
	vegetable v5 = { "Carrot","Orange",3.00,123 };
	char name[20];

	//assign value to data
	strcpy(v1.name, "Spinach");
	strcpy(v1.color, "Green");
	v1.price = 2.00;
	v1.id = 203;

	//call to greeting function
	Greeting(name);

	//fill vegebtales with data by assigning them to FillVegetable function
	v2 = FillVegetable();
	v3 = FillVegetable();
	v4 = FillVegetable();

	printf("\nThe five vegetables are:\n\n");
	//Display each vegetable by calling to DisplayVegetable function
	DisplayVegetable(v1);
	DisplayVegetable(v2);
	DisplayVegetable(v3);
	DisplayVegetable(v4);
	DisplayVegetable(v5);

	//say gooodbye
	printf("\nThanks %s, goodbye\n\n", name);
	return 0;
}

//ask and get name
//explain program
void Greeting(char name[])
{
	printf("What is your name\n\n");
	scanf(" %s", name);
	printf("\nHello %s, welcome to the vegetable program\n\n",name);
	printf("A vegetable has a name, color, price, and id\n\n");
}

//declare a temp vegetable
//fills the data fields of vegetable one by one
//return the filled vegetable
vegetable FillVegetable()
{
	vegetable temp;
	printf("\nEnter a name\n\n");
	scanf(" %s", temp.name);
	printf("\nEnter a color\n\n");
	scanf(" %s", temp.color);
	printf("\nEnter a price\n\n");
	scanf("%lf",&temp.price);
	printf("\nEnter an id\n\n");
	scanf("%d", &temp.id);
	return temp;
}

//input: vegetable with data
//displays all info
void DisplayVegetable(vegetable temp)
{
	printf("\nThe name is:\t %s", temp.name);
	printf("\nThe color is:\t %s", temp.color);
	printf("\nThe price is:\t $%.2f", temp.price);
	printf("\nThe id is:\t %d", temp.id);
	printf("\n*********************************\n");
}