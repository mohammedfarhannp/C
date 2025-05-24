// Header Files
#include <stdio.h>
#include <malloc.h>

// Linked List Structure
struct node {
	int info;
	struct node* next;
};

// Global Pointers
struct node* Head = NULL;
struct node* Temp = NULL;
struct node* Previous = NULL;

// Function Prototypes
int int_input(char*);

void Create_Linked_List(void);
void Display_Linked_List(void);
void Insert_to_Linked_List(void);
void Delete_from_Linked_List(void);

int Switch_Case_Call(int);

// Main Function
int main(int argc, char* argv[])
{
	int Run = 1, Option;

	while (Run) {
		Option = int_input("Select an Option:\n 1 - Create Linked List\n 2 - Insert to Linked List\n 3 - Display Linked List\n 4 - Delet from Linked List\n\n 0 - Exit\n\nChoose: ");
		Run = Switch_Case_Call(Option);
	}

	return 0;
}

// Function for Handling Switch Cases and function calls (Aesthetic Purpose)
int Switch_Case_Call(int Input)
{
	int ret_case = 1;
	switch (Input)
	{
	case 0:
		ret_case = 0;
		break;
	case 1:
		Create_Linked_List();
		break;
	case 2:
		Insert_to_Linked_List();
		break;
	case 3:
		Display_Linked_List();
		break;
	case 4:
		Delete_from_Linked_List();
		break;
	default:
		printf("Unknown Command! Try again!");
	}
	return ret_case;
}

// Function to Delete Elements from Linked List
void Delete_from_Linked_List(void) {
	if (Head == NULL) {
		printf("Linked List doesn't exist!\n");
		return;
	}

	int Key = int_input("Enter the element to be removed from Linked List: ");

	Temp = Head;
	Previous = NULL;

	while (Temp != NULL && Temp->info != Key)
	{
		Previous = Temp;
		Temp = Temp->next;
	}

	if (Temp == NULL)
		return;
	if (Temp == Head)
	{
		Head = Head->next;
	}
	else {
		Previous->next = Temp->next;
	}

	free(Temp);
}

// Function to Insert Elements to Linked List
void Insert_to_Linked_List(void)
{
	if (Head == NULL)
	{
		printf("Linked List doesn't exist!\n");
		return;
	}

	int Key = int_input("Enter the key after which new element will be added: ");
	int element = int_input("Enter the new element to be inserted: ");

	Temp = Head;
	
	while (Temp != NULL && Temp->info != Key)
	{	
		Temp = Temp->next;
	}


	if (Temp == NULL)
	{
		printf("No Key Found!\n");
		return;
	}

	struct node* New_Pointer = (struct node*)malloc(sizeof(struct node));
	New_Pointer->info = element;
	New_Pointer->next = Temp->next;
	Temp->next = New_Pointer;
}

// Function to Display Linked List
void Display_Linked_List(void)
{
	printf("\n");
	Temp = Head;
	while (Temp != NULL)
	{
		printf("[%d]", Temp->info);
		if (Temp->next != NULL)
		{
			printf("-->");
		}
		Temp = Temp->next;
	}
	printf("\n");
}

// Function to Create Linked List
void Create_Linked_List(void)
{
	if (Head != NULL)
	{
		printf("Linked List already Exists!\n");
		return;
	}

	int element = int_input("Enter a number for starting of linked list: ");
	
	Head = (struct node*)malloc(sizeof(struct node));
	if (Head == NULL)
	{
		printf("Linked List Memory Allocation failure!\n");
		return;
	}

	Head->info = element;
	Head->next = NULL;
}


// Function for ease of integer user input handling.
int int_input(char* prompt)
{
	int x;
	printf("%s", prompt);
	scanf("%d", &x);
	return x;
}