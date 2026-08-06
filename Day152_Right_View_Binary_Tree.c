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

void rightView(struct Node *root) {

    if(root == NULL)
        return;

    struct Node *queue[100];

    int front = 0;
    int rear = 0;

    queue[rear++] = root;

    while(front < rear) {

        int levelSize = rear - front;

        for(int i = 0; i < levelSize; i++) {

            struct Node *current = queue[front++];

            // Last node of current level
            if(i == levelSize - 1)
                printf("%d ", current->data);

            if(current->left != NULL)
                queue[rear++] = current->left;

            if(current->right != NULL)
                queue[rear++] = current->right;
        }
    }
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->right = createNode(6);

    root->left->right->right = createNode(7);

    printf("Right View of Binary Tree:\n");

    rightView(root);

    return 0;
}