#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {

    if(low > high) {
        return -1;
    }

    int mid = (low + high) / 2;

    if(arr[mid] == target) {
        return mid;
    }

    else if(target < arr[mid]) {
        return binarySearch(arr, low, mid - 1, target);
    }

    else {
        return binarySearch(arr, mid + 1, high, target);
    }
}

int main() {

    int arr[] = {2, 4, 6, 8, 10, 12};
    int n = 6;

    int target = 8;

    int result = binarySearch(arr, 0, n - 1, target);

    if(result != -1)
        printf("Element found at index %d", result);
    else
        printf("Element not found");

    return 0;
}