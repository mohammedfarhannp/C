#include <stdio.h>
#include <malloc.h>
#include "input.h"

struct node {
	int coef;
	int exp;
	struct node* next;
};

struct node* Head = NULL;

void Create(void);
void Add_Term(void);
void Remove_Term(void);
void Display(void);
void Clean(void);

int main(int argc, char* argv[])
{
	int choice, run = 1;

	while (run)
	{
		choice = int_input("\n1 - Create Polynomial\n2 - Add Term to Polynomial\n3 - Remove Term from Polynomial\n4 - Display Polynomial\n\n0 - Exit\n\nChoose: ");

		switch (choice)
		{
		case 2:
			Add_Term();
			break;

		case 3:
			Remove_Term();
			break;

		case 4:
			Display();
			break;

		case 1:
			Create();
			break;

		case 0:
			run = 0;
			break;

		default:
			printf("Invalid Choice\n");
		}
	}
	Clean();
	return 0;
}

void Create(void)
{
	if (Head != NULL)
	{
		printf("Polynomial Already Exists!\n");
		return;
	}

	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->coef = int_input("Coefficient of Term : ");
	temp->exp = int_input("Exponent of X : ");
	temp->next = NULL;

	Head = temp;
}

void Add_Term(void)
{
	if (Head == NULL)
	{
		printf("Polynomial Doesn't exist!\n");
		return;
	}

	struct node* last = Head;
	while (last->next != NULL)
	{
		last = last->next;
	}

	struct node* temp = (struct node*)malloc(sizeof(struct node));

	temp->coef = int_input("Coefficient of Term : ");
	temp->exp = int_input("Exponent of X : ");
	temp->next = NULL;

	last->next = temp;
}

void Remove_Term(void)
{
	if (Head == NULL)
	{
		printf("Polynomial doesn't exist!\n");
		return;
	}

	int Coef = int_input("Coefficient of the term to delete: ");
	int Exp = int_input("Power of X to delete: ");

	struct node* temp = Head;
	struct node* previous = NULL;

	while (temp != NULL)
	{
		if (Coef == temp->coef && Exp == temp->exp)
		{
			if (temp == Head)
			{
				Head = Head->next;
			}
			else {
				previous->next = temp->next;
			}
			free(temp);
			return;
		}
		previous = temp;
		temp = temp->next;
	}

	printf("Term not found in the Polynomial\n");
}

void Display(void)
{
	if (Head == NULL)
	{
		printf("Polynomial doesn't exist!\n");
		return;
	}

	struct node* temp = Head;
	printf("_____\n");
	while (temp != NULL)
	{
		printf("(%d", temp->coef);
		if (temp->exp > 0)
		{
			printf("x^%d)", temp->exp);
		}
		else {
			printf(")");
		}

		if (temp->next != NULL)
		{
			printf(" + ");
		}
		temp = temp->next;
	}
	printf(" = 0\n");
	printf("-----\n\n");
}

void Clean(void)
{
	if (Head == NULL) return;

	struct node* temp;
	while (Head != NULL)
	{
		temp = Head;
		Head = Head->next;
		free(temp);
	}
}