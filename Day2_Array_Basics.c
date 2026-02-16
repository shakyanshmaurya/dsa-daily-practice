#include <stdio.h>

int main() {
    int arr[5];
    int sum = 0;
    int i;

    printf("Enter 5 numbers: ");

    for(i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum = %d", sum);

    return 0;
}