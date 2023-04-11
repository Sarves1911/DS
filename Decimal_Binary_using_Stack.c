//DECIMAL TI BINARY USING STACK

#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;

void dectobi(int x)
{
    int rem;
    while (x!=NULL)
    {
        rem=x%2;
        push(rem);
        x=x/2;
    }
}

void push(int x)
{
top=top+1;
stack[top]=x;
}

int pop()
 {
    int val;
    if (top == -1)
     {
        printf("Stack Underflow\n");
        return -1;
    }
    val=stack[top];
    top = top - 1;
    return val;
}

int isempty()
{
    if (top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }  
}

void print()
{
    while (!isempty())
    {
        printf("%d ", pop());
    }  
}

int main()
{
    int num;
    printf("Enter Number Decimal to Convert");
    scanf("%d",&num);
    dectobi(num);
    print();
    return 0;
}