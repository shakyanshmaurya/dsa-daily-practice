#include <stdio.h>

int main() {

    int arr[] = {12, 45, 7, 89, 23, 56};
    int size = 6;

    int max = arr[0];

    for(int i = 1; i < size; i++) {

        if(arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Maximum element = %d", max);

    return 0;
}