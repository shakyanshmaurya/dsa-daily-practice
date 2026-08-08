#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int hd;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->hd = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void bottomView(struct Node *root) {

    if(root == NULL)
        return;

    struct Node *queue[100];

    int front = 0;
    int rear = 0;

    int bottom[200];
    int visited[200] = {0};

    root->hd = 0;

    queue[rear++] = root;

    while(front < rear) {

        struct Node *current = queue[front++];

        int index = current->hd + 100;

        /*
         * Unlike Top View,
         * Bottom View updates the value
         * whenever a node is found.
         */
        bottom[index] = current->data;
        visited[index] = 1;

        if(current->left != NULL) {

            current->left->hd = current->hd - 1;

            queue[rear++] = current->left;
        }

        if(current->right != NULL) {

            current->right->hd = current->hd + 1;

            queue[rear++] = current->right;
        }
    }

    printf("Bottom View: ");

    for(int i = 0; i < 200; i++) {

        if(visited[i])
            printf("%d ", bottom[i]);
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

    bottomView(root);

    return 0;
}