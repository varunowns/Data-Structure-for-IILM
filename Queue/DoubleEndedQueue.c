#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int deque[MAX];
int front = -1;
int rear = -1;

void insertFront() {
    int value;

    if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
        printf("Deque is Full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1) {
        front = rear = 0;
    }
    else if (front == 0) {
        front = MAX - 1;
    }
    else {
        front--;
    }

    deque[front] = value;
    printf("%d inserted at front.\n", value);
}

void insertRear() {
    int value;

    if ((front == 0 && rear == MAX - 1) || front == rear + 1) {
        printf("Deque is Full!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    if (front == -1) {
        front = rear = 0;
    }
    else if (rear == MAX - 1) {
        rear = 0;
    }
    else {
        rear++;
    }

    deque[rear] = value;
    printf("%d inserted at rear.\n", value);
}

void deleteFront() {
    if (front == -1) {
        printf("Deque is Empty!\n");
        return;
    }

    printf("%d deleted from front.\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (front == MAX - 1) {
        front = 0;
    }
    else {
        front++;
    }
}

void deleteRear() {
    if (front == -1) {
        printf("Deque is Empty!\n");
        return;
    }

    printf("%d deleted from rear.\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    }
    else if (rear == 0) {
        rear = MAX - 1;
    }
    else {
        rear--;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Deque is Empty!\n");
        return;
    }

    printf("Deque elements: ");

    i = front;

    while (1) {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- DOUBLE ENDED QUEUE ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertFront();
                break;

            case 2:
                insertRear();
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program exited.\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}