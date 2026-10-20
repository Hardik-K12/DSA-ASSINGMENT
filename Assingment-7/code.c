
#include <stdio.h>
#include <ctype.h>

int stack[100], top = -1;

int main()
{
    char exp[100], ch;
    int i, a, b, result;

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    for (i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];

        // Push the number onto the stack
        if (isdigit((unsigned char)ch))
        {
            stack[++top] = ch - '0';
        }
        else
        {
            // Two operands are needed for an operator
            if (top < 1)
            {
                printf("Invalid expression\n");
                return 1;
            }

            // Pop operands in the correct order
            b = stack[top--];
            a = stack[top--];

            switch (ch)
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;

                case '/':
                    if (b == 0)
                    {
                        printf("Division by zero\n");
                        return 1;
                    }
                    result = a / b;
                    break;

                default:
                    printf("Invalid operator\n");
                    return 1;
            }

            // Push the calculated result back
            stack[++top] = result;
        }
    }

    // A valid expression should leave one result
    if (top == 0)
        printf("Result = %d\n", stack[top]);
    else
        printf("Invalid expression\n");

    return 0;
}
