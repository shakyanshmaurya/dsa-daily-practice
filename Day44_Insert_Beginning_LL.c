#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// function to insert at beginning
struct Node* insertAtBeginning(struct Node* head, int value) {

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;

    head = newNode;

    return head;
}

void traverse(struct Node* head) {

    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main() {

    struct Node *head = NULL;

    // initial list
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    printf("Original List:\n");
    traverse(head);

    // insert new node at beginning
    head = insertAtBeginning(head, 5);

    printf("\nAfter Insertion:\n");
    traverse(head);

    return 0;
}