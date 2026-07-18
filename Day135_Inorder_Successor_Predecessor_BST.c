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

void findPreSuc(struct Node *root, int key,
                int *pre, int *suc) {

    while(root != NULL) {

        if(root->data == key) {

            if(root->left) {
                struct Node *temp = root->left;
                while(temp->right)
                    temp = temp->right;
                *pre = temp->data;
            }

            if(root->right) {
                struct Node *temp = root->right;
                while(temp->left)
                    temp = temp->left;
                *suc = temp->data;
            }

            return;
        }

        if(key < root->data) {
            *suc = root->data;
            root = root->left;
        }
        else {
            *pre = root->data;
            root = root->right;
        }
    }
}

int main() {

    struct Node *root = createNode(20);

    root->left = createNode(10);
    root->right = createNode(30);

    root->left->left = createNode(5);
    root->left->right = createNode(15);

    root->right->left = createNode(25);
    root->right->right = createNode(35);

    int pre = -1, suc = -1;

    findPreSuc(root, 20, &pre, &suc);

    printf("Predecessor = %d\n", pre);
    printf("Successor = %d", suc);

    return 0;
}