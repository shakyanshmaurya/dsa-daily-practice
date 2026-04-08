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

// search function
void search(struct Node* head, int key) {

    int position = 1;
    int found = 0;

    while(head != NULL) {

        if(head->data == key) {
            printf("Element found at position %d", position);
            found = 1;
            return;
        }

        head = head->next;
        position++;
    }

    if(!found) {
        printf("Element not found");
    }
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

    printf("Linked List:\n");
    traverse(head);

    int key;
    printf("\nEnter element to search: ");
    scanf("%d", &key);

    search(head, key);

    return 0;
}