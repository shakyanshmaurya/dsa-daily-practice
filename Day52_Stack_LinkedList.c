#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// push
void push(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// pop
void pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp = top;
    printf("Popped: %d\n", temp->data);

    top = top->next;
    free(temp);
}

// peek
void peek() {
    if(top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

// display
void display() {
    struct Node* temp = top;

    if(temp == NULL) {
        printf("Stack is empty\n");
        return;
    }

    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {

    push(10);
    push(20);
    push(30);

    printf("Stack:\n");
    display();

    peek();

    pop();

    printf("After pop:\n");
    display();

    return 0;
}