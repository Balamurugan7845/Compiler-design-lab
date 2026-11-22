#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char production[10][20];
char first[10][20];
char follow[10][20];

int n;
void add(char set[], char ch)
{
    int i;

    for (i = 0; set[i] != '\0'; i++)
    {
        if (set[i] == ch)
            return;
    }

    i = strlen(set);
    set[i] = ch;
    set[i + 1] = '\0';
}
void findFirst(char symbol, int index)
{
    int i, j;
    char temp;

    if (!isupper(symbol))
    {
        add(first[index], symbol);
        return;
    }

    for (i = 0; i < n; i++)
    {
        if (production[i][0] == symbol)
        {
            if (production[i][2] == '#')
            {
                add(first[index], '#');
            }
            else
            {
                j = 2;

                while (production[i][j] != '\0')
                {
                    temp = production[i][j];

                    if (!isupper(temp))
                    {
                        add(first[index], temp);
                        break;
                    }
                    else
                    {
                        int k;
                        int pos;
                        int hasEpsilon = 0;

                        for (k = 0; k < n; k++)
                        {
                            if (production[k][0] == temp)
                            {
                                pos = 0;

                                while (first[k][pos] != '\0')
                                {
                                    if (first[k][pos] != '#')
                                        add(first[index],
                                            first[k][pos]);

                                    if (first[k][pos] == '#')
                                        hasEpsilon = 1;

                                    pos++;
                                }
                            }
                        }

                        if (!hasEpsilon)
                            break;

                        j++;

                        if (production[i][j] == '\0')
                            add(first[index], '#');
                    }
                }
            }
        }
    }
}

void findFollow(int index)
{
    int i, j, k;
    char lhs, symbol, next;

    if (index == 0)
        add(follow[index], '$');

    for (i = 0; i < n; i++)
    {
        lhs = production[i][0];

        for (j = 2; production[i][j] != '\0'; j++)
        {
            symbol = production[i][j];

            if (isupper(symbol))
            {
                next = production[i][j + 1];

                if (next == '\0')
                {
                    for (k = 0; k < n; k++)
                    {
                        if (production[k][0] == lhs)
                        {
                            int p;

                            for (p = 0; first[k][p] != '\0'; p++)
                            {
                     
                            }
                        }
                    }
                }
                else
                {
                    if (!isupper(next))
                    {
                        add(follow[index], next);
                    }
                }
            }
        }
    }
}

void main()
{
    int i, j;
    int changed;

    clrscr();

    printf("FIRST AND FOLLOW SETS\n");
    printf("---------------------\n");
    printf("\nEnter number of productions: ");
    scanf("%d", &n);
    printf("\nEnter productions using # for epsilon.\n");
    printf("Example: E=TR\n\n");
    for (i = 0; i < n; i++)
    {
        printf("Production %d: ", i + 1);
        scanf("%s", production[i]);
    }

    for (i = 0; i < 10; i++)
    {
        first[i][0] = '\0';
        follow[i][0] = '\0';
    }
    for (i = 0; i < n; i++)
    {
        findFirst(production[i][0], i);
    }
    printf("\nFIRST SETS\n");
    printf("----------\n");
    for (i = 0; i < n; i++)
    {
        int duplicate = 0;
        for (j = 0; j < i; j++)
        {
            if (production[i][0] == production[j][0])
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            printf("FIRST(%c) = { ",
                   production[i][0]);

            for (j = 0; first[i][j] != '\0'; j++)
                printf("%c ", first[i][j]);

            printf("}\n");
        }
    }

    for (i = 0; i < n; i++)
    {
        follow[i][0] = '\0';
    }
    add(follow[0], '$');

    for (changed = 0; changed < 10; changed++)
    {
        for (i = 0; i < n; i++)
        {
            char lhs = production[i][0];

            for (j = 2; production[i][j] != '\0'; j++)
            {
                char symbol = production[i][j];

                if (isupper(symbol))
                {
                    int target = -1;
                    int k;
                    for (k = 0; k < n; k++)
                    {
                        if (production[k][0] == symbol)
                        {
                            target = k;
                            break;
                        }
                    }

                    if (production[i][j + 1] != '\0')
                    {
                        char next = production[i][j + 1];

                        if (!isupper(next))
                        {
                            add(follow[target], next);
                        }
                        else
                        {
                            int f;

                            for (k = 0; k < n; k++)
                            {
                                if (production[k][0] == next)
                                {
                                    for (f = 0;
                                         first[k][f] != '\0';
                                         f++)
                                    {
                                        if (first[k][f] != '#')
                                            add(follow[target],
                                                first[k][f]);
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        int source = -1;
                        int f;

                        for (k = 0; k < n; k++)
                        {
                            if (production[k][0] == lhs)
                            {
                                source = k;
                                break;
                            }
                        }

                        if (source != -1 && source != target)
                        {
                            for (f = 0;
                                 follow[source][f] != '\0';
                                 f++)
                            {
                                add(follow[target],
                                    follow[source][f]);
                            }
                        }
                    }
                }
            }
        }
    }

    printf("\nFOLLOW SETS\n");
    printf("-----------\n");

    for (i = 0; i < n; i++)
    {
        int duplicate = 0;

        for (j = 0; j < i; j++)
        {
            if (production[i][0] == production[j][0])
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            printf("FOLLOW(%c) = { ",
                   production[i][0]);

            for (j = 0; follow[i][j] != '\0'; j++)
                printf("%c ", follow[i][j]);

            printf("}\n");
        }
    }

    getch();
}
