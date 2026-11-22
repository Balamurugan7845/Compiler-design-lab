#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {
    "int", "float", "char", "if",
    "else", "while", "for", "return"
};

int isKeyword(char str[])
{
    int i;

    for (i = 0; i < 8; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

void main()
{
    char input[200];
    char token[50];

    int i = 0;
    int j;

    clrscr();

    printf("LEXICAL ANALYZER\n");
    printf("----------------\n");

    printf("Enter input:\n");
    gets(input);

    printf("\nTokens:\n");

    while (input[i] != '\0')
    {
        
        if (input[i] == ' ' || input[i] == '\t')
        {
            i++;
        }

     
        else if (isalpha(input[i]) || input[i] == '_')
        {
            j = 0;

            while (isalnum(input[i]) || input[i] == '_')
            {
                token[j] = input[i];
                j++;
                i++;
            }

            token[j] = '\0';

            if (isKeyword(token))
                printf("Keyword    : %s\n", token);
            else
                printf("Identifier : %s\n", token);
        }

        
        else if (isdigit(input[i]))
        {
            j = 0;

            while (isdigit(input[i]))
            {
                token[j] = input[i];
                j++;
                i++;
            }

            token[j] = '\0';

            printf("Number     : %s\n", token);
        }

  
        else if (input[i] == '+' ||
                 input[i] == '-' ||
                 input[i] == '*' ||
                 input[i] == '/' ||
                 input[i] == '=' ||
                 input[i] == '<' ||
                 input[i] == '>')
        {
            printf("Operator   : %c\n", input[i]);
            i++;
        }

      
        else
        {
            printf("Symbol     : %c\n", input[i]);
            i++;
        }
    }

    getch();
}