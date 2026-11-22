%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER

%left '+' '-'
%left '*' '/'

%%

expression:
      expression '+' expression
    | expression '-' expression
    | expression '*' expression
    | expression '/' expression
    | '(' expression ')'
    | NUMBER
    ;

%%

int main(void)
{
    printf("YACC ARITHMETIC EXPRESSION PARSER\n");
    printf("---------------------------------\n");
    printf("Enter an arithmetic expression:\n");

    if (yyparse() == 0)
        printf("\nResult: VALID EXPRESSION\n");
    else
        printf("\nResult: INVALID EXPRESSION\n");

    return 0;
}

void yyerror(const char *s)
{
    printf("\nError: Invalid arithmetic expression\n");
}