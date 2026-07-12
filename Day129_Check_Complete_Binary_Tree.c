#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* queue[100];
int front = 0, rear = 0;

void enqueue(struct Node *node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

int isComplete(struct Node *root) {

    if(root == NULL)
        return 1;

    int foundNull = 0;

    enqueue(root);

    while(!isEmpty()) {

        struct Node *current = dequeue();

        if(current == NULL) {
            foundNull = 1;
        }
        else {

            if(foundNull)
                return 0;

            enqueue(current->left);
            enqueue(current->right);
        }
    }

    return 1;
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);

    if(isComplete(root))
        printf("Complete Binary Tree");
    else
        printf("Not a Complete Binary Tree");

    return 0;
}