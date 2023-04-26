#include <stdio.h>
#include <stdlib.h>

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
        printf("Stack is empty\n");
        exit(1);
    }
    else
    {
        int x = stack[top];
        top--;
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

int evaluate_expression(char exp[])
{
    for (int i = 0; exp[i]; i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0'); // convert char to int
        }
        else
        {
            int operand1 = pop();
            int operand2 = pop();
            switch (exp[i])
            {
            case '+':
                push(operand2 + operand1);
                break;

            case '-':
                push(operand2 - operand1);
                break;

            case '*':
                push(operand2 * operand1);
                break;

            case '/':
                if (operand1 == 0)
                {
                    printf("Division by zero\n");
                    exit(1);
                }
                push(operand2 / operand1);
                break;

            default:
                printf("Invalid operator\n");
                exit(1);
            }
        }
    }

    int finalresult = pop();
    if (!isempty())
    {
        printf("Invalid expression\n");
        exit(1);
    }
    return finalresult;
}

int main()
{
    char expression[MAX];
    printf("Enter postfix expression to evaluate: ");
    scanf("%s", expression);

    int result = evaluate_expression(expression);
    printf("Result: %d\n", result);

    return 0;
}
