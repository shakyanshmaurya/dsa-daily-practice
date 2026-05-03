#include <stdio.h>

int main() {

    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};

    int n1 = 3, n2 = 3;
    int result[10];

    int i = 0, j = 0, k = 0;

    while(i < n1 && j < n2) {

        if(arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        }
        else {
            result[k++] = arr2[j++];
        }
    }

    // remaining elements
    while(i < n1) {
        result[k++] = arr1[i++];
    }

    while(j < n2) {
        result[k++] = arr2[j++];
    }

    printf("Merged Array:\n");

    for(int x = 0; x < k; x++) {
        printf("%d ", result[x]);
    }

    return 0;
}