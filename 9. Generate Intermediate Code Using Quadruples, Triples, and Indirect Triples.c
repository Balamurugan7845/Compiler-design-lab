#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char expr[100], postfix[100];
char opstack[100];
int top = -1;

char qop[100][5], qarg1[100][10];
char qarg2[100][10], qresult[100][10];
char values[100][10];

int n = 0;

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
            postfix[j++] = ch;
        else if (ch == '(')
            opstack[++top] = ch;
        else if (ch == ')')
        {
            while (top >= 0 && opstack[top] != '(')
                postfix[j++] = opstack[top--];

            if (top >= 0)
                top--;
        }
        else
        {
            while (top >= 0 &&
                   opstack[top] != '(' &&
                   precedence(opstack[top]) >= precedence(ch))
            {
                postfix[j++] = opstack[top--];
            }

            opstack[++top] = ch;
        }
    }

    while (top >= 0)
        postfix[j++] = opstack[top--];

    postfix[j] = '\0';
}

void main()
{
    int i, sp = -1, k;
    char a[10], b[10], temp[10];

    clrscr();

    printf("INTERMEDIATE CODE GENERATION\n");
    printf("----------------------------\n");
    printf("Enter expression: ");
    scanf("%99s", expr);

    convert();

    printf("\nPostfix Expression: %s\n", postfix);

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

            strcpy(qop[n], "");
            qop[n][0] = postfix[i];
            qop[n][1] = '\0';

            strcpy(qarg1[n], a);
            strcpy(qarg2[n], b);

            sprintf(temp, "t%d", n + 1);
            strcpy(qresult[n], temp);

            strcpy(values[++sp], temp);
            n++;
        }
    }

    printf("\nQUADRUPLES\n");
    printf("---------------------------------\n");
    printf("No.\tOp\tArg1\tArg2\tResult\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%s\t%s\t%s\n",
               i, qop[i], qarg1[i],
               qarg2[i], qresult[i]);
    }

    printf("\nTRIPLES\n");
    printf("---------------------------------\n");
    printf("No.\tOp\tArg1\tArg2\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%s\t%s\n",
               i, qop[i], qarg1[i], qarg2[i]);
    }

    printf("\nINDIRECT TRIPLES\n");
    printf("---------------------------------\n");
    printf("Pointer\tTriple No.\n");

    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, i);

    getch();
}
