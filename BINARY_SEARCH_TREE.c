// to check the binary tree is a binary search tree or not
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

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("% d ", root->data);
        inorder(root->right);
    }
}

int isbst(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isbst(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data < prev->data)
        {
            return 0;
        }
        prev = root;
        return (isbst(root->right));
    }
    else
    {
        return 1;
    }
}
int main()
{

    struct node *root = create_node(5);
    struct node *p1 = create_node(3);
    struct node *p2 = create_node(6);
    struct node *p3 = create_node(1);
    struct node *p4 = create_node(4);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;

    //          5
    //         /  \
    //        3    6
    //      /  \
    //     1     4

    // 5-3-6-1-4

    inorder(root);

    printf("\n");
    printf("%d ", isbst(root));

    return 0;
}