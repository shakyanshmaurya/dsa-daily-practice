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

struct Node* queue[100];
int front = 0, rear = 0;

void enqueue(struct Node *node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void verticalOrder(struct Node *root) {

    if(root == NULL)
        return;

    int vertical[201][20] = {0};
    int count[201] = {0};

    enqueue(root);

    while(!isEmpty()) {

        struct Node *current = dequeue();

        int index = current->hd + 100;

        vertical[index][count[index]++] =
            current->data;

        if(current->left) {

            current->left->hd =
                current->hd - 1;

            enqueue(current->left);
        }

        if(current->right) {

            current->right->hd =
                current->hd + 1;

            enqueue(current->right);
        }
    }

    printf("Vertical Order:\n");

    for(int i = 0; i < 201; i++) {

        if(count[i] > 0) {

            for(int j = 0; j < count[i]; j++)
                printf("%d ", vertical[i][j]);

            printf("\n");
        }
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

    verticalOrder(root);

    return 0;
}