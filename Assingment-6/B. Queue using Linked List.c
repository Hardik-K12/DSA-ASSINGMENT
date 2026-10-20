
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

// Insert a new node at the rear
void enqueue()
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
    newnode->next = NULL;

    // First node becomes both front and rear
    if (front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

// Delete a node from the front
void dequeue()
{
    struct node *temp;

    if (front == NULL)
        printf("Queue is empty\n");
    else
    {
        temp = front;
        printf("Deleted element: %d\n", front->data);

        front = front->next;

        // If queue becomes empty, reset rear too
        if (front == NULL)
            rear = NULL;

        free(temp);
    }
}

// Display queue elements
void display()
{
    struct node *temp = front;

    if (front == NULL)
        printf("Queue is empty\n");
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
        printf("\n1.Enqueue  2.Dequeue  3.Display  4.Exit\n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 4);

    return 0;
}
