#include <stdio.h>

int main() {
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int second = arr[0];

    for(i = 1; i < n; i++) {
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