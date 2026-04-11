#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

// push
void push(int value) {
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
}

// pop
void pop() {
    if(top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("Popped: %d\n", stack[top]);
    top--;
}

// peek
void peek() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element: %d\n", stack[top]);
}

// display
void display() {
    if(top == -1) {
        printf("Stack is empty\n");
        return;
    }

    for(int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
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