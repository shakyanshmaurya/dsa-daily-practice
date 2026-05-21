#include <stdio.h>

#define SIZE 100

int heap[SIZE];
int heapSize = 0;

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {

    heap[heapSize] = value;

    int current = heapSize;

    heapSize++;

    // heapify up
    while(current > 0) {

        int parent = (current - 1) / 2;

        if(heap[parent] < heap[current]) {

            swap(&heap[parent], &heap[current]);

            current = parent;
        }
        else {
            break;
        }
    }
}

void display() {

    printf("Max Heap:\n");

    for(int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
}

int main() {

    insert(20);
    insert(50);
    insert(10);
    insert(40);
    insert(30);

    display();

    return 0;
}