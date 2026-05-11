#include <stdio.h>

int main() {

    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = 6;

    int target = 7;

    int low = 0;
    int high = n - 1;

    int found = -1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(arr[mid] == target) {
            found = mid;
            break;
        }
        else if(target < arr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    if(found != -1)
        printf("Element found at index %d", found);
    else
        printf("Element not found");

    return 0;
}