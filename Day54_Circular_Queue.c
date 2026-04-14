#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// enqueue
void enqueue(int value) {

    if((rear + 1) % MAX == front) {
        printf("Queue Overflow\n");
        return;
    }

    if(front == -1) front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

// dequeue
void dequeue() {

    if(front == -1) {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if(front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }
}

// display
void display() {

    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }

    int i = front;

    while(1) {
        printf("%d ", queue[i]);

        if(i == rear) break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {

    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue:\n");
    display();

    dequeue();

    printf("After Dequeue:\n");
    display();

    enqueue(40);
    enqueue(50);

    printf("After Adding More:\n");
    display();

    return 0;
}