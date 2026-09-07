#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at first position
void insertFirst()
{
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;
    head = newNode;

    printf("Node inserted at first position.\n");
}

// Insert at last position
void insertLast()
{
    int value;

    printf("Enter value: ");
    scanf("%d", &value);

    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;

        // Move to the last node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at last position.\n");
}

// Display linked list
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFirst();
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