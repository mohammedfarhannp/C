#include <stdio.h>
#include "input.h"

#define SIZE 10

int Stack[SIZE];
int ptr = 0;

int isFull(void);
int isEmpty(void);

void push(void);
void pop(void);
void display(void);

int main(int argc, char* argv[])
{
	int choice, run = 1;

	while (run)
	{
		choice = int_input("\n1 - Push\n2 - Pop\n3 - Display\n\n0 - Exit\n\nChoose: ");
		switch (choice)
		{
		case 0:
			run = 0;
			break;
		case 1:
			push();
			break;
		case 2:
			pop();
			break;
		case 3:
			display();
			break;
		default:
			printf("Invalid Choice\n");
			break;
		}
	}

	return 0;
}

int isEmpty() {
	return (ptr == 0);
}

int isFull() {
	return (ptr == SIZE);
}

void push(void)
{
	if (isFull())
	{
		printf("\n[!] Stack full!\n\n");
		return;
	}

	Stack[ptr] = int_input("Push element to Stack: ");
	ptr++;
}

void pop(void)
{
	if (isEmpty())
	{
		printf("\n[!] Stack Empty!\n\n");
		return;
	}

	ptr--;
}

void display(void)
{
	if (isEmpty())
	{
		printf("\n[!] Stack Empty!\n\n");
		return;
	}

	printf("[Stack Top]\n");
	for (int i = ptr - 1; i >= 0; i--)
	{
		printf(" %d \n", Stack[i]);
	}
	printf("[Stack Floor]\n");
}