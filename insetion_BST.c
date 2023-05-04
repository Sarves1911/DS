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

void insert(struct node *root, int key)
{
    struct node *prev = NULL;
    struct node *ptr = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Duplicate value found, insertion failed.\n");
            return;
        }
        else if (root->data > key)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }

    ptr = create_node(key);
    if (key > prev->data)
    {
        prev->right = ptr;
    }
    else
    {
        prev->left = ptr;
    }
    printf("Insertion successful.\n");
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

    insert(root, 6);
    insert(root, 2);
    insert(root, 7);
    insert(root, 4); // Duplicate value
    return 0;
}
