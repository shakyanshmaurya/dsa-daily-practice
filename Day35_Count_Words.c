#include <stdio.h>

int main() {

    char str[100];
    int i, count = 1;

    printf("Enter a sentence: ");
    scanf("%[^\n]", str);

    for(i = 0; str[i] != '\0'; i++) {

        if(str[i] == ' ') {
            count++;
        }

    }

    printf("Total words = %d", count);

    return 0;
}