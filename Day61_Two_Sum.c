#include <stdio.h>

int main() {

    int arr[] = {2, 7, 11, 15};
    int n = 4;
    int target = 9;

    for(int i = 0; i < n; i++) {

        for(int j = i + 1; j < n; j++) {

            if(arr[i] + arr[j] == target) {
                printf("Pair found: %d + %d = %d\n", arr[i], arr[j], target);
            }
        }
    }

    return 0;
}