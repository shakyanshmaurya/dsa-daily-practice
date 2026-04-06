#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// delete from beginning
struct Node* deleteFromBeginning(struct Node* head) {

    if(head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp = head;

    head = head->next;

    free(temp);

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

    // creating list
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);

    printf("Original List:\n");
    traverse(head);

    head = deleteFromBeginning(head);

    printf("\nAfter Deletion:\n");
    traverse(head);

    return 0;
}