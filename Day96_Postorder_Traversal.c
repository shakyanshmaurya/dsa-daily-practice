#include <stdio.h>
#include <stdlib.h>

// node structure
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

// postorder traversal
void postorder(struct Node* root) {

    if(root == NULL) {
        return;
    }

    postorder(root->left);

    postorder(root->right);

    printf("%d ", root->data);
}

int main() {

    struct Node* root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);

    printf("Postorder Traversal:\n");

    postorder(root);

    return 0;
}