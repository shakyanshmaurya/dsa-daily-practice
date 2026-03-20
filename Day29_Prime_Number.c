#include <stdio.h>

int main() {

    int num, i, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num <= 1) {
        isPrime = 0;
    }

    for(i = 2; i < num; i++) {
        if(num % i == 0) {
            isPrime = 0;
            break;
        }
    }

    if(isPrime)
        printf("Prime Number");
    else
        printf("Not a Prime Number");

    return 0;
}