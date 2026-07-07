#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *head = NULL;
struct Node *prev = NULL;

struct Node* createNode(int value) {

    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void BTtoDLL(struct Node *root) {

    if(root == NULL)
        return;

    BTtoDLL(root->left);

    if(prev == NULL)
        head = root;
    else {

        root->left = prev;
        prev->right = root;
    }

    prev = root;

    BTtoDLL(root->right);
}

void printDLL(struct Node *head) {

    while(head != NULL) {

        printf("%d ", head->data);
        head = head->right;
    }
}

int main() {

    struct Node *root = createNode(10);

    root->left = createNode(12);
    root->right = createNode(15);

    root->left->left = createNode(25);
    root->left->right = createNode(30);

    root->right->left = createNode(36);

    BTtoDLL(root);

    printf("Doubly Linked List:\n");

    printDLL(head);

    return 0;
}