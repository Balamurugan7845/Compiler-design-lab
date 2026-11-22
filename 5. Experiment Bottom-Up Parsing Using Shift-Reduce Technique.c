#include <stdio.h>
#include <conio.h>
#include <string.h>

char stack[100];
char input[100];

int top = -1;
int ip = 0;


void display()
{
    int i;

    printf("\nStack: ");

    for (i = 0; i <= top; i++)
        printf("%c", stack[i]);

    printf("\tInput: ");

    for (i = ip; input[i] != '\0'; i++)
        printf("%c", input[i]);
}


void shift()
{
    stack[++top] = input[ip++];
    printf("\nSHIFT");
    display();
}


int reduce()
{

    if (top >= 0 && stack[top] == 'i')
    {
        stack[top] = 'E';

        printf("\nREDUCE E -> i");
        display();

        return 1;
    }

 
    if (top >= 2 &&
        stack[top - 2] == '(' &&
        stack[top - 1] == 'E' &&
        stack[top] == ')')
    {
        top = top - 2;
        stack[top] = 'E';

        printf("\nREDUCE E -> (E)");
        display();

        return 1;
    }

   
    if (top >= 2 &&
        stack[top - 2] == 'E' &&
        stack[top - 1] == '+' &&
        stack[top] == 'E')
    {
        top = top - 2;
        stack[top] = 'E';

        printf("\nREDUCE E -> E+E");
        display();

        return 1;
    }


    if (top >= 2 &&
        stack[top - 2] == 'E' &&
        stack[top - 1] == '*' &&
        stack[top] == 'E')
    {
        top = top - 2;
        stack[top] = 'E';

        printf("\nREDUCE E -> E*E");
        display();

        return 1;
    }

    return 0;
}

void main()
{
    int changed;

    clrscr();

    printf("BOTTOM-UP PARSER\n");
    printf("-----------------\n");

    printf("Grammar:\n");
    printf("E -> E+E\n");
    printf("E -> E*E\n");
    printf("E -> (E)\n");
    printf("E -> i\n");

    printf("\nEnter input string: ");
    scanf("%s", input);

    
    strcat(input, "$");

    printf("\nParsing Steps:\n");

    while (input[ip] != '$')
    {
        shift();

        /* Perform reductions repeatedly */
        do
        {
            changed = reduce();
        }
        while (changed);
    }

  
    do
    {
        changed = reduce();
    }
    while (changed);

    printf("\n\nFinal Stack: ");

    if (top >= 0)
    {
        int i;

        for (i = 0; i <= top; i++)
            printf("%c", stack[i]);
    }

    printf("\n");

    if (top == 0 && stack[0] == 'E' && input[ip] == '$')
    {
        printf("\nResult: STRING ACCEPTED");
    }
    else
    {
        printf("\nResult: STRING REJECTED");
    }

    getch();
}
