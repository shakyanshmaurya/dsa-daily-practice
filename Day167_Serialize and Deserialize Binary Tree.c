#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Serialize
void serialize(struct Node* root) {
    if (root == NULL) {
        printf("# ");
        return;
    }

    printf("%d ", root->data);

    serialize(root->left);
    serialize(root->right);
}

// Deserialize
struct Node* deserialize() {
    char value[10];

    scanf("%s", value);

    // NULL marker
    if (value[0] == '#') {
        return NULL;
    }

    struct Node* root = createNode(atoi(value));

    root->left = deserialize();
    root->right = deserialize();

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    /*
            1
           / \
          2   3
             / \
            4   5
    */

    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->right->left = createNode(4);
    root->right->right = createNode(5);

    printf("Serialized Tree:\n");
    serialize(root);

    printf("\n\nEnter serialized tree:\n");

    struct Node* newRoot = deserialize();

    printf("\nInorder after Deserialization:\n");
    inorder(newRoot);

    return 0;
}