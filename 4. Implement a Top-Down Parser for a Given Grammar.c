#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int pos = 0;
int error = 0;


void E();
void Eprime();
void T();
void Tprime();
void F();


void match(char ch)
{
    if (input[pos] == ch)
    {
        pos++;
    }
    else
    {
        error = 1;
    }
}


void E()
{
    T();
    Eprime();
}


void Eprime()
{
    if (input[pos] == '+')
    {
        match('+');
        T();
        Eprime();
    }
}


void T()
{
    F();
    Tprime();
}


void Tprime()
{
    if (input[pos] == '*')
    {
        match('*');
        F();
        Tprime();
    }
}


void F()
{
    if (input[pos] == 'i' &&
        input[pos + 1] == 'd')
    {
        pos = pos + 2;
    }
    else if (input[pos] == '(')
    {
        match('(');
        E();

        if (input[pos] == ')')
        {
            match(')');
        }
        else
        {
            error = 1;
        }
    }
    else
    {
        error = 1;
    }
}

void main()
{
    clrscr();

    printf("TOP-DOWN PARSER\n");
    printf("----------------\n");

    printf("Grammar:\n");
    printf("E  -> T E'\n");
    printf("E' -> + T E' | epsilon\n");
    printf("T  -> F T'\n");
    printf("T' -> * F T' | epsilon\n");
    printf("F  -> (E) | id\n\n");

    printf("Enter the input string: ");
    scanf("%s", input);

    pos = 0;
    error = 0;

    E();

    if (error == 0 && input[pos] == '\0')
    {
        printf("\nResult: STRING ACCEPTED");
    }
    else
    {
        printf("\nResult: STRING REJECTED");
    }

    getch();
}