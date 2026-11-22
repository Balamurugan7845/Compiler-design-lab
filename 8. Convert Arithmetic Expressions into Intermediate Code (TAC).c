#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
char postfix[100];
char expr[100];
int top = -1;

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void convert()
{
    int i, j = 0;
    char ch;

    for (i = 0; expr[i] != '\0'; i++)
    {
        ch = expr[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = stack[top--];

            if (top >= 0)
                top--;
        }
        else
        {
            while (top >= 0 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }
    }

    while (top >= 0)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';
}

void main()
{
    char values[100][10];
    char a[10], b[10], temp[10];
    int i, sp = -1, count = 0;

    clrscr();

    printf("THREE ADDRESS CODE GENERATION\n");
    printf("-----------------------------\n");
    printf("Enter expression: ");
    scanf("%99s", expr);

    convert();

    printf("\nPostfix Expression: %s\n", postfix);
    printf("\nThree Address Code:\n");

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            values[++sp][0] = postfix[i];
            values[sp][1] = '\0';
        }
        else
        {
            strcpy(b, values[sp--]);
            strcpy(a, values[sp--]);

            count++;
            sprintf(temp, "t%d", count);

            printf("%s = %s %c %s\n",
                   temp, a, postfix[i], b);

            strcpy(values[++sp], temp);
        }
    }

    getch();
}
