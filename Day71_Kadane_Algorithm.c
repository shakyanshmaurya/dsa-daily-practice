#include <stdio.h>
#include <limits.h>

int main() {

    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = 9;

    int currentSum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++) {

        currentSum += arr[i];

        if(currentSum > maxSum) {
            maxSum = currentSum;
        }

        if(currentSum < 0) {
            currentSum = 0;
        }
    }

    printf("Maximum Subarray Sum = %d", maxSum);

    return 0;
}