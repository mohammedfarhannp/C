#include <stdio.h>
#include <malloc.h>

#include "input.h"

struct node {
    int info;
    struct node* next;
};

struct node* Front = NULL;
struct node* Rear = NULL;

int Queue_Size = 10, Queue_Ptr = 0;

void enqueue(int);
void dequeue(void);

void display(void);
void clean(void);

int main(int argc, char* argv[])
{
    int choice;
    while(1)
    {
        choice = int_input("1 - enqueue to Stack\n2 - dequeue from Stack\n3 - Display\n\n0 - exit\n\nSelect : ");
        if(choice == 0)
            break;
        switch(choice)
        {
            case 1:
                enqueue(int_input("Enter a number to be enqueued onto stack: "));
                break;
            case 2:
                dequeue();
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
    while (Front != NULL) {
        dequeue();
    }
}

void display(void)
{
    if(Front == NULL)
    {
        printf("Queue Empty!\n");
        return;
    }

    struct node* temp = Front;

    printf("[Q_FRONT] -- ");
    while(temp != NULL)
    {
        printf("[%d]", temp->info);
        if(temp->next != NULL)
            printf(" -- ");
        temp = temp->next;
    }
    printf(" -- [Q_REAR]\n");
}

void dequeue(void)
{
    if(Front == NULL)
    {
        printf("Queue Empty!\n");
        return;
    }

    struct node* temp = Front;
    Front = Front->next;
    printf("%d dequeueed from Queue (Linked List)\n", temp->info);
    free(temp);
    Queue_Ptr--;
}

void enqueue(int element)
{
    if(Queue_Ptr >= Queue_Size)
    {
        printf("Queue Full!\n");
        return;
    }

    struct node* temp = (struct node*) malloc(sizeof(struct node));
    temp->info = element;
    temp->next = NULL;

    if(Front == NULL)
    {
        Front = temp;
        Rear = temp;
    } else {
        Rear->next = temp;
        Rear = temp;
    }
    printf("%d is enqueueed to Queue (Linked List)\n", element);
    Queue_Ptr++;
}

