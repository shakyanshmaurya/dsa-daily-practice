#include <stdio.h>

int main() {

    int arr1[3] = {10, 20, 30};
    int arr2[3] = {40, 50, 60};
    int arr3[6];

    int i, j;

    // Copy first array
    for(i = 0; i < 3; i++) {
        arr3[i] = arr1[i];
    }

    // Copy second array
    for(j = 0; j < 3; j++) {
        arr3[i] = arr2[j];
        i++;
    }

    printf("Merged Array:\n");

    for(i = 0; i < 6; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}