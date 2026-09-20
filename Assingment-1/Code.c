#include <stdio.h>

// Function declarations
int pallindrome(char input[]);
void copy(char input[], char output[]);
int stringlength(char input[]);
void substring(char input[]);
void reverse(char input[]);

int main()
{
    int ch;
    char str[50];
    char output[50];

    // Taking string from user
    printf("Enter a string: ");
    scanf("%49s", str);

    // Display menu
    printf("\nChoose an Operation:\n");
    printf("1. Check Palindrome\n");
    printf("2. Copy String\n");
    printf("3. Check String Length\n");
    printf("4. Substring\n");
    printf("5. Reverse String\n");

    // Taking choice from user
    printf("Enter your choice: ");
    scanf("%d", &ch);

    // Perform operation according to choice
    switch(ch)
    {
        case 1:
        {
            // Check palindrome
            int c = pallindrome(str);

            if(c == 1)
                printf("Palindrome\n");
            else
                printf("Not a Palindrome\n");

            break;
        }

        case 2:
            // Copy string
            copy(str, output);
            break;

        case 3:
            // Find string length
            printf("String length is: %d\n", stringlength(str));
            break;

        case 4:
            // Find substring
            substring(str);
            break;

        case 5:
            // Reverse the string
            reverse(str);
            break;

        default:
            // If wrong choice is entered
            printf("Invalid choice\n");
    }

    return 0;
}

// Function to find length of string
int stringlength(char input[])
{
    int i = 0;

    // Count characters until null character
    while(input[i] != '\0')
    {
        i++;
    }

    return i;
}

// Function to check palindrome
int pallindrome(char input[])
{
    int i = 0;
    int j = stringlength(input) - 1;

    // Compare characters from both ends
    while(i < j)
    {
        if(input[i] != input[j])
        {
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}

// Function to copy one string into another
void copy(char input[], char output[])
{
    int i;

    // Copy characters one by one
    for(i = 0; input[i] != '\0'; i++)
    {
        output[i] = input[i];
    }

    // Add null character at end
    output[i] = '\0';

    printf("Output string is: %s\n", output);
}

// Function to find substring
void substring(char input[])
{
    int i, position;
    char output[50];

    int n = stringlength(input);

    // Taking starting position
    printf("Enter the position of substring: ");
    scanf("%d", &position);

    // Check whether position is valid
    if(position >= 0 && position < n)
    {
        // Copy substring from given position
        for(i = 0; i < n - position; i++)
        {
            output[i] = input[position + i];
        }

        output[i] = '\0';

        printf("Input string: %s\n", input);
        printf("Output substring: %s\n", output);
    }
    else
    {
        printf("Position entered is out of range\n");
    }
}

// Function to reverse string
void reverse(char input[])
{
    int i;
    int n = stringlength(input);
    char output[50];

    // Store characters in reverse order
    for(i = 0; i < n; i++)
    {
        output[n - 1 - i] = input[i];
    }

    output[n] = '\0';

    printf("Input string: %s\n", input);
    printf("Output (reversed) String: %s\n", output);
}
