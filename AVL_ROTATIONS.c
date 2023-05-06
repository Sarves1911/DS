#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}

int getheight(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }

    return n->height;
}

int getbalancefactor(struct node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (getheight(n->right) - getheight(n->left));
}
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
struct node *leftrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *t2 = x->right;

    // after rotation

    x->right = y;
    y->left = t2;

    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    return x; // new root node after rotation
}

struct node *rightrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *t2 = y->left;

    // after rotation

    y->left = x;
    x->right = t2;
    x->height = max(getheight(x->left), getheight(x->right)) + 1;
    y->height = max(getheight(y->left), getheight(y->right)) + 1;

    return y;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        return createnode(key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }

    root->height = max(getheight(root->left), getheight(root->right)) + 1;

    int bf = getbalancefactor(root);

    // Left Left Case
    if (bf > 1 && root->left->data > key)
    {
        return rightrotate(root);
    }

    // Right Right Case
    if (bf < -1 && root->right->data < key)
    {
        return leftrotate(root);
    }

    // Left Right Case
    if (bf > 1 && root->left->data < key)
    {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    // Right Left Case
    if (bf < -1 && root->right->data > key)
    {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
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

int main()
{
    struct node *root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Inorder traversal of the constructed AVL tree:\n");
    inorder(root);
    printf("\n");

    return 0;
}
