#include <stdio.h>

int majorityElement(int arr[], int n) {

    int candidate = arr[0];
    int count = 1;

    for(int i = 1; i < n; i++) {

        if(arr[i] == candidate) {
            count++;
        }
        else {
            count--;
        }

        if(count == 0) {
            candidate = arr[i];
            count = 1;
        }
    }

    return candidate;
}

int main() {

    int arr[] = {2, 2, 1, 2, 3, 2, 2};
    int n = 7;

    int result = majorityElement(arr, n);

    printf("Majority Element = %d", result);

    return 0;
}