#include <stdio.h>
#define MAX 5

void enqueue(int element, int *front, int *rear, int max, int queue[]){
    if (*front == -1 && *rear == -1)
    {
        *front = *rear = 0;
        queue[*rear] = element;
    } else if ((*rear + 1) % max == *front)
    {
        printf("Queue overflow!\n");
    } else
    {
        *rear = (*rear + 1) % max;
        queue[*rear] = element;
    }
}

void dequeue(int *front, int *rear, int max, int queue[]){
    if (*front == -1 && *rear == -1)
    {
        printf("Queue underflow!\n");
    } else
    {
        printf("Deleted element: %d\n", queue[*front]);
        if (*front == *rear)
        {
            *front = *rear = -1;
        }
        else
        {
            *front = (*front + 1) % max;
        }  
    }   
}

void display(int front, int rear, int max, int queue[]){
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty!\n");
    } else
    {
        printf("Queue elements: ");
        do
        {
            printf("%d ", queue[i]);
            i = (i+1) % max;
        } while (i != (rear + 1) % max);
        printf("\n");
    }
    
    
}

int main(){
    int queue[MAX];
    int front = -1, rear = -1;
    int choice, element;

    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element, &front, &rear, MAX, queue);
                break;
            case 2:
                dequeue(&front, &rear, MAX, queue);
                break;
            case 3:
                display(front, rear, MAX, queue);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}