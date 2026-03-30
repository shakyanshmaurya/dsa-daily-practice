#include <stdio.h>

int main() {

    char str[100];
    int count[26] = {0};
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    // count frequency
    for(i = 0; str[i] != '\0'; i++) {
        count[str[i] - 'a']++;
    }

    // find first non-repeating
    for(i = 0; str[i] != '\0'; i++) {
        if(count[str[i] - 'a'] == 1) {
            printf("First non-repeating character = %c", str[i]);
            return 0;
        }
    }

    printf("No non-repeating character found");

    return 0;