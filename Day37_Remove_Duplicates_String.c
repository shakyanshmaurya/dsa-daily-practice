#include <stdio.h>

int main() {

    char str[100];
    int i, j;

    printf("Enter a string: ");
    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++) {

        for(j = i + 1; str[j] != '\0'; j++) {

            if(str[i] == str[j]) {
                str[j] = '0';   // mark duplicate
            }
        }
    }

    printf("String after removing duplicates: ");

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] != '0') {
            printf("%c", str[i]);
        }
    }

    return 0;
