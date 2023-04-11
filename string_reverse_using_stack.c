#include <stdio.h>
#define MAX 100

int top = -1;
char A[MAX];

void push(char c) {
    if (top == MAX - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    A[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
        return '\0';
    }
    return A[top--];
}

void reverseString(char array[]) {
    for (int i = 0; array[i] != '\0'; i++) {
        push(array[i]);
    }

    for (int i = 0; array[i] != '\0'; i++) {
        array[i] = pop();
    }
}

int main() {
    char string[MAX];
    printf("Enter String To Reverse: ");
    scanf("%s", string);

    printf("Original string: %s\n", string);
    reverseString(string);
    printf("Reversed string: %s\n", string);

    return 0;
}
