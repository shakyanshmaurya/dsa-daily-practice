#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int isSorted = 1;

    for(int i = 0; i < n - 1; i++) {

        if(arr[i] > arr[i + 1]) {
            isSorted = 0;
            break;
        }
    }

    if(isSorted)
        printf("Array is Sorted");
    else
        printf("Array is NOT Sorted");

    return 0;
}