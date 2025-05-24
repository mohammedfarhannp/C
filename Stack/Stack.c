/*
	Implementation of Stack using C language to check a string of
	2 alphabets as to which of the alphabets is more in number
	without counting.
*/

// Header Files
#include <stdio.h>
#include <string.h>

// Definition
#define MAX 100

// Global Stack Vars
char Stack[MAX];
int Stack_Ptr = 0;

// Function Prototypes
void Push(char);
void Pop(void);
void Display_Stack(void);

int Unique(char[]);

// Main Function
int main(int argc, char* argv[])
{
	// User Input Var
	char Input[256];

	// User Input
	printf("Enter a string: ");
	
	if (fgets(Input, sizeof(Input), stdin))
	{
		size_t len = strlen(Input);
		if (len > 0 && Input[len - 1] == '\n')
		{
			Input[len - 1] = '\0';
		}
	}

	// Checks if the unique alphabet count in the string is 2
	if (Unique(Input) != 2)
	{
		printf("Only 2 alphabet string would be handled but input of %d alphabet string was given\n", Unique(Input));
		return 1;
	}

	// Use of Stack to perform checking of the string input.
	int i = 0;

	while(Input[i] != '\0')
	{	
		// Stores a char in tmp var
		char tmp = Input[i];

		// if stack is empty then push to stack
		if (Stack_Ptr == 0)
		{
			Push(tmp);
		}
		// else if the char is same as the ones in stack then push to stack 
		else if (Stack[0] == tmp)
		{
			Push(tmp);
		}
		// else pop from the stack
		else {
			Pop();
		}

		i++;
	}

	// print the output
	if (Stack_Ptr != 0)
		printf("Number of %c's is greater\n", Stack[0]);
	else
		printf("Both alphabets are equal in number!\n");

	return 0;
}

// function for returning the count of unique char count from a string
int Unique(char string[])
{
	int uniq_count = 0, i = 0, j = 0, ptr = 0, flag;
	char Seen[256] = {0};

	while (string[i] != '\0')
	{
		flag = 0;
		for (j = 0; j < ptr; j++)
		{
			if (Seen[j] == string[i])
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0 && string[i] != '\n')
		{
			Seen[ptr] = string[i];
			ptr++;
		}
		i++;
	}
	return ptr;
}

// Function for Stack Operation: Push
void Push(char element)
{
	if (Stack_Ptr < MAX)
	{
		Stack[Stack_Ptr] = element;
		Stack_Ptr++;
	}
	else {
		printf("Stack is Full!\n");
		return;
	}
}

// Function for Stack Operation: Pop
void Pop(void)
{
	if (Stack_Ptr == 0)
	{
		printf("Stack is empty!\n");
		return;
	}
	Stack_Ptr--;
}