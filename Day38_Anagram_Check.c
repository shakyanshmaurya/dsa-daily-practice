#include <stdio.h>

int main() {

    char str1[100], str2[100];
    int i, count[26] = {0};
    int isAnagram = 1;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // count characters of str1
    for(i = 0; str1[i] != '\0'; i++) {
        count[str1[i] - 'a']++;
    }

    // subtract characters of str2
    for(i = 0; str2[i] != '\0'; i++) {
        count[str2[i] - 'a']--;
    }

    // check all counts are zero
    for(i = 0; i < 26; i++) {
        if(count[i] != 0) {
            isAnagram = 0;
            break;
        }
    }

    if(isAnagram)
        printf("Anagram Strings");
    else
        printf("Not Anagram Strings");

    return 0;
}