#include <stdio.h>
#include <string.h>

#define MAX 100000

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    if (top == -1)
        return '\0';
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isBalanced(char* s) {
    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else {
            if (isEmpty())
                return 0;

            char topChar = pop();

            if ((ch == ')' && topChar != '(') ||
                (ch == '}' && topChar != '{') ||
                (ch == ']' && topChar != '[')) {
                return 0;
            }
        }
    }

    return isEmpty();
}

int main() {
    char s[] = "{[()]}";

    if (isBalanced(s))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
