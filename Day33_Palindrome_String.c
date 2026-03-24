#include <stdio.h>

int main() {

    char str[100];
    int i = 0, length = 0;
    int isPalindrome = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    // length find
    while(str[length] != '\0') {
        length++;
    }

    // check palindrome
    for(i = 0; i < length / 2; i++) {
        if(str[i] != str[length - i - 1]) {
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome)
        printf("Palindrome String");
    else
        printf("Not a Palindrome String");

    return 0;
}