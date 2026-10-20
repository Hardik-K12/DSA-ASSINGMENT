
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

// Push a new node onto the stack
void push()
{
    struct node *newnode;
    int x;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

// Pop the top node
void pop()
{
    struct node *temp;

    if (top == NULL)
        printf("Stack Underflow\n");
    else
    {
        temp = top;
        printf("Deleted element: %d\n", top->data);

        top = top->next;
        free(temp);  // Release deleted node memory
    }
}

// Display all stack elements
void display()
{
    struct node *temp = top;

    if (top == NULL)
        printf("Stack is empty\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int ch;

    do
    {
        printf("\n1.Push  2.Pop  3.Display  4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
        }
    } while (ch != 4);

    return 0;
}
