//Array Implementation of  Circular queues

#include<stdio.h>
#define MAX 100
int front= -1;
int rear =-1;
int A[MAX];

void enqueue(int x)
{
    if ((rear +1)%MAX==front)
    {
        printf("Queue is full \n");
        return ;
    }
    else if (front==-1 && rear==-1)
    {
        front=rear=0;
        A[rear]=x;

    }
    else
    {
        rear=(rear+1)%MAX;
        A[rear]=x;
    }
}

int isempty()
{
    if (front==-1 && rear==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is empty \n");
        return ;
    }
    else if (front == rear) 
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1)%MAX;
    }
}

int main()
{
    enqueue(4);
    dequeue();
    enqueue(6);
    enqueue(9);
    enqueue(6);
    enqueue(9);
    enqueue(5);
    dequeue();

   for (int i =front; i <=rear; i++)
    {
        printf("%d \n", A[i]);
    }
    return 0;
}