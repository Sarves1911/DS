#include <stdio.h>
#define MAX 100
char Stack[MAX];

int top = -1;

void push(char x)
{
    if (top == MAX - 1)
    {
        printf("Stack is full \n");
        return;
    }
    else
    {
        top = top + 1;
        Stack[top] = x;
    }
}

void pop()
{

    if (top == -1)
    {
        printf("Stack is Empty \n");
        return;
    }
    else
    {
        top = top - 1;
    }
}

int isempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char string[MAX];
    printf("Enter String of Parenthesis \n");
    scanf("%s", string);
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '(')
        {
            push(string[i]);
        }
        else if (string[i] == ')')
        {
            pop();
        }
    }
    if (isempty() == 1)
    {
        printf("Expression is balanced \n");
    }
    else
    {
        printf("Expression is not balanced \n");
    }

    return 0;
}
