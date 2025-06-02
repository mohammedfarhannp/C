#include <stdio.h>
#include <malloc.h>

#include "input.h"

struct node {
    int info;
    struct node* next;
};

struct node* Top = NULL;

int Stack_Size = 10, Stack_Ptr = 0;

void push(int);
void pop(void);
void display(void);
void clean(void);

int main(int argc, char* argv[])
{
    int choice;
    while(1)
    {
        choice = int_input("1 - Push to Stack\n2 - Pop from Stack\n3 - Display\n\n0 - exit\n\nSelect : ");
        if(choice == 0)
            break;
        switch(choice)
        {
            case 1:
                push(int_input("Enter a number to be pushed onto stack: "));
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                printf("Invalid Choice! Try Again!\n");
        }
    }
    clean();
    return 0;
}

void clean(void)
{
    while (Top != NULL) {
        pop();
    }
}

void display(void)
{
    if(Top == NULL)
    {
        printf("Stack Empty!\n");
        return;
    }

    struct node* temp = Top;

    printf(" -- STACK TOP -- \n");
    while(temp != NULL)
    {
        printf("%d\n", temp->info);
        temp = temp->next;
    }
    printf(" -- STACK FLOOR -- \n");
}

void pop(void)
{
    if(Top == NULL)
    {
        printf("Stack Empty!\n");
        return;
    }

    struct node* temp = Top;
    Top = Top->next;
    printf("%d Poped from Stack (Linked List)\n", temp->info);
    free(temp);
    Stack_Ptr--;
}

void push(int element)
{
    if(Stack_Ptr >= Stack_Size)
    {
        printf("Stack Full!\n");
        return;
    }

    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->info = element;
    temp->next = NULL;

    if(Top == NULL)
        Top = temp;
    else {
        temp->next = Top;
        Top = temp;
    }
    printf("%d is pushed to Stack (Linked List)\n", element);
    Stack_Ptr++;
}

