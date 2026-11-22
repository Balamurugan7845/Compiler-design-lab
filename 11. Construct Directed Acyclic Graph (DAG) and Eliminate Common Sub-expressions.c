#include <stdio.h>
#include <conio.h>
#include <string.h>

struct node
{
    char op;
    char value[10];
    int left, right;
};

struct node dag[50];
int count = 0;

int leaf(char name[])
{
    int i;

    for(i = 0; i < count; i++)
    {
        if(dag[i].op == 'v' &&
           strcmp(dag[i].value, name) == 0)
            return i;
    }

    strcpy(dag[count].value, name);
    dag[count].op = 'v';
    dag[count].left = -1;
    dag[count].right = -1;

    return count++;
}

int operation(char op, int l, int r)
{
    int i;

    for(i = 0; i < count; i++)
    {
        if(dag[i].op == op &&
           dag[i].left == l &&
           dag[i].right == r)
            return i;
    }

    dag[count].op = op;
    dag[count].left = l;
    dag[count].right = r;

    sprintf(dag[count].value, "t%d", count + 1);

    return count++;
}

void main()
{
    int a, b, c, d;
    int n1, n2, n3, n4;

    clrscr();

    printf("DAG CONSTRUCTION AND CSE\n");
    printf("-----------------------\n");

    a = leaf("a");
    b = leaf("b");
    c = leaf("c");
    d = leaf("d");

    n1 = operation('+', a, b);
    n2 = operation('+', c, d);

    /* Common sub-expression */
    n3 = operation('+', a, b);

    n4 = operation('*', n1, n2);

    printf("\nDAG NODE TABLE\n");
    printf("-----------------------\n");
    printf("Node\tOperator\tLeft\tRight\n");

    for(a = 0; a < count; a++)
    {
        printf("%d\t", a);

        if(dag[a].op == 'v')
            printf("VALUE\t\t%s\n", dag[a].value);
        else
            printf("%c\t\t%d\t%d\n",
                   dag[a].op,
                   dag[a].left,
                   dag[a].right);
    }

    printf("\nOPTIMIZED CODE\n");
    printf("-----------------------\n");

    printf("t1 = a + b\n");
    printf("t2 = c + d\n");
    printf("t3 = t1 * t2\n");
    printf("t4 = t1  (reused common expression)\n");

    printf("\nCommon expression a+b is calculated once.");

    getch();
}