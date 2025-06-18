#include <stdio.h>
#include "input.h"
#include <malloc.h>

#define ROW_SIZE 3
#define COL_SIZE 3

int* Array_Ptr = NULL;

int Calc_Pos(int, int);
void Display(void);

int main(int argc, char* argv[])
{
	Array_Ptr = (int*)malloc(sizeof(int) * COL_SIZE * ROW_SIZE);
	int tr = 1, tc = 1;
	for (int i = 0; i < ROW_SIZE * COL_SIZE; i++)
	{
		if (tc % (COL_SIZE+1) == 0)
		{
			tc = 1;
			tr++;
		}
		printf("enter row %d column %d th", tr, tc);
		Array_Ptr[i] = int_input(" element of Array: ");
		tc++;
	}

	int choice, run = 1, x, y;

	while (run)
	{
		choice = int_input("\n1 - Display Array\n2 - Find element using row and col number\n\n0 - Exit\n\nChoose: ");
		switch (choice)
		{
		case 1:
			Display();
			break;

		case 2:
			x = int_input("\nEnter the row number: ");
			y = int_input("\nEnter the col number: ");
			printf("\nThe element at row %d and column %d is %d\n", x, y, Array_Ptr[Calc_Pos(x,y)]);
			break;

		default:
			printf("Invalid Choice!\n");
		}
	}

	free(Array_Ptr);
	return 0;
}

int Calc_Pos(int x, int y)
{
	return ((x-1) * ROW_SIZE) + (y-1);
}

void Display(void)
{
	printf("\n");
	for (int i = 0; i < ROW_SIZE * COL_SIZE; i++)
	{
		if(i != 0 && i % ROW_SIZE == 0)
			printf("\n");

		printf(" %d", Array_Ptr[i]);
	}
	printf("\n");
}