#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char ch) {
    stack[++top] = ch;
}

char pop() {
    return stack[top--];
}

int isMatching(char open, char close) {

    if(open == '(' && close == ')')
        return 1;

    if(open == '{' && close == '}')
        return 1;

    if(open == '[' && close == ']')
        return 1;

    return 0;
}

int main() {

    char str[] = "{[()]}";
    int valid = 1;

    for(int i = 0; i < strlen(str); i++) {

        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        }
        else {

            if(top == -1) {
                valid = 0;
                break;
            }

            char topChar = pop();

            if(!isMatching(topChar, ch)) {
                valid = 0;
                break;
            }
        }
    }

    if(top != -1)
        valid = 0;

    if(valid)
        printf("Valid Parentheses");
    else
        printf("Invalid Parentheses");

    return 0;
}