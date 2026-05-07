#include <stdio.h>

int main() {

    int arr[] = {1, 3, 4, 2, 2};
    int n = 5;

    int duplicate = -1;

    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {

            if(arr[i] == arr[j]) {
                duplicate = arr[i];
            }
        }
    }

    printf("Duplicate Number = %d", duplicate);

    return 0;
}