#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    char exp1[20], exp2[20];
    char op1, op2;
    char a1, b1, a2, b2;

    clrscr();

    printf("COMMON SUB-EXPRESSION ELIMINATION\n");
    printf("---------------------------------\n");

    printf("Enter first expression (a+b): ");
    scanf("%19s", exp1);

    printf("Enter second expression (a+b): ");
    scanf("%19s", exp2);

    if(strlen(exp1) != 3 || strlen(exp2) != 3 ||
       exp1[1] != '+' && exp1[1] != '-' &&
       exp1[1] != '*' && exp1[1] != '/')
    {
        printf("\nInvalid expression.");
        getch();
        return;
    }

    a1 = exp1[0];
    op1 = exp1[1];
    b1 = exp1[2];

    a2 = exp2[0];
    op2 = exp2[1];
    b2 = exp2[2];

    printf("\nOriginal Code:\n");
    printf("t1 = %s\n", exp1);
    printf("t2 = %s\n", exp2);

    printf("\nOptimized Code:\n");

    if(a1 == a2 && b1 == b2 && op1 == op2)
    {
        printf("t1 = %c %c %c\n", a1, op1, b1);
        printf("t2 = t1\n");

        printf("\nCommon Sub-expression Found!");
    }
    else
    {
        printf("t1 = %c %c %c\n", a1, op1, b1);
        printf("t2 = %c %c %c\n", a2, op2, b2);

        printf("\nNo Common Sub-expression Found.");
    }

    getch();
}