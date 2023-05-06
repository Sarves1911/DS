#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// rightmost child of the left subtree is inorder predesessor
struct node *inorderpre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *delete(struct node *root, int value)
{
    struct node *inpre;
    if (root == NULL)
    {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if (value > root->data)
    {
        root->right = delete (root->right, value);
    }
    else if (value < root->data)
    {
        root->left = delete (root->left, value);
    }
    else
    {
        inpre = inorderpre(root);
        root->data = inpre->data;
        root->left = delete (root->left, inpre->data);
    }

    return root;
}

int main()
{
    struct node *root = createnode(10);
    struct node *p1 = createnode(8);
    struct node *p2 = createnode(12);
    struct node *p3 = createnode(14);
    struct node *p4 = createnode(11);
    struct node *p5 = createnode(9);
    struct node *p6 = createnode(6);

    root->left = p1;
    root->right = p2;

    p2->left = p4;
    p2->right = p3;

    p1->left = p6;
    p1->right = p5;

    inorder(root);
    delete (root, 10);
    printf("\n");
    inorder(root);

    return 0;
}