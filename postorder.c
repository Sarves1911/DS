#include <stdio.h>

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

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf(" %d ", root->data);
    }
}

int main()
{

    struct node *root = create_node(4);
    struct node *p1 = create_node(1);
    struct node *p2 = create_node(6);
    struct node *p3 = create_node(5);
    struct node *p4 = create_node(2);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    //          4
    //         /  \
    //        1    6
    //      /  \
    //     5     2

    // 5-2-1-6-4

    postorder(root);
    return 0;
}