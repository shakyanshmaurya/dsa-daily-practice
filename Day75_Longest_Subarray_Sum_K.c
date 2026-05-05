#include <stdio.h>

int main() {

    int arr[] = {1, 2, 3, 1, 1, 1, 1};
    int n = 7;
    int k = 3;

    int maxLen = 0;

    for(int i = 0; i < n; i++) {

        int sum = 0;

        for(int j = i; j < n; j++) {

            sum += arr[j];

            if(sum == k) {
                int len = j - i + 1;
                if(len > maxLen) {
                    maxLen = len;
                }
            }
        }
    }

    printf("Longest Subarray Length = %d", maxLen);

    return 0;
}