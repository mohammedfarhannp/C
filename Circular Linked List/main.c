#include <stdio.h>
#include <malloc.h>
#include "input.h"

struct node {
	int data;
	struct node* next;
};

struct node* Head = NULL;

void Create(void);
void Insert(void);
void Display(void);
void Delete(void);
void Clean(void);

int main(int argc, char* argv[])
{
	int choice, run=1;
	while (run)
	{
		choice = int_input("\n1 - Create linked list\n2 - Insert to linked list\n3 - Display linked list\n4 - Delete from linked list\n\n0 - Exit\n\nChoose: ");
		switch (choice)
		{
		case 0:
			run = 0;
			break;
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
		printf("Linked List Already Exists!\n\n");
		return;
	}

	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->data = int_input("Enter value for Head node of linked list: ");
	temp->next = NULL;

	Head = temp;
	Head->next = Head;
}

void Insert(void) {
	if (Head == NULL)
	{
		printf("Linked List doesn't exist!\n\n");
		return;
	}

	int Key = int_input("Enter a value of node after which new node is to be inserted: ");
	struct node* temp = Head;

	do {
		if (temp->data == Key)
		{
			struct node* new_node = (struct node*)malloc(sizeof(struct node));
			new_node->data = int_input("Enter value of new node: ");

			new_node->next = temp->next;
			temp->next = new_node;
			printf("New Node added successfully\n");
			return;
		}	
		temp = temp->next;
	} while (temp != Head);
	printf("Node not found!\n\n");
	
}

void Display(void)
{
	if (Head == NULL)
	{
		printf("Linked List Doesn't Exist!\n");
		return;
	}

	struct node* temp = Head;

	printf("-- Linked List --\n\n");
	do {
		printf("-->[%d]", temp->data);
		temp = temp->next;
	} while (temp != Head);
	printf("-->\n\n-- Linked List --\n");
}

void Delete(void) {
	if (Head == NULL)
	{
		printf("No Linked List Exists!\n\n");
		return;
	}

	int Item = int_input("Value of node to delete: ");
	
	struct node* temp = Head, * previous = NULL;

	if (Head->next == Head)
	{
		if (Head->data == Item)
		{
			free(Head);
			Head = NULL;
			printf("Linked List Deleted Successfully!\n\n");
		} else {
			printf("Node not found!\n\n");
		}
		return;
	}

	do {
		if (temp->data == Item)
			break;
		previous = temp;
		temp = temp->next;
	} while (temp != Head);

	if (temp->data != Item)
	{
		printf("Node not found!\n\n");
		return;
	}

	if (temp == Head)
	{
		struct node* last = Head;
		while (last->next != Head)
			last = last->next;
		last->next = Head->next;
		Head = Head->next;
		free(temp);

	} else {
		previous->next = temp->next;
		free(temp);
	}

	printf("Node deleted successfully!\n\n");
}

void Clean(void) {
	
	if (Head == NULL) return;

	struct node* temp = Head;
	struct node* last = Head;

	while (last->next != Head)
		last = last->next;
	last->next = NULL;

	while (Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		free(temp);
	}

}