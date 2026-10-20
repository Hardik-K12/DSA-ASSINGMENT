
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

// Create a new node
struct node *create(int x)
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newnode->data = x;
    newnode->left = newnode->right = NULL;

    return newnode;
}

// Insert values according to BST rules
struct node *insert(struct node *root, int x)
{
    if (root == NULL)
        return create(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

// Search for a value in the BST
void search(struct node *root, int x)
{
    if (root == NULL)
        printf("Element not found\n");
    else if (root->data == x)
        printf("Element found\n");
    else if (x < root->data)
        search(root->left, x);
    else
        search(root->right, x);
}

// Inorder: Left, Root, Right
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder: Root, Left, Right
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left, Right, Root
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    int ch, x;

    do
    {
        printf("\n1.Create/Insert  2.Search");
        printf("\n3.Inorder  4.Preorder  5.Postorder  6.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &x);
                search(root, x);
                break;

            case 3:
                inorder(root);
                printf("\n");
                break;

            case 4:
                preorder(root);
                printf("\n");
                break;

            case 5:
                postorder(root);
                printf("\n");
                break;
        }
    } while (ch != 6);

    return 0;
}
