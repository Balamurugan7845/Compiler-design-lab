#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>

char expr[100];
char *p;
int error = 0;

void skip()
{
    while(*p == ' ')
        p++;
}

long factor()
{
    long n = 0;

    skip();

    if(*p == '(')
    {
        p++;
        n = 0;

        /* Parse expression inside brackets */
        {
            long a, b;
            char op;

            a = factor();

            while(*p == '*' || *p == '/')
            {
                op = *p++;
                b = factor();

                if(op == '*')
                    a = a * b;
                else if(b != 0)
                    a = a / b;
                else
                    error = 1;
            }

            n = a;
        }

        skip();

        if(*p == ')')
            p++;
        else
            error = 1;

        return n;
    }

    if(!isdigit(*p))
    {
        error = 1;
        return 0;
    }

    while(isdigit(*p))
    {
        n = n * 10 + (*p - '0');
        p++;
    }

    return n;
}

long term()
{
    long a, b;
    char op;

    a = factor();

    while(1)
    {
        skip();

        if(*p != '*' && *p != '/')
            break;

        op = *p++;
        b = factor();

        if(op == '*')
            a = a * b;
        else if(b != 0)
            a = a / b;
        else
            error = 1;
    }

    return a;
}

long expression()
{
    long a, b;
    char op;

    a = term();

    while(1)
    {
        skip();

        if(*p != '+' && *p != '-')
            break;

        op = *p++;
        b = term();

        if(op == '+')
            a = a + b;
        else
            a = a - b;
    }

    return a;
}

void main()
{
    long result;

    clrscr();

    printf("CONSTANT FOLDING OPTIMIZATION\n");
    printf("----------------------------\n");

    printf("Enter arithmetic expression: ");
    gets(expr);

    p = expr;

    result = expression();

    skip();

    if(error || *p != '\0')
    {
        printf("\nInvalid expression or division by zero.");
    }
    else
    {
        printf("\nOriginal Expression: %s", expr);
        printf("\nOptimized Expression: %ld", result);
        printf("\n\nConstant Folding Completed.");
    }

    getch();
}