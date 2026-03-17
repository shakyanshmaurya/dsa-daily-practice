#include <stdio.h>

int main() {

    int arr[10] = {10, 20, 30, 40, 50};
    int i, pos, size = 5;

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    for(i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;

    printf("Updated Array:\n");

    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}