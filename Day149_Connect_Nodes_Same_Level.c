#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;
};

struct Node* createNode(int value) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->next = NULL;

    return newNode;
}

void connectSameLevel(struct Node *root) {

    if(root == NULL)
        return;

    struct Node *queue[100];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while(front < rear) {

        int levelSize = rear - front;

        struct Node *previous = NULL;

        for(int i = 0; i < levelSize; i++) {

            struct Node *current = queue[front++];

            if(previous != NULL)
                previous->next = current;

            previous = current;

            if(current->left != NULL)
                queue[rear++] = current->left;

            if(current->right != NULL)
                queue[rear++] = current->right;
        }

        // Last node of current level
        previous->next = NULL;
    }
}

void printConnections(struct Node *root) {

    if(root == NULL)
        return;

    struct Node *queue[100];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while(front < rear) {

        struct Node *current = queue[front++];

        printf("%d -> ", current->data);

        if(current->next != NULL)
            printf("%d", current->next->data);
        else
            printf("NULL");

        printf("\n");

        if(current->left != NULL)
            queue[rear++] = current->left;

        if(current->right != NULL)
            queue[rear++] = current->right;
    }
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->right = createNode(6);

    connectSameLevel(root);

    printf("Same Level Connections:\n");

    printConnections(root);

    return 0;
}