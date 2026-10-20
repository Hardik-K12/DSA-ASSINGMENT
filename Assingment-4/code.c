#include <stdio.h>

// Structure to store student details
struct student
{
    int roll;
    char name[80];
    float SGPA;
};

// Function to enter student details
void create(struct student arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("\nEnter details of student %d:\n", i + 1);

        // Taking student name
        printf("Enter Name: ");
        scanf("%s", arr[i].name);

        // Taking roll number
        printf("Enter Roll No: ");
        scanf("%d", &arr[i].roll);

        // Taking SGPA
        printf("Enter SGPA: ");
        scanf("%f", &arr[i].SGPA);
    }
}

// Function to display student details
void display(struct student arr[], int n)
{
    printf("\nStudent Details:\n");

    for(int i = 0; i < n; i++)
    {
        printf("\nName: %s", arr[i].name);
        printf("\nRoll No: %d", arr[i].roll);
        printf("\nSGPA: %.2f\n", arr[i].SGPA);
    }
}

// Function to search student using roll number
void search(struct student arr[], int n)
{
    int roll;

    printf("\nEnter roll number to search: ");
    scanf("%d", &roll);

    // Check roll number in the array
    for(int i = 0; i < n; i++)
    {
        if(arr[i].roll == roll)
        {
            printf("\nStudent found!\n");

            printf("Name: %s\n", arr[i].name);
            printf("Roll No: %d\n", arr[i].roll);
            printf("SGPA: %.2f\n", arr[i].SGPA);

            return;
        }
    }

    // If roll number is not found
    printf("\nStudent not found.\n");
}

int main()
{
    struct student s[100];
    int n;

    // Taking number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Enter student details
    create(s, n);

    // Display all student details
    display(s, n);

    // Search student by roll number
    search(s, n);

    return 0;
}
