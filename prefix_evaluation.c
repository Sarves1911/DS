#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int stack[MAX];
int top = -1;

void push(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack is full\n");
        exit(1);
    }
    else
    {
        top++;
        stack[top] = x;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack is Empty \n");
        exit(1);
    }
    else
    {
        int x = stack[top];
        top = top - 1;
        return x;
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

int prefix_evaluation(char exp[], int n)
{

    for (int i = n - 1; i >= 0; i--)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            int operand1 = pop();
            int operand2 = pop();
            switch (exp[i])
            {
            case '+':
                push(operand1 + operand2);
                break;

            case '-':
                push(operand1 - operand2);
                break;

            case '*':
                push(operand1 * operand2);
                break;

            case '/':
                if (operand2 == 0)
                {
                    printf("Division by zero\n");
                    exit(1);
                }
                push(operand1 / operand2);
                break;

            default:
                printf("Invalid operator\n");
                exit(1);
            }
        }
    }

    int final_result = pop();
    if (!isempty())
    {
        printf("Invalid Expression \n");
        exit(1);
    }
    return final_result;
}

int main()
{
    char expression[MAX];
    printf("Enter prefix expression to evaluate: ");
    scanf("%s", expression);
    int size;
    size = strlen(expression);
    int result = prefix_evaluation(expression, size);
    printf("Result is %d \n", result);

    return 0;
}