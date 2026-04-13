#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int value) {

    if(rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1) front = 0;

    rear++;
    queue[rear] = value;
}

// dequeue
void dequeue() {

    if(front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);
    front++;
}

// peek
void peek() {
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

// display
void display() {

    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }

    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue:\n");
    display();

    peek();

    dequeue();

    printf("After Dequeue:\n");
    display();

    return 0;
}