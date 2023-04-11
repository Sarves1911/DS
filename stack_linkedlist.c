#include<stdio.h>
struct node *top=NULL;

struct node
{
    int data;
    struct node* next;
};

void push(int x)
{
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=top;
    top=temp;

}

void pop()
{
    struct node *temp;
    if (top==NULL)
    {
        return;
    }
    temp=top;
    top=top->next;
    free(temp);
    
}

void isempty()
{
    if (top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
    
}

void display(struct node * ptr)
{
while (ptr!=NULL)
{
    printf("%d \n",ptr->data);
    ptr=ptr->next;
}

}

int main()
{
   push(2);
   push(3);
   push(5);
   pop();
   push(10);
   push(19);
   pop();

   display(top);

}
