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

void deleteMax() {

    if(heapSize == 0) {
        printf("Priority Queue Empty\n");
        return;
    }

    printf("Deleted Element: %d\n", heap[0]);

    heap[0] = heap[heapSize - 1];

    heapSize--;

    int current = 0;

    // heapify down
    while(1) {

        int left = 2 * current + 1;
        int right = 2 * current + 2;

        int largest = current;

        if(left < heapSize && heap[left] > heap[largest]) {
            largest = left;
        }

        if(right < heapSize && heap[right] > heap[largest]) {
            largest = right;
        }

        if(largest != current) {

            swap(&heap[current], &heap[largest]);

            current = largest;
        }
        else {
            break;
        }
    }
}

void display() {

    printf("Priority Queue:\n");

    for(int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }

    printf("\n");
}

int main() {

    insert(20);
    insert(50);
    insert(30);
    insert(10);
    insert(40);

    display();

    deleteMax();

    display();

    return 0;
}