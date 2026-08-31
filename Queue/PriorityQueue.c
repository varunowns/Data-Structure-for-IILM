#include <stdio.h>

#define MAX 5

int queue[MAX];
int priority[MAX];
int size = 0;

// Insertion
void insertion()
{
    int data, p;

    if (size == MAX)
    {
        printf("Priority Queue is Full\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &data);

    printf("Enter priority: ");
    scanf("%d", &p);

    queue[size] = data;
    priority[size] = p;

    size++;

    printf("Element inserted successfully\n");
}

// Deletion
void deletion()
{
    int i, pos = 0;

    if (size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    // Find highest priority
    for (i = 1; i < size; i++)
    {
        if (priority[i] < priority[pos])
        {
            pos = i;
        }
    }

    printf("Deleted element = %d\n", queue[pos]);

    // Shift elements
    for (i = pos; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
        priority[i] = priority[i + 1];
    }

    size--;
}

// Display
void display()
{
    int i;

    if (size == 0)
    {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("\nData\tPriority\n");

    for (i = 0; i < size; i++)
    {
        printf("%d\t%d\n", queue[i], priority[i]);
    }
}

// Main function
int main()
{
    int choice;

    while (1)
    {
        printf("\n--- PRIORITY QUEUE ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertion();
                break;

            case 2:
                deletion();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}