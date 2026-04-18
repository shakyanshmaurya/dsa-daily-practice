#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    int i = 0, j = n - 1, temp;

    while(i < j) {

        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }

    printf("Reversed Array:\n");

    for(int k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}