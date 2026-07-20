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

void inorder(struct Node *root, int arr[], int *index) {

    if(root == NULL)
        return;

    inorder(root->left, arr, index);

    arr[(*index)++] = root->data;

    inorder(root->right, arr, index);
}

void mergeArrays(int a[], int n1,
                 int b[], int n2) {

    int i = 0, j = 0;

    while(i < n1 && j < n2) {

        if(a[i] < b[j])
            printf("%d ", a[i++]);
        else
            printf("%d ", b[j++]);
    }

    while(i < n1)
        printf("%d ", a[i++]);

    while(j < n2)
        printf("%d ", b[j++]);
}

int main() {

    struct Node *root1 = createNode(2);
    root1->left = createNode(1);
    root1->right = createNode(4);

    struct Node *root2 = createNode(9);
    root2->left = createNode(3);
    root2->right = createNode(12);

    int arr1[100], arr2[100];
    int n1 = 0, n2 = 0;

    inorder(root1, arr1, &n1);
    inorder(root2, arr2, &n2);

    printf("Merged BST Elements:\n");

    mergeArrays(arr1, n1, arr2, n2);

    return 0;
}