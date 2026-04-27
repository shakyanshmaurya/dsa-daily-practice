#include <stdio.h>

// reverse function
void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 2;

    k = k % n; // handle large k

    // step 1
    reverse(arr, 0, k - 1);

    // step 2
    reverse(arr, k, n - 1);

    // step 3
    reverse(arr, 0, n - 1);

    printf("Array after rotation:\n");

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}