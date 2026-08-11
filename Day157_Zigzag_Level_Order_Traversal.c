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

void zigzagTraversal(struct Node *root) {

    if(root == NULL)
        return;

    struct Node *queue[100];

    int front = 0;
    int rear = 0;

    int leftToRight = 1;

    queue[rear++] = root;

    while(front < rear) {

        int levelSize = rear - front;

        int level[100];

        for(int i = 0; i < levelSize; i++) {

            struct Node *current = queue[front++];

            level[i] = current->data;

            if(current->left != NULL)
                queue[rear++] = current->left;

            if(current->right != NULL)
                queue[rear++] = current->right;
        }

        if(leftToRight) {

            for(int i = 0; i < levelSize; i++)
                printf("%d ", level[i]);

        } else {

            for(int i = levelSize - 1; i >= 0; i--)
                printf("%d ", level[i]);
        }

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

    printf("Zigzag Level Order Traversal:\n");

    zigzagTraversal(root);

    return 0;
}