
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

// non recursive
int min_bst(struct node *root)
{
    struct node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }

    return current->data;
}

int max_bst(struct node *root)
{
    struct node *current = root;
    while (current->right != NULL)
    {
        current = current->right;
    }
    return current->data;
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

    int min = min_bst(root);
    printf("%d ", min);

    int max = max_bst(root);
    printf("%d\n", max);

    return 0;
}