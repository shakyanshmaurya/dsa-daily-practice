#include <stdio.h>

int main() {

    int arr[5] = {10, 45, 32, 89, 67};
    int i;
    int largest, second;

    largest = second = arr[0];

    for(i = 1; i < 5; i++) {

        if(arr[i] > largest) {
            second = largest;
            largest = arr[i];
        }
        else if(arr[i] > second && arr[i] != largest) {
            second = arr[i];
        }

    }

    printf("Second Largest = %d", second);

    return 0;
}