#include <stdio.h>
#include "input.h"
#include <malloc.h>

#define ROW_SIZE 3
#define COL_SIZE 3
#define PAGES 3

int* Array_Ptr = NULL;

int Calc_Pos(int, int, int);
void Display(void);

int main(int argc, char* argv[])
{
	Array_Ptr = (int*)malloc(sizeof(int) * COL_SIZE * ROW_SIZE * PAGES);
	int tp = 1, tr = 1, tc = 1;

	for (int i = 0; i < ROW_SIZE * COL_SIZE * PAGES; i++)
	{
		if (i != 0 && i % ((COL_SIZE * ROW_SIZE)) == 0)
		{
			tr = 0;
			tp++;
		}
		if (tc % (COL_SIZE + 1) == 0)
		{
			tc = 1;
			tr++;
		}
		
		printf("Enter page %d, row %d, column %d", tp, tr, tc);
		Array_Ptr[i] = int_input(" element of Array: ");
		tc++;
	}

	int choice, run = 1, x, y, z;

	while (run)
	{
		choice = int_input("\n1 - Display Array\n2 - Find Element using page number, column number and row number\n\n0 - Exit\n\nChoose: ");
		switch (choice)
		{
		case 0:
			run = 0;
			break;

		case 1:
			Display();
			break;

		case 2:
			x = int_input("Enter the Page Number : ");
			y = int_input("Enter the Row Number : ");
			z = int_input("Enter the Column Number : ");

			printf("\nThe element at Page %d, Row %d, and Column %d is %d", x, y, z, Array_Ptr[Calc_Pos(x,y,z)]);
			break;

		default:
			printf("Invalid Choice\n");
			break;
		}
	}

	free(Array_Ptr);
	return 0;
}

int Calc_Pos(int x, int y, int z)
{
	return ((x - 1) * ROW_SIZE * COL_SIZE) + ((y - 1) * ROW_SIZE) + (z - 1);

}

void Display(void)
{
	printf("\n");
	int pg = 1;
	for (int i = 0; i < PAGES * ROW_SIZE * COL_SIZE; i++)
	{
		if (i % (ROW_SIZE * COL_SIZE) == 0)
		{
			printf("\n------PAGE %d-------\n", pg);
			pg++;
		}
		if (i % ROW_SIZE == 0)
			printf("\n");

		printf(" %d", Array_Ptr[i]);
	}
	printf("\n");
}