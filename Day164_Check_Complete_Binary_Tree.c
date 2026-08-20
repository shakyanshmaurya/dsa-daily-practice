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

int isComplete(struct Node *root) {

    if(root == NULL)
        return 1;

    struct Node *queue[100];

    int front = 0;
    int rear = 0;

    int foundNull = 0;

    queue[rear++] = root;

    while(front < rear) {

        struct Node *current = queue[front++];

        /*
         * Left child
         */
        if(current->left != NULL) {

            if(foundNull)
                return 0;

            queue[rear++] = current->left;

        } else {

            foundNull = 1;
        }

        /*
         * Right child
         */
        if(current->right != NULL) {

            if(foundNull)
                return 0;

            queue[rear++] = current->right;

        } else {

            foundNull = 1;
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
        printf("Binary Tree is Complete");
    else
        printf("Binary Tree is NOT Complete");

    return 0;
}