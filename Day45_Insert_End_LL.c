#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// insert at end
struct Node* insertAtEnd(struct Node* head, int value) {

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // if list is empty
    if(head == NULL) {
        return newNode;
    }

    struct Node* temp = head;

    // go to last node
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

// traverse
void traverse(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main() {

    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Original List:\n");
    traverse(head);

    head = insertAtEnd(head, 40);

    printf("\nAfter Insertion at End:\n");
    traverse(head);

    return 0;
}