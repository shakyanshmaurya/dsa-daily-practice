#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// insert at end (for initial list)
struct Node* insertAtEnd(struct Node* head, int value) {

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        return newNode;
    }

    struct Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

// delete from end
struct Node* deleteFromEnd(struct Node* head) {

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    // only one node
    if(head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* temp = head;

    // go to second last node
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

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

    head = deleteFromEnd(head);

    printf("\nAfter Deletion:\n");
    traverse(head);

    return 0;
}