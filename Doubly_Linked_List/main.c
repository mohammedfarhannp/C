#include <stdio.h>
#include <malloc.h>
#include "input.h"

struct node {
	int data;
	struct node *previous, *next;
};

struct node* Head = NULL;

void Create(void);
void Insert(void);
void Display(void);
void Delete(void);
void Clean(void);

int main(int argc, char* argv[]) {
	int choice;
	while (1)
	{
		choice = int_input("\n1 - Create DLL\n2 - Insert to DLL\n3 - Display DLL\n4 - Delete from DLL\n\n0 - Exit\n\nSelect: ");
		if (choice == 0)
			break;
		switch (choice)
		{
		case 1:
			Create();
			break;
		case 2:
			Insert();
			break;
		case 3:
			Display();
			break;
		case 4:
			Delete();
			break;
		default:
			printf("Invalid Choice! Try Again!\n");
		}
	}
	Clean();
	return 0;
}

void Create(void)
{
	if (Head != NULL)
	{
		printf("Linked List already exists!\n");
		return;
	}

	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->data = int_input("Enter a numeric value for Head node: ");
	temp->next = NULL;
	temp->previous = NULL;

	Head = temp;
}

void Insert(void)
{
	if (Head == NULL)
	{
		printf("Linked List is empty! Create one first!\n");
		return;
	}

	int Key = int_input("Enter the value after which new item is to be inserted: ");

	struct node* temp = Head;
	
	while (temp != NULL)
	{
		if (temp->data == Key)
			break;
		temp = temp->next;
	}

	if (temp == NULL)
	{
		printf("value not found!\n");
		return;
	}

	struct node* new_node = (struct node*)malloc(sizeof(struct node));

	new_node->data = int_input("Enter a value for new node: ");
	
	new_node->next = temp->next;
	new_node->previous = temp;

	if(temp->next != NULL)
		temp->next->previous = new_node;
	temp->next = new_node;

}

void Display(void)
{
	if (Head == NULL)
	{
		printf("Linked List doesn't exist! Create one first!\n");
		return;
	}

	printf("\n -- Linked List Display -- \n");

	struct node* temp = Head;

	while (temp != NULL)
	{
		printf("[ %d ]", temp->data);
		if (temp->next != NULL)
		{
			printf("<--->");
		}
		temp = temp->next;
	}

	printf("\n -- Linked List Display -- \n");
}

void Delete(void)
{
	if (Head == NULL)
	{
		printf("Linked List doesn't exist! Create one first!\n");
		return;
	}

	int item = int_input("Enter the value you want to delete from linked list: ");

	struct node* temp = Head;
	struct node* var;

	while (temp != NULL)
	{
		if (temp->data == item)
			break;
		temp = temp->next;
	}

	if (temp == Head)
	{
		var = Head;
		Head = Head->next;
		Head->previous = NULL;
	} else {
		var = temp;
		temp->previous->next = temp->next;
		temp->next->previous = temp->previous;
	}
	free(var);
}

void Clean(void)
{
	if (Head == NULL)
		return;

	struct node* temp;

	while (Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		if (Head != NULL)
			Head->previous = NULL;
		free(temp);
	}
}