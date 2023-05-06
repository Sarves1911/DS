#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct
{
    int data;
    int priority;
} element;

element queue[MAX_QUEUE_SIZE];
int front = 0, rear = 0;

int is_empty()
{
    return front == rear;
}

int is_full()
{
    return (rear + 1) % MAX_QUEUE_SIZE == front;
}

void enqueue(element item)
{
    if (is_full())
    {
        printf("Queue is full.\n");
        return;
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    queue[rear] = item;
}

element dequeue()
{
    if (is_empty())
    {
        printf("Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    front = (front + 1) % MAX_QUEUE_SIZE;
    return queue[front];
}

void display()
{
    if (is_empty())
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = (front + 1) % MAX_QUEUE_SIZE; i != (rear + 1) % MAX_QUEUE_SIZE; i = (i + 1) % MAX_QUEUE_SIZE)
    {
        printf("(%d, %d) ", queue[i].data, queue[i].priority);
    }
    printf("\n");
}

int main()
{
    // Example usage:
    enqueue((element){.data = 10, .priority = 3});
    enqueue((element){.data = 20, .priority = 1});
    enqueue((element){.data = 30, .priority = 2});
    display(); // Should print: Queue: (20, 1) (30, 2) (10, 3)
    dequeue();
    display(); // Should print: Queue: (30, 2) (10, 3)
    return 0;
}
