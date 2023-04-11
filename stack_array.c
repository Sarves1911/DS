#include <stdio.h>
#define MAX 100

int A[MAX];
int top = -1;

void push(int x) {
    top = top + 1;
    A[top] = x;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    top = top - 1;
}

int isempty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void display() {
    if (isempty()) {
        printf("Empty Stack\n");
        return;
    }
    for (int i = 0; i <= top; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    printf("Stack Implementation Using Arrays\n");
    push(3);
    if (!isempty()) {
        pop();
    }
    push(5);
    push(7);
    push(0);
    display();
    return 0;
}
