#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    struct Node *head, *second, *third;

    // allocate memory
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    // assign data
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // traversal
    struct Node* ptr = head;

    printf("Linked List: ");

    while(ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");

    return 0;
}