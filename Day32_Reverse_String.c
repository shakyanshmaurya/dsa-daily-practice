#include <stdio.h>

int main() {

    char str[100];
    int i, length = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    // Length find
    while(str[length] != '\0') {
        length++;
    }

    printf("Reversed String: ");

    for(i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    return 0;
}