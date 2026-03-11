#include <stdio.h>

int main() {

    int arr[6] = {10, 23, 45, 8, 12, 7};
    int i;
    int even = 0, odd = 0;

    for(i = 0; i < 6; i++) {

        if(arr[i] % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }

    }

    printf("Even numbers = %d\n", even);
    printf("Odd numbers = %d\n", odd);

    return 0;
}