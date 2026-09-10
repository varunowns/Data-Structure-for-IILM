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

void insertRandom(){
    int i, loc,item;
    struct Node *ptr, *temp;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    if (ptr == NULL){
        printf("\nOVERFLOW");
    } else {
        printf("Enter element value : ");
        scanf("%d",&item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert : ");
        scanf("\n%d", &loc);
        temp = head;
        for (int i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\nCan't insert!");
                return;
            }
            
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode Inserted");
    }
}
void deleteFirst(){
    struct Node* ptr;
    if (head == NULL)
    {
        printf("\nList is Empty!");
    } else {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\n Node deleted from begining ...");
    }
}
void deleteLast(){
    struct Node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\nList is Empty");
    } else if(head->next == NULL){
        head = NULL;
        free(head);
        printf("\nOnly node of the list deleted ...");
    } else {
        ptr = head;
        while (ptr->next!=NULL)
        {
            ptr1 = ptr;
            ptr = ptr -> next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nDeleted Node from last ...");
        
    }
    
}

void deleteSpecified(){
    struct Node *ptr, *ptr1;
    int loc,i;
    printf("Enter specific location from where to delete : ");
    scanf("%d", &loc);
    ptr = head;
    for (i = 0; i < loc; i++)
    {
        ptr1=ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("\n There are less than %d elements in the list..\n",loc);
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted %d node..",loc);    
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
        printf("3. Insert at random\n");
        printf("4. Delete at First\n");
        printf("5. Delete at Last\n");
        printf("6. Delete at Specific\n");
        printf("7. Display\n");
        printf("8. Exit\n");

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
                insertRandom();
                break;

            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                deleteSpecified();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}