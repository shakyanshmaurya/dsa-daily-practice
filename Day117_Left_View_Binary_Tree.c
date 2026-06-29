#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Queue
struct Node* queue[100];

int front = 0;
int rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void leftView(struct Node* root) {

    if(root == NULL)
        return;

    enqueue(root);

    while(!isEmpty()) {

        int levelSize = rear - front;

        for(int i = 0; i < levelSize; i++) {

            struct Node* current =
                dequeue();

            if(i == 0)
                printf("%d ", current->data);

            if(current->left)
                enqueue(current->left);

            if(current->right)
                enqueue(current->right);
        }
    }
}

int main() {

    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->right = createNode(6);

    root->left->right->left = createNode(7);

    printf("Left View: ");

    leftView(root);

    return 0;
}