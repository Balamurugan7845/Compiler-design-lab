#include <stdio.h>
#include <conio.h>

void main()
{
    char input[100];
    int current[3] = {1, 0, 0};
    int next[3];

    int i, j;
    int symbol;

    clrscr();

    printf("NFA STRING VALIDATION\n");
    printf("---------------------\n");
    printf("Language: Strings containing 01\n");
    printf("Alphabet: {0, 1}\n\n");

    printf("Enter a binary string: ");
    scanf("%s", input);

    for (i = 0; i < 3; i++)
        next[i] = 0;

    printf("\nInitial State: {q0}\n");

    i = 0;

    while (input[i] != '\0')
    {
        if (input[i] != '0' && input[i] != '1')
        {
            printf("\nInvalid input symbol: %c", input[i]);
            getch();
            return;
        }

        symbol = input[i] - '0';

        for (j = 0; j < 3; j++)
            next[j] = 0;

       

        
        if (current[0] == 1)
        {
            if (symbol == 0)
            {
                next[0] = 1;
                next[1] = 1;
            }
            else
            {
                next[0] = 1;
            }
        }

   
        if (current[1] == 1)
        {
            if (symbol == 1)
            {
                next[2] = 1;
            }
        }

     
        if (current[2] == 1)
        {
            next[2] = 1;
        }

        
        for (j = 0; j < 3; j++)
            current[j] = next[j];

        printf("After input '%c' : {", input[i]);

        if (current[0])
            printf("q0 ");

        if (current[1])
            printf("q1 ");

        if (current[2])
            printf("q2 ");

        printf("}\n");

        i++;
    }

   
    if (current[2] == 1)
        printf("\nResult: STRING ACCEPTED");
    else
        printf("\nResult: STRING REJECTED");

    getch();
}
