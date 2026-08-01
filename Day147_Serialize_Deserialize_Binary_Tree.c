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

/* ---------- Serialization ---------- */

void serialize(struct Node *root) {

    if(root == NULL) {
        printf("# ");
        return;
    }

    printf("%d ", root->data);

    serialize(root->left);
    serialize(root->right);
}

/* ---------- Deserialization ---------- */

struct Node* deserialize() {

    char value[20];

    scanf("%s", value);

    if(value[0] == '#')
        return NULL;

    int data = atoi(value);

    struct Node *root = createNode(data);

    root->left = deserialize();
    root->right = deserialize();

    return root;
}

/* ---------- Inorder ---------- */

void inorder(struct Node *root) {

    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

int main() {

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->right->left = createNode(4);
    root->right->right = createNode(5);

    printf("Serialized Tree:\n");

    serialize(root);

    printf("\n\nEnter serialized tree:\n");

    struct Node *newRoot = deserialize();

    printf("\nInorder of Deserialized Tree:\n");

    inorder(newRoot);

    return 0;
}