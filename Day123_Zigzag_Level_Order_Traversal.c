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

void zigzagTraversal(struct Node *root) {

    if(root == NULL)
        return;

    int leftToRight = 1;

    enqueue(root);

    while(!isEmpty()) {

        int size = rear - front;
        int level[100];

        for(int i = 0; i < size; i++) {

            struct Node *current = dequeue();

            level[i] = current->data;

            if(current->left)
                enqueue(current->left);

            if(current->right)
                enqueue(current->right);
        }

        if(leftToRight) {

            for(int i = 0; i < size; i++)
                printf("%d ", level[i]);
        }
        else {

            for(int i = size - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

        printf("\n");

        leftToRight = !leftToRight;
    }
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Zigzag Traversal:\n");

    zigzagTraversal(root);

    return 0;
}