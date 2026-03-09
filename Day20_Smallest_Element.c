#include <stdio.h>

int main() {

    int arr[5] = {12, 45, 7, 89, 34};
    int i, smallest;

    smallest = arr[0];

    for(i = 1; i < 5; i++) {
        if(arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    printf("Smallest element = %d", smallest);

    return 0;
}