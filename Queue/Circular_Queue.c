#include <stdio.h>
#include "input.h"

#define MAX_SIZE 10

int Queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty(void);
int isFull(void);

void Enqueue(void);
void Dequeue(void);
void Display(void);

int main(int argc, char* argv[])
{
	int choice, run = 1;

	while (run)
	{
		choice = int_input("\n1 - Enqueue\n2 - Dequeue\n3 - Display\n\n0 - Exit\n\nChoose: ");
		switch (choice)
		{
		case 0:
			run = 0;
			break;

		case 1:
			Enqueue();
			break;

		case 2:
			Dequeue();
			break;

		case 3:
			Display();
			break;

		default:
			printf("Invalid choice!");
			break;
		}
	}
	return 0;
}

int isEmpty(void)
{
	return (front == -1);
}

int isFull(void)
{
	return ((rear + 1) % MAX_SIZE == front);
}

void Enqueue(void)
{
	if (isFull())
	{
		printf("\n[!] Queue is Full!\n\n");
		return;
	}
	else if (isEmpty())
	{
		front = 0;
		rear = 0;
	}
	else {
		rear = (rear + 1) % MAX_SIZE;
	}

	Queue[rear] = int_input("Enter item to be enqueued: ");
}

void Dequeue(void) {
	if (isEmpty())
	{
		printf("\n[!] Queue Empty!\n\n");
		return;
	}

	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else {
		front = (front + 1) % MAX_SIZE;
	}
}

void Display(void)
{
	if (isEmpty())
	{
		printf("\n[!] Queue Empty\n\n");
		return;
	}

	int i = rear;

	printf("[Rear]");
	while (1)
	{
		printf(" %d ", Queue[i]);
		if (i == front)
			break;
		printf("|");
		i = (i - 1 + MAX_SIZE) % MAX_SIZE;
	}
	printf("[Front]\n");
}