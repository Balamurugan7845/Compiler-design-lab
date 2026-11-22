#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
    int n, i;
    char result[10], op1[10], op2[10], oper;
    char instruction[100];

    clrscr();

    printf("TARGET CODE GENERATION\n");
    printf("----------------------\n");

    printf("Enter number of TAC instructions: ");
    scanf("%d", &n);

    printf("\nEnter instructions (example: t1=a+b)\n");

    printf("\nGenerated Target Code:\n");
    printf("----------------------\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s", instruction);

        if (sscanf(instruction, "%[^=]=%[^+-*/]%c%[^+-*/]",
                   result, op1, &oper, op2) != 4)
        {
            printf("Invalid instruction: %s\n", instruction);
            continue;
        }

        printf("\nMOV R0, %s\n", op1);

        switch (oper)
        {
            case '+':
                printf("ADD R0, %s\n", op2);
                break;

            case '-':
                printf("SUB R0, %s\n", op2);
                break;

            case '*':
                printf("MUL R0, %s\n", op2);
                break;

            case '/':
                printf("DIV R0, %s\n", op2);
                break;

            default:
                printf("Invalid operator\n");
                continue;
        }

        printf("MOV %s, R0\n", result);
    }

    getch();
}
