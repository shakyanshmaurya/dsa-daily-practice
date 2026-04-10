#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at End
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

// Delete from Beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if(head == NULL) return NULL;

    struct Node* temp = head;
    head = head->next;
    free(temp);

    return head;
}

// Search
void search(struct Node* head, int key) {
    int pos = 1;

    while(head != NULL) {
        if(head->data == key) {
            printf("Found at position %d\n", pos);
            return;
        }
        head = head->next;
        pos++;
    }

    printf("Not Found\n");
}

// Reverse
struct Node* reverseList(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

// Traverse
void traverse(struct Node* head) {
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {

    struct Node* head = NULL;

    // Insert
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("List:\n");
    traverse(head);

    // Delete
    head = deleteFromBeginning(head);
    printf("After Deletion:\n");
    traverse(head);

    // Search
    search(head, 20);

    // Reverse
    head = reverseList(head);
    printf("After Reverse:\n");
    traverse(head);

    return 0;
}