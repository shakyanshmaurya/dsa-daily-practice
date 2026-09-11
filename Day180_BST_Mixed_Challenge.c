#include <stdio.h>
#include <stdlib.h>

// BST Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create Node
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert into BST
struct Node* insert(struct Node* root, int data) {

    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

// Search
struct Node* search(struct Node* root, int key) {

    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

// Find Minimum
struct Node* findMin(struct Node* root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root;
}

// Find Maximum
struct Node* findMax(struct Node* root) {

    while (root->right != NULL) {
        root = root->right;
    }

    return root;
}

// Inorder Successor
struct Node* successor(struct Node* root, int key) {

    struct Node* succ = NULL;

    while (root != NULL) {

        if (key < root->data) {
            succ = root;
            root = root->left;
        }
        else if (key > root->data) {
            root = root->right;
        }
        else {
            if (root->right != NULL) {
                succ = findMin(root->right);
            }
            break;
        }
    }

    return succ;
}

// Inorder Predecessor
struct Node* predecessor(struct Node* root, int key) {

    struct Node* pred = NULL;

    while (root != NULL) {

        if (key > root->data) {
            pred = root;
            root = root->right;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else {
            if (root->left != NULL) {
                pred = findMax(root->left);
            }
            break;
        }
    }

    return pred;
}

// Kth Smallest
void kthSmallest(struct Node* root, int* k, int* answer) {

    if (root == NULL || *answer != -1) {
        return;
    }

    kthSmallest(root->left, k, answer);

    if (*answer != -1) {
        return;
    }

    (*k)--;

    if (*k == 0) {
        *answer = root->data;
        return;
    }

    kthSmallest(root->right, k, answer);
}

// Kth Largest
void kthLargest(struct Node* root, int* k, int* answer) {

    if (root == NULL || *answer != -1) {
        return;
    }

    kthLargest(root->right, k, answer);

    if (*answer != -1) {
        return;
    }

    (*k)--;

    if (*k == 0) {
        *answer = root->data;
        return;
    }

    kthLargest(root->left, k, answer);
}

// Inorder
void inorder(struct Node* root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {

    struct Node* root = NULL;

    // Create BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: ");
    inorder(root);

    // 1. Search
    int key = 60;

    if (search(root, key) != NULL) {
        printf("\nSearch %d: Found", key);
    }
    else {
        printf("\nSearch %d: Not Found", key);
    }

    // 2. Minimum
    printf("\nMinimum: %d", findMin(root)->data);

    // 3. Maximum
    printf("\nMaximum: %d", findMax(root)->data);

    // 4. Successor
    struct Node* succ = successor(root, 50);

    if (succ != NULL) {
        printf("\nSuccessor of 50: %d", succ->data);
    }

    // 5. Predecessor
    struct Node* pred = predecessor(root, 50);

    if (pred != NULL) {
        printf("\nPredecessor of 50: %d", pred->data);
    }

    // 6. Kth Smallest
    int k1 = 3;
    int smallestAnswer = -1;

    kthSmallest(root, &k1, &smallestAnswer);

    printf("\n3rd Smallest: %d", smallestAnswer);

    // 7. Kth Largest
    int k2 = 2;
    int largestAnswer = -1;

    kthLargest(root, &k2, &largestAnswer);

    printf("\n2nd Largest: %d", largestAnswer);

    return 0;
}