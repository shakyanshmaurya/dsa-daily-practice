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

/* Count Total Nodes */

int countNodes(struct Node *root) {

    if(root == NULL)
        return 0;

    return 1 +
           countNodes(root->left) +
           countNodes(root->right);
}

/* Count Leaf Nodes */

int countLeaves(struct Node *root) {

    if(root == NULL)
        return 0;

    if(root->left == NULL &&
       root->right == NULL)
        return 1;

    return countLeaves(root->left) +
           countLeaves(root->right);
}

/* Sum of Nodes */

int sumNodes(struct Node *root) {

    if(root == NULL)
        return 0;

    return root->data +
           sumNodes(root->left) +
           sumNodes(root->right);
}

/* Height */

int height(struct Node *root) {

    if(root == NULL)
        return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if(leftHeight > rightHeight)
        return leftHeight + 1;

    return rightHeight + 1;
}

/* Preorder: Root Left Right */

void preorder(struct Node *root) {

    if(root == NULL)
        return;

    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}

/* Inorder: Left Root Right */

void inorder(struct Node *root) {

    if(root == NULL)
        return;

    inorder(root->left);

    printf("%d ", root->data);

    inorder(root->right);
}

/* Postorder: Left Right Root */

void postorder(struct Node *root) {

    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    printf("%d ", root->data);
}

int main() {

    /*
              1
             / \
            2   3
           / \ / \
          4  5 6  7
    */

    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Total Nodes = %d\n",
           countNodes(root));

    printf("Leaf Nodes = %d\n",
           countLeaves(root));

    printf("Sum of Nodes = %d\n",
           sumNodes(root));

    printf("Height = %d\n",
           height(root));

    printf("Preorder = ");
    preorder(root);

    printf("\nInorder = ");
    inorder(root);

    printf("\nPostorder = ");
    postorder(root);

    return 0;
}