#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* left;
    struct Node* right;
};

// create node
struct Node* createNode(int value) {

    struct Node* newNode =
        (struct Node*) malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// queue for nodes
struct Node* queue[100];

int front = 0;
int rear = 0;

// enqueue
void enqueue(struct Node* node) {
    queue[rear++] = node;
}

// dequeue
struct Node* dequeue() {
    return queue[front++];
}

// check empty
int isEmpty() {
    return front == rear;
}

// level order traversal
void levelOrder(struct Node* root) {

    if(root == NULL)
        return;

    enqueue(root);

    while(!isEmpty()) {

        struct Node* current = dequeue();

        printf("%d ", current->data);

        if(current->left != NULL)
            enqueue(current->left);

        if(current->right != NULL)
            enqueue(current->right);
    }
}

int main() {

    struct Node* root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);

    printf("Level Order Traversal:\n");

    levelOrder(root);

    return 0;
}