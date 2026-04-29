#include <stdio.h>

// check if element exists in arr
int isPresent(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key)
            return 1;
    }
    return 0;
}

int main() {

    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {3, 4, 5, 6};

    int n1 = 4, n2 = 4;

    printf("Intersection: ");

    for(int i = 0; i < n1; i++) {
        if(isPresent(arr2, n2, arr1[i])) {
            printf("%d ", arr1[i]);
        }
    }

    return 0;
}