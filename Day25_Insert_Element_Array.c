#include <stdio.h>

int main() {

    int arr[10] = {10, 20, 30, 40, 50};
    int i, pos, value, size = 5;

    printf("Enter position to insert: ");
    scanf("%d", &pos);

    printf("Enter value: ");
    scanf("%d", &value);

    for(i = size; i >= pos; i--) {
        arr[i] = arr[i-1];
    }

    arr[pos-1] = value;
    size++;

    printf("Updated Array:\n");

    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}