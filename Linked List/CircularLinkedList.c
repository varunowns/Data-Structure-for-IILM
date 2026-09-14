#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertBeginning()
{
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    printf("Node inserted at beginning.\n");
}

void insertLast()
{
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    printf("Node inserted at last.\n");
}

void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Circular linked list is empty.\n");
        return;
    }

    temp = head;

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("(Back to Head)\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Last\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertLast();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}