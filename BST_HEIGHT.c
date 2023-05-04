
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}
int height(struct node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else
    {
        int left_height = height(root->left);
        int right_height = height(root->right);
        if (left_height > right_height)
        {
            return left_height + 1;
        }
        else
        {
            return right_height + 1;
        }
    }
}

int main()
{

    struct node *root = create_node(5);
    struct node *p1 = create_node(3);
    struct node *p2 = create_node(16);
    struct node *p3 = create_node(1);
    struct node *p4 = create_node(4);
    struct node *p5 = create_node(18);
    struct node *p6 = create_node(8);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p2->left = p6;
    int h = height(root);
    printf("The height of the binary tree is: %d\n", h);

    return 0;
}