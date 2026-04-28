#include <stdio.h>

// function to check duplicate
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

    printf("Union: ");

    // print first array
    for(int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }

    // check and print from second
    for(int i = 0; i < n2; i++) {
        if(!isPresent(arr1, n1, arr2[i])) {
            printf("%d ", arr2[i]);
        }
    }

    return 0;
}