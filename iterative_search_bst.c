
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
/* RECURSIVE METHOD
struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (key == root->data)
    {
        return root;
    }
    else if (key > root->data)
    {
        return search(root->right, key);
    }
    else
    {
        return search(root->left, key);
    }
}
*/

struct node *search(struct node *root, int key)
{

    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
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
    return NULL;
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

    int key;
    printf("Enter element to search \n");
    scanf("%d", &key);

    struct node *result = search(root, key);
    if (result != NULL)
    {
        printf("%d is present in the tree \n ", result->data);
    }
    else
    {
        printf("Given element is not present in the tree \n");
    }

    return 0;
}