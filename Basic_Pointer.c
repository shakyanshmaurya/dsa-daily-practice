#include <stdio.h>

int main() {
    int num = 10;
    int *ptr;

    ptr = &num;   // pointer me num ka address store

    printf("Value of num: %d\n", num);
    printf("Address of num: %p\n", &num);

    printf("Pointer ptr stores address: %p\n", ptr);
    printf("Value at address stored in ptr: %d\n", *ptr);

    return 0;
}