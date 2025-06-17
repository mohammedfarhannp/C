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
void Delete(void);
void Display(void);
void Reverse(void);


int main(int argc, char* argv[])
{
	int choice, run = 1;

	while (run)
	{
		choice = int_input("\n1 - Create Linked List\n2 - Insert to Linked List\n3 - Delete from Linked List\n4 - Display Linked List\n5 - Reverse Linked List\n\n0 - Exit\n\nChoose: ");
		switch (choice)
		{
		case 1:
			Create();
			break;
		case 2:
			Insert();
			break;
		case 3:
			Delete();
			break;
		case 4:
			Display();
			break;
		case 5:
			Reverse();
			break;
		case 0:
			run = 0;
			break;
		default:
			printf("Invalid Choice\n");
		}
	}
	return 0;
}

void Create(void)
{
	if (Head != NULL)
	{
		printf("[-] Linked List already exists! [-]\n");
		return;
	}

	struct node* temp = (struct node*)malloc(sizeof(struct node));
	
	temp->data = int_input("Enter number for Head node of the Linked List: ");
	temp->next = NULL;

	Head = temp;
	printf("[+] Linked List Created Successfully [+]\n");
}

void Insert(void) {
	if (Head == NULL)
	{
		printf("[-] Linked List doesn't exist! Create one! [-]\n");
		return;
	}

	int Key = int_input("Enter the value of node after which new node is to be inserted: ");

	struct node* temp = Head;
	while (temp != NULL)
	{
		if (temp->data == Key)
		{
			struct node* new_node = (struct node*)malloc(sizeof(struct node));
			new_node->data = int_input("Enter the value of new node: ");
			new_node->next = temp->next;
			temp->next = new_node;
			printf("[+] New Node Added successfully [+]\n");
			return;
		}
		temp = temp->next;
	}

	printf("[-] Node not found [-]\n");
}

void Display(void)
{
	if (Head == NULL)
	{
		printf("[-] Linked List doesn't exist! Create one! [-]\n");
		return;
	}

	printf("\n[LINKED LIST]\n");
	struct node* temp = Head;
	while (temp != NULL)
	{
		printf("[%d]", temp->data);
		if (temp->next != NULL)
			printf(" --> ");
		temp = temp->next;
	}
	printf("\n[LINKED LIST]\n");
}

void Delete(void)
{
	if (Head == NULL)
	{
		printf("[-] Linked List doesn't exist! Create one! [-]\n");
		return;
	}

	int Key = int_input("Enter the value of node to be deleted: ");

	struct node* temp = Head;
	struct node* previous = NULL;
	while (temp != NULL)
	{
		if (temp->data == Key)
		{
			if (temp == Head)
			{
				Head = Head->next;
			}
			else {
				previous->next = temp->next;
			}
			free(temp);
			printf("[+] Node Deleted Successfully [+]\n");
			return;
		}
		previous = temp;
		temp = temp->next;
	}
	printf("[-] Node not found [-]\n");
}

void Reverse(void)
{
	if (Head == NULL)
	{
		printf("[-] Linked List doesn't exist! Create one! [-]\n");
		return;
	}

	struct node* previous = NULL;
	struct node* current = Head;
	struct node* nex = NULL;

	while (current != NULL)
	{
		nex = current->next;
		current->next = previous;
		previous = current;
		current = nex;
	}
	
	Head = previous;

	printf("\n[+] Linked List Reversed [+]\n");
	Display();
}