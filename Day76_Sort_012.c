#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int arr[] = {2, 0, 2, 1, 1, 0};
    int n = 6;

    int low = 0, mid = 0, high = n - 1;

    while(mid <= high) {

        if(arr[mid] == 0) {
            swap(&arr[low], &arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1) {
            mid++;
        }
        else {
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }

    printf("Sorted Array:\n");

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}