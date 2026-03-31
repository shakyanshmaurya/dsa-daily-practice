#include <stdio.h>
#include <string.h>

int main() {

    char str1[100], str2[100], temp[200];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // length check
    if(strlen(str1) != strlen(str2)) {
        printf("Not Rotation");
        return 0;
    }

    // concatenate str1 with itself
    strcpy(temp, str1);
    strcat(temp, str1);

    // check substring
    if(strstr(temp, str2) != NULL)
        printf("Rotation Strings");
    else
        printf("Not Rotation");

    return 0;
}