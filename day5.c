#include <stdio.h>

int main() {
    int n, i, sorted = 1;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            sorted = 0;
            break;
        }
    }

    if(sorted)
        printf("Array is Sorted");
    else
        printf("Array is Not Sorted");

    return 0;
}