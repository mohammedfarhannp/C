#include <stdio.h>
#include <malloc.h>
#include "input.h"

struct node {
    int num;
    struct node* previous;
    struct node* next;
};

struct node* Head = NULL;

void Create(void);
void Insert(void);
void Delete(void);
void Display(void);

int isNULL(void);

int main(int argc, char* argv[])
{
    int run = 1, choice;

    while(run)
    {
        choice = int_input("\n1 - Create Circular Doubly Linked List\n2 - Insert item to Circular Doubly Linked List\n3 - Delete item from Circular Doubly Linked List\n4 - Display Circular Doubly Linked List\n\n0 - Exit\n\nChoose: ");
        switch(choice)
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
        case 0:
            run = 0;
            break;
        default:
            printf("\n[-] Invalid Choice [-]\n");
        }

    }

    return 0;
}

void Delete(void)
{
    if(isNULL())
    {
        printf("\n[-] Circular Doubly Linked List Doesn't Exist [-]\n");
        return;
    }

    int key = int_input("Enter the value of the node to be deleted: ");

    struct node* temp = Head;
    do {
        if(key == temp->num)
        {
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
            
            if(temp == Head)
                Head = temp->next;

            free(temp);

            printf("\n[+] Node Deleted Successfully [+]\n");
            return;
        }
        temp = temp->next;
    } while (temp != Head);
}

void Display(void)
{
    if(isNULL())
    {
        printf("\n[-] Circular Doubly Linked List Doesn't Exist [-]\n");
        return;
    }

    struct node* temp = Head;

    printf("[CIRCULAR DOUBLY LINKED LIST]\n|<-->");
    do {
        printf("[%d]<-->", temp->num);
        temp = temp->next;
    } while(temp != Head);
    printf("|\n[CIRCULAR DOUBLY LINKED LIST]\n");
}

void Insert(void)
{
    if(isNULL())
    {
        printf("\n[-] Circular Doubly Linked List Doesn't Exist [-]\n");
        return;
    }

    int key = int_input("Enter the value of node after which new node is to be inserted: ");

    struct node* temp = Head;
    do {
        if(temp->num == key)
        {
            struct node* new_node = (struct node*)malloc(sizeof(struct node));
            new_node->num = int_input("Enter a value for new node: ");

            temp->next->previous = new_node;
            new_node->next = temp->next;
            new_node->previous = temp;
            temp->next = new_node;

            printf("\n[+] Node Inserted Successfully [+]\n");
            return;
        }
        temp = temp->next;
    } while (temp != Head);

    printf("\n[-] Node not found [-]\n");
}

void Create(void){
    if(!isNULL())
    {
        printf("\n[-] Circular Doubly Linked List Already Exists [-]\n");
        return;
    }

    Head = (struct node*)malloc(sizeof(struct node));

    Head->num = int_input("Enter a value for Head node: ");
    Head->next = Head;
    Head->previous = Head;

    printf("\n[+] Node Created Successfully [+]\n");
}

int isNULL(void)
{
    if(Head == NULL)
        return 1;
    return 0;
}