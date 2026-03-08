#include <stdio.h>

int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int *ptr;
    int i, sum = 0;

    ptr = arr;   // pointer array ka address store karega

    for(i = 0; i < 5; i++) {
        sum = sum + *(ptr + i);
    }

    printf("Sum of array = %d", sum);

    return 0;
}