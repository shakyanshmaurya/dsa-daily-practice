#include <stdio.h>

int main() {

    int arr[] = {12, 11, 13, 5, 6};
    int n = 5;

    for(int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        // shift larger elements
        while(j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    printf("Sorted Array:\n");

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}