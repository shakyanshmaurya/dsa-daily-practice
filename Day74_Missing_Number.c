#include <stdio.h>

int main() {

    int arr[] = {1, 2, 4, 5};
    int n = 5; // total numbers should be 1 to 5

    int expectedSum = n * (n + 1) / 2;
    int actualSum = 0;

    for(int i = 0; i < n - 1; i++) {
        actualSum += arr[i];
    }

    int missing = expectedSum - actualSum;

    printf("Missing Number = %d", missing);

    return 0;
}