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

    if(head == NULL) return newNode;

    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;

    temp->next = newNode;
    return head;
}

// traverse
void traverse(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// reverse linked list
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    return head;
}

int main() {

    struct Node* head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Original List:\n");
    traverse(head);

    head = reverseList(head);

    printf("Reversed List:\n");
    traverse(head);

    return 0;
}