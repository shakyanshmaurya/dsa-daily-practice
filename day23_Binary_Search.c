#include <stdio.h>

int main() {

    int arr[6] = {10, 20, 30, 40, 50, 60};
    int low = 0, high = 5, mid;
    int key;

    printf("Enter number to search: ");
    scanf("%d", &key);

    while(low <= high) {

        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("Element found at index %d", mid);
            return 0;
        }

        else if(key < arr[mid]) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }

    }

    printf("Element not found");

    return 0;
}