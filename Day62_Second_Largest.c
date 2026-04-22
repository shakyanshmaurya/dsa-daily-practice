#include <stdio.h>
#include <limits.h>

int main() {

    int arr[] = {10, 20, 4, 45, 99};
    int n = 5;

    int first = INT_MIN, second = INT_MIN;

    for(int i = 0; i < n; i++) {

        if(arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    printf("Second Largest = %d", second);

    return 0;
}