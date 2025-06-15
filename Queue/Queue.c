#include <stdio.h>
#include "input.h"

#define MAX_SIZE 10

int Queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty(void);
int isFull(void);
void enqueue(void);
void dequeue(void);
void display(void);
void reset_ptrs(void);

int main(int argc, char* argv[])
{
	int choice, run=1;

	while (run)
	{
		choice = int_input("\n1 - Enqueue\n2 - Dequeue\n3 - Display\n\n0 - Exit\n\nChoose: ");
		switch (choice)
		{
		case 1:
			enqueue();
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 0:
			run = 0;
			break;

		default:
			printf("Invalid choice!\n");
			break;
		}

	}

	return 0;
}

int isEmpty(void) {
	return (front == rear);
}

int isFull(void)
{
	return (rear == MAX_SIZE);
}

void reset_ptrs(void)
{
	front = -1;
	rear = -1;
}

void enqueue(void)
{
	if (isFull())
	{
		printf("\n[!] Queue Full!\n");
		return;
	}

	if (isEmpty())
	{
		front = 0;
		rear = 0;
	}

	Queue[rear] = int_input("Enter Item to be Enqueued: ");
	rear++;
}

void dequeue(void)
{
	if (isEmpty())
	{
		printf("[!] Queue Empty!\n");
		reset_ptrs();
		return;
	}

	front++;
}

void display(void)
{
	printf("[QUEUE REAR]\n");
	for (int i = rear-1; i >= front; i--)
	{
		printf(" %d \n", Queue[i]);
	}
	printf("[QUEUE FRONT]\n");
}