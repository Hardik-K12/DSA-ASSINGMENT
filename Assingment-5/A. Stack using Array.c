
#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

// Insert an element into the stack
void push()
{
    int x;

    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

// Remove the top element
void pop()
{
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Deleted element: %d\n", stack[top--]);
}

// Display stack from top to bottom
void display()
{
    int i;

    if (top == -1)
        printf("Stack is empty\n");
    else
    {
        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
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
