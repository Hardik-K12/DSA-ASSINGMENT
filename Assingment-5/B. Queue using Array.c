
#include <stdio.h>
#define MAX 5

int queue[MAX], front = -1, rear = -1;

// Insert an element at the rear
void enqueue()
{
    int x;

    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter value: ");
        scanf("%d", &x);

        if (front == -1)
            front = 0;

        queue[++rear] = x;
    }
}

// Remove an element from the front
void dequeue()
{
    if (front == -1)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted element: %d\n", queue[front++]);

        // Reset queue when it becomes empty
        if (front > rear)
            front = rear = -1;
    }
}

// Display queue elements
void display()
{
    int i;

    if (front == -1)
        printf("Queue is empty\n");
    else
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
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
