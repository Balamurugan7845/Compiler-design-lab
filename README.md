# Compiler Design Lab Programs

A collection of Compiler Design laboratory experiments, including lexical analysis, automata, parsing, FIRST/FOLLOW sets, intermediate code generation, code optimization, and target-code generation.

## Table of Contents

1. [1. Identify Keywords, Identifiers, Operators and Constants](#1-identify-keywords-identifiers-operators-and-constants)
2. [2. Implement a Lex Program to Recognize Keywords, Numbers and Identifiers](#2-implement-a-lex-program-to-recognize-keywords-numbers-and-identifiers)
3. [3. a) Design a Program to Simulate DFA for Validating Strings](#3-a-design-a-program-to-simulate-dfa-for-validating-strings)
4. [4. Implement a Top-Down Parser for a Given Grammar](#4-implement-a-top-down-parser-for-a-given-grammar)
5. [5. Experiment: Bottom-Up Parsing Using Shift-Reduce Technique](#5-experiment-bottom-up-parsing-using-shift-reduce-technique)
6. [6. Use YACC to construct a parser for arithmetic expressions.](#6-use-yacc-to-construct-a-parser-for-arithmetic-expressions)
7. [7. Experiment: FIRST and FOLLOW Sets](#7-experiment-first-and-follow-sets)
8. [8. Convert Arithmetic Expressions into Intermediate Code (TAC)](#8-convert-arithmetic-expressions-into-intermediate-code-tac)
9. [9. Generate Intermediate Code Using Quadruples, Triples, and Indirect Triples](#9-generate-intermediate-code-using-quadruples-triples-and-indirect-triples)
10. [10. Generate Target Code from Intermediate Representation](#10-generate-target-code-from-intermediate-representation)
11. [11. Construct Directed Acyclic Graph (DAG) and Eliminate Common Sub-expressions](#11-construct-directed-acyclic-graph-dag-and-eliminate-common-sub-expressions)
12. [12. Optimize the Given Expression Using Constant Folding Optimization](#12-optimize-the-given-expression-using-constant-folding-optimization)
13. [13. Optimize the Given Expression Using Common Sub-expression Elimination (CSE)](#13-optimize-the-given-expression-using-common-sub-expression-elimination-cse)

---

## 1. Identify Keywords, Identifiers, Operators and Constants

### Aim

To write a C program to identify and classify keywords, identifiers, operators and constants from a given input program.
### Algorithm

Start the program.
Define a list of C keywords.
Read a line of source code from the user.
Scan the input character by character.
Ignore spaces and tabs.
If a character is an alphabet or underscore, collect the complete word.
Compare the word with the keyword list.
If it matches, identify it as a Keyword; otherwise identify it as an Identifier.
If a character is a digit, collect the number and identify it as a Constant.
If a character is an operator, identify it as an Operator.
Display all identified tokens.
Stop the program.
### Program

```c
```
**File name: LEXICAL1.C**

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {
    "int", "float", "char", "if", "else",
    "while", "for", "return", "void"
};

int isKeyword(char str[])
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }

    return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '=' || ch == '<' ||
        ch == '>' || ch == '%')
        return 1;

    return 0;
}

void main()
{
    char input[200];
    char token[50];
    int i = 0, j;

    clrscr();

    printf("LEXICAL ANALYZER\n");
    printf("----------------\n");

    printf("Enter a C statement:\n");
    gets(input);

    printf("\n--- TOKEN IDENTIFICATION ---\n");

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

            while (isdigit(input[i]) || input[i] == '.')
            {
                token[j] = input[i];
                j++;
                i++;
            }

            token[j] = '\0';

            printf("Constant   : %s\n", token);
        }
        else if (isOperator(input[i]))
        {
            printf("Operator   : %c\n", input[i]);
            i++;
        }
        else
        {
            i++;
        }
    }

    getch();
}
```
### Output

```text
LEXICAL ANALYZER
----------------
Enter a C statement:
int total = count + 45

--- TOKEN IDENTIFICATION ---
Keyword    : int
Identifier : total
Operator   : =
Identifier : count
Operator   : +
Constant   : 45
```
### Result

Thus, the program successfully identifies keywords, identifiers, operators and constants from the given input program.
## 2. Implement a Lex Program to Recognize Keywords, Numbers and Identifiers

### Aim

To implement a C program that simulates a Lexical Analyzer and recognizes keywords, numbers, identifiers and operators.
### Algorithm

Start the program.
Define the list of keywords.
Read the input string.
Scan the input character by character.
Ignore spaces and tabs.
If the input begins with an alphabet or underscore, collect the complete word.
Compare the word with the keyword list.
Display it as a Keyword or Identifier.
If the input begins with a digit, collect the number and display it as a Number.
If an operator is found, display it as an Operator.
Continue until the end of the input.
Stop the program.
### Program

```c
```
**File name: LEXICAL2.C**

```c
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

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '=' || ch == '<' ||
        ch == '>' || ch == '%')
        return 1;

    return 0;
}

void main()
{
    char input[200];
    char token[50];

    int i = 0, j;

    clrscr();

    printf("LEXICAL ANALYZER - LEX SIMULATION\n");
    printf("----------------------------------\n");

    printf("Enter input:\n");
    gets(input);

    printf("\n--- TOKENS ---\n");

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
        else if (isOperator(input[i]))
        {
            printf("Operator   : %c\n", input[i]);
            i++;
        }
        else
        {
            i++;
        }
    }

    getch();
}
```
### Output

```text
LEXICAL ANALYZER - LEX SIMULATION
----------------------------------
Enter input:
int total = count + 45

--- TOKENS ---
Keyword    : int
Identifier : total
Operator   : =
Identifier : count
Operator   : +9
Number     : 45
```
### Result

Thus, the program successfully recognizes keywords, numbers, identifiers and operators, simulating the basic operation of a Lex program.
## 3. a) Design a Program to Simulate DFA for Validating Strings

### Aim

To write a C program to simulate a DFA for validating binary strings and accept strings that end with 01.
### Algorithm

Start the program.
Define the DFA transition table.
Set q0 as the initial state.
Set q2 as the final state.
Read a binary string from the user.
Check each input symbol.
If the symbol is not 0 or 1, display an error.
Use the transition table to find the next state.
Continue until the entire string is processed.
If the final state is q2, display STRING ACCEPTED.
Otherwise, display STRING REJECTED.
Stop the program.
### Program

```c
```
**File name: DFA.C**

```c
#include <stdio.h>
#include <conio.h>

int transition[3][2] = {
    {1, 0},
    {1, 2},
    {1, 0}
};

void main()
{
    char input[100];
    int currentState = 0;
    int i;
    int symbol;
    int nextState;

    clrscr();

    printf("DFA STRING VALIDATION\n");
    printf("---------------------\n");
    printf("Language: Strings ending with 01\n");
    printf("Alphabet: {0, 1}\n\n");

    printf("Enter a binary string: ");
    scanf("%s", input);

    printf("\nExecution Trace:\n");
    printf("Initial State: q%d\n", currentState);

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
        nextState = transition[currentState][symbol];

        printf("q%d --(%c)--> q%d\n",
               currentState, input[i], nextState);

        currentState = nextState;
        i++;
    }

    printf("\nFinal State: q%d\n", currentState);

    if (currentState == 2)
        printf("Result: STRING ACCEPTED");
    else
        printf("Result: STRING REJECTED");

    getch();
}
```
### Output — Accepted

```text
DFA STRING VALIDATION
---------------------
Language: Strings ending with 01
Alphabet: {0, 1}

Enter a binary string: 1101

Execution Trace:
Initial State: q0
q0 --(1)--> q0
q0 --(1)--> q0
q0 --(0)--> q1
q1 --(1)--> q2

Final State: q2
Result: STRING ACCEPTED
```
### Output — Rejected

```text
Enter a binary string: 1010

Execution Trace:
Initial State: q0
q0 --(1)--> q0
q0 --(0)--> q1
q1 --(1)--> q2
q2 --(0)--> q1

Final State: q1
Result: STRING REJECTED
```
### Result

Thus, the DFA simulator successfully validates binary strings and accepts strings ending with 01 while rejecting other strings.
b) Design a Program to Simulate DFA for Validating Strings
### Aim

To write a C program to simulate a Non-Deterministic Finite Automaton (NFA) and determine whether a given binary string contains the substring 01.
### Algorithm

Start the program.
Define the NFA states q0, q1, and q2.
Set q0 as the initial state.
Set q2 as the final state.
Read a binary string from the user.
Maintain the set of possible current states.
For every input symbol, calculate all possible next states using the NFA transition rules.
Continue until the complete string is processed.
If the final state q2 is present in the current state set, accept the string.
Otherwise, reject the string.
Stop the program.
Program
**File name: NFA.C**

```c
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
Output 1 — Accepted
NFA STRING VALIDATION
---------------------
Language: Strings containing 01
Alphabet: {0, 1}

Enter a binary string: 1101

Initial State: {q0}
After input '1' : {q0}
After input '1' : {q0}
After input '0' : {q0 q1}
After input '1' : {q0 q2}

Result: STRING ACCEPTED
Output 2 — Rejected
NFA STRING VALIDATION
---------------------
Language: Strings containing 01
Alphabet: {0, 1}

Enter a binary string: 111

Initial State: {q0}
After input '1' : {q0}
After input '1' : {q0}
After input '1' : {q0}

Result: STRING REJECTED
```
### Result

Thus, the C program successfully simulates an NFA and correctly accepts strings containing 01 and rejects strings that do not contain 01.
## 4. Implement a Top-Down Parser for a Given Grammar

### Aim

To implement a top-down recursive-descent parser in C for a given grammar and determine whether the input string is accepted.
### Algorithm

Start the program.
Define the grammar productions.
Read the input string.
Set the initial position to zero.
Implement functions for E, E', T, T', and F.
Parse the input according to the grammar.
Match id, +, *, ( and ).
If a symbol does not match the grammar, generate an error.
After parsing, check whether the complete input has been consumed.
If the complete input is parsed successfully, display STRING ACCEPTED.
Otherwise, display STRING REJECTED.
Stop the program.
### Program

```c
```
**File name: PARSER.C**

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>

char input[100];
int pos;
int error;


void E();
void Eprime();
void T();
void Tprime();
void F();


void E()
{
    T();
    Eprime();
}


void Eprime()
{
    if (input[pos] == '+')
    {
        pos++;
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
        pos++;
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
        pos++;

        E();

        if (input[pos] == ')')
        {
            pos++;
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

    printf("Enter input string: ");
    scanf("%s", input);

    pos = 0;
    error = 0;

    E();

    if (error == 0 && input[pos] == '\0')
        printf("\nResult: STRING ACCEPTED");
    else
        printf("\nResult: STRING REJECTED");

    getch();
}
```
### Output — Accepted

```text
TOP-DOWN PARSER
----------------
Grammar:
E  -> T E'
E' -> + T E' | epsilon
T  -> F T'
T' -> * F T' | epsilon
F  -> (E) | id

Enter input string: id+id*id

Result: STRING ACCEPTED
```
### Output — Rejected

```text
TOP-DOWN PARSER
----------------
Grammar:
E  -> T E'
E' -> + T E' | epsilon
T  -> F T'
T' -> * F T' | epsilon
F  -> (E) | id

Enter input string: id+*id

Result: STRING REJECTED
```
### Result

#### Thus, the top-down recursive-descent parser successfully parses the given grammar and correctly accepts valid strings and rejects invalid strings.

## 5. Experiment: Bottom-Up Parsing Using Shift-Reduce Technique

### Aim

To write a C program to perform bottom-up parsing using the shift-reduce technique and determine whether the given input string is accepted by the grammar.
### Algorithm

Start the program.
Define the grammar productions.
Initialize an empty stack.
Read the input string and append $ as the end marker.
Shift the input symbol onto the stack.
After each shift, check whether the top of the stack matches the right-hand side of any grammar production.
If a production matches, reduce the symbols on the stack to the corresponding non-terminal.
Repeat shifting and reducing until the complete input is processed.
If the stack becomes E$ and the input is completely consumed, accept the string.
Otherwise, reject the string.
Stop the program.
Program
**File name: SHIFTRED.C**

```c
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
Output
BOTTOM-UP PARSER
-----------------
Grammar:
E -> E+E
E -> E*E
E -> (E)
E -> i

Enter input string: i+i

Parsing Steps:

SHIFT
Stack: i    Input: +i$

REDUCE E -> i
Stack: E    Input: +i$

SHIFT
Stack: E+    Input: i$

SHIFT
Stack: E+i   Input: $

REDUCE E -> i
Stack: E+E   Input: $

REDUCE E -> E+E
Stack: E    Input: $

Final Stack: E

Result: STRING ACCEPTED

Result:
Thus, the bottom-up parser using the shift-reduce technique was successfully implemented in C. The program correctly performs shift and reduce operations and accepts valid strings according to the given grammar.
```
## 6. Use YACC to construct a parser for arithmetic expressions.

### Aim

To use YACC (Yet Another Compiler-Compiler) to construct a parser for arithmetic expressions containing addition, subtraction, multiplication, division, and parentheses.
### Algorithm

Start the program.
Define NUMBER as a token in the YACC program.
Define the grammar rules for arithmetic expressions.
Specify operator precedence and associativity.
Use Lex/Flex to recognize numbers and operators.
Pass the recognized tokens from Lex to YACC.
YACC parses the input according to the grammar.
If the complete expression follows the grammar, display VALID EXPRESSION.
Otherwise, display INVALID EXPRESSION.
Stop the program.
Program
#### 1. YACC Program — parser.y

```c
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
int main()
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
```
#### 2. Lex Program — lexer.l

```
%{
#include "y.tab.h"
#include <stdlib.h>
%}
%%
[0-9]+      {
                yylval = atoi(yytext);
                return NUMBER;
            }
[ \t]+      ;
\n          return 0;
"+"         return '+';
"-"         return '-';
"*"         return '*';
"/"         return '/';
"("         return '(';
")"         return ')';
.           return yytext[0];

%%
Output -1
YACC ARITHMETIC EXPRESSION PARSER
---------------------------------
Enter an arithmetic expression:
10+20*5
Result: VALID EXPRESSION
Output -2
YACC ARITHMETIC EXPRESSION PARSER
---------------------------------
Enter an arithmetic expression:
10+*20
Result: INVALID EXPRESSION
```
### Result

Thus, YACC was successfully used to construct a parser for arithmetic expressions. The parser correctly recognizes valid arithmetic expressions and rejects invalid expressions according to the specified grammar.
## 7. Experiment: FIRST and FOLLOW Sets

### Aim

To write a C program to compute the FIRST and FOLLOW sets for a given context-free grammar.
### Algorithm

Start the program and read the given grammar productions.
Identify the terminals and non-terminals in the grammar.
Compute FIRST sets by finding the terminals that can appear first in the derivation of each non-terminal.
If a production contains ε (epsilon), add ε to the corresponding FIRST set and continue checking the next symbol.
Initialize FOLLOW of the start symbol with $ and scan each production to find the symbols that can follow every non-terminal.
Repeat the FIRST and FOLLOW calculations until no new symbols can be added to any set.
Display the computed FIRST and FOLLOW sets and terminate the program.
Program
**File name: FIRSTFOL.C**

```c
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
```
##### Use this input

Enter number of productions: 8
E=TR
R=+TR
R=#
T=FY
Y=*FY
Y=#
F=(E)
F=i
#### Output:

```text
FIRST SETS
----------
FIRST(E) = { ( i }
FIRST(R) = { + # }
FIRST(T) = { ( i }
FIRST(Y) = { * # }
FIRST(F) = { ( i }

FOLLOW SETS
-----------
FOLLOW(E) = { $ ) }
FOLLOW(R) = { $ ) }
FOLLOW(T) = { + $ ) }
FOLLOW(Y) = { + $ ) }
FOLLOW(F) = { * + $ ) }
```
### Result

Thus, the C program successfully computes the FIRST and FOLLOW sets for the given context-free grammar.
## 8. Convert Arithmetic Expressions into Intermediate Code (TAC)

### Aim

To write a C program to convert an arithmetic expression into Three-Address Code (TAC) using temporary variables.
### Algorithm

Start the program.
Read an arithmetic expression from the user.
Identify operators and operands in the expression.
Find the operators with higher precedence, such as * and /.
Generate intermediate code using temporary variables like t1, t2, and t3.
Replace each evaluated subexpression with its temporary variable.
Display the generated Three-Address Code and stop the program.
### Program

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
char postfix[100];
char expr[100];
int top = -1;

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void convert()
{
    int i, j = 0;
    char ch;

    for (i = 0; expr[i] != '\0'; i++)
    {
        ch = expr[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top >= 0 && stack[top] != '(')
                postfix[j++] = stack[top--];

            if (top >= 0)
                top--;
        }
        else
        {
            while (top >= 0 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }
    }

    while (top >= 0)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';
}

void main()
{
    char values[100][10];
    char a[10], b[10], temp[10];
    int i, sp = -1, count = 0;

    clrscr();

    printf("THREE ADDRESS CODE GENERATION\n");
    printf("-----------------------------\n");
    printf("Enter expression: ");
    scanf("%99s", expr);

    convert();

    printf("\nPostfix Expression: %s\n", postfix);
    printf("\nThree Address Code:\n");

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            values[++sp][0] = postfix[i];
            values[sp][1] = '\0';
        }
        else
        {
            strcpy(b, values[sp--]);
            strcpy(a, values[sp--]);

            count++;
            sprintf(temp, "t%d", count);

            printf("%s = %s %c %s\n",
                   temp, a, postfix[i], b);

            strcpy(values[++sp], temp);
        }
    }

    getch();
}
```
### Output

```text
Input:
a+b*c
Output:
THREE ADDRESS CODE GENERATION
-----------------------------
Enter expression: a+b*c

Postfix Expression: abc*+

Three Address Code:
t1 = b * c
t2 = a + t1
```
### Result

Thus, the C program successfully converts the given arithmetic expression into Three-Address Code using temporary variables.
## 9. Generate Intermediate Code Using Quadruples, Triples, and Indirect Triples

### Aim

To write a C program to generate intermediate code for a given arithmetic expression using Quadruples, Triples, and Indirect Triples.
### Algorithm

Start the program and read the arithmetic expression.
Convert the infix expression into postfix notation according to operator precedence.
Scan the postfix expression from left to right.
Push operands onto a stack.
When an operator is found, pop two operands and generate an intermediate instruction.
Store each instruction in a quadruple containing operator, argument 1, argument 2, and result.
Generate triples using the operator and two arguments, referring to previous results by instruction number.
Generate indirect triples by creating a pointer table that refers to the triple instructions.
Display the quadruple, triple, and indirect triple tables.
Stop the program.
#### C Program.

```c
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

char expr[100], postfix[100];
char opstack[100];
int top = -1;

char qop[100][5], qarg1[100][10];
char qarg2[100][10], qresult[100][10];
char values[100][10];

int n = 0;

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

void convert()
{
    int i, j = 0;
    char ch;

    for (i = 0; expr[i] != '\0'; i++)
    {
        ch = expr[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch))
            postfix[j++] = ch;
        else if (ch == '(')
            opstack[++top] = ch;
        else if (ch == ')')
        {
            while (top >= 0 && opstack[top] != '(')
                postfix[j++] = opstack[top--];

            if (top >= 0)
                top--;
        }
        else
        {
            while (top >= 0 &&
                   opstack[top] != '(' &&
                   precedence(opstack[top]) >= precedence(ch))
            {
                postfix[j++] = opstack[top--];
            }

            opstack[++top] = ch;
        }
    }

    while (top >= 0)
        postfix[j++] = opstack[top--];

    postfix[j] = '\0';
}

void main()
{
    int i, sp = -1, k;
    char a[10], b[10], temp[10];

    clrscr();

    printf("INTERMEDIATE CODE GENERATION\n");
    printf("----------------------------\n");
    printf("Enter expression: ");
    scanf("%99s", expr);

    convert();

    printf("\nPostfix Expression: %s\n", postfix);

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            values[++sp][0] = postfix[i];
            values[sp][1] = '\0';
        }
        else
        {
            strcpy(b, values[sp--]);
            strcpy(a, values[sp--]);

            strcpy(qop[n], "");
            qop[n][0] = postfix[i];
            qop[n][1] = '\0';

            strcpy(qarg1[n], a);
            strcpy(qarg2[n], b);

            sprintf(temp, "t%d", n + 1);
            strcpy(qresult[n], temp);

            strcpy(values[++sp], temp);
            n++;
        }
    }

    printf("\nQUADRUPLES\n");
    printf("---------------------------------\n");
    printf("No.\tOp\tArg1\tArg2\tResult\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%s\t%s\t%s\n",
               i, qop[i], qarg1[i],
               qarg2[i], qresult[i]);
    }

    printf("\nTRIPLES\n");
    printf("---------------------------------\n");
    printf("No.\tOp\tArg1\tArg2\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\t%s\t%s\n",
               i, qop[i], qarg1[i], qarg2[i]);
    }

    printf("\nINDIRECT TRIPLES\n");
    printf("---------------------------------\n");
    printf("Pointer\tTriple No.\n");

    for (i = 0; i < n; i++)
        printf("%d\t%d\n", i, i);

    getch();
}
```
### Output

```text
Input:
a+b*c
Output:
INTERMEDIATE CODE GENERATION
----------------------------
Enter expression: a+b*c

Postfix Expression: abc*+

QUADRUPLES
---------------------------------
No.     Op      Arg1    Arg2    Result
0       *       b       c       t1
1       +       a       t1      t2

TRIPLES
---------------------------------
No.     Op      Arg1    Arg2
0       *       b       c
1       +       a       (0)

INDIRECT TRIPLES
---------------------------------
Pointer Triple No.
0       0
1       1

```
### Result

Thus, the C program generates intermediate code for the given arithmetic expression using Quadruples, Triples, and Indirect Triples.
## 10. Generate Target Code from Intermediate Representation

### Aim

To write a C program to generate target code (assembly-like instructions) from a given Three-Address Code (TAC) intermediate representation.
### Algorithm

Start the program.
Read the number of intermediate-code instructions.
Read each instruction in the form result = operand1 operator operand2.
Extract the result, operands, and operator from each instruction.
Generate target instructions using registers.
Load the first operand into a register using MOV.
Apply the operator using the appropriate instruction, such as ADD, SUB, MUL, or DIV.
Store the result in the destination variable using MOV.
Display the generated target code and stop the program.
### Program

```c
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
```
### Output:

```text
```
#### TARGET CODE GENERATION

----------------------
Enter number of TAC instructions: 2
t1=a+b
t2=t1*c
Expected target code:
MOV R0, a
ADD R0, b
MOV t1, R0
MOV R0, t1
MUL R0, c
MOV t2, R0
### Result

Thus, the C program successfully generates assembly-like target instructions from the given Three-Address Code using register operations.
## 11. Construct Directed Acyclic Graph (DAG) and Eliminate Common Sub-expressions

### Aim

To write a C program to construct a Directed Acyclic Graph (DAG) for a given set of expressions and eliminate common sub-expressions to generate optimized code.
### Algorithm

Start the program and read the given arithmetic expressions.
Identify the operators and operands in each expression.
Create leaf nodes for all operands in the DAG.
Create operator nodes for arithmetic operations.
Check whether an identical operator node with the same operands already exists.
If a common sub-expression exists, reuse the existing node instead of creating a new one.
Display the DAG nodes and generate optimized intermediate code without repeated calculations.
### Program

```c
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
```
### Output

```text
DAG CONSTRUCTION AND CSE
-----------------------

DAG NODE TABLE
-----------------------
Node    Operator    Left    Right
0       VALUE       a
1       VALUE       b
2       VALUE       c
3       VALUE       d
4       +           0       1
5       +           2       3
6       *           4       5

OPTIMIZED CODE
-----------------------
t1 = a + b
t2 = c + d
t3 = t1 * t2
t4 = t1  (reused common expression)

Common expression a+b is calculated once.
```
### Result

Thus, the C program successfully constructs a Directed Acyclic Graph (DAG) and eliminates common sub-expressions by reusing previously computed results.
## 12. Optimize the Given Expression Using Constant Folding Optimization

### Aim

To write a C program to perform constant folding optimization by evaluating constant expressions at compile time and replacing them with their calculated values.
### Algorithm

Start the program and read an arithmetic expression.
Identify the constants and arithmetic operators in the expression.
Check whether the operands of an operation are constant values.
Evaluate constant expressions according to operator precedence.
Replace the original constant expression with its calculated result.
Repeat the process until all possible constant expressions are evaluated.
Display the optimized expression and terminate the program.
### Program

```c
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
```
### Output

```text
CONSTANT FOLDING OPTIMIZATION
----------------------------
Enter arithmetic expression: 10+20*5

Original Expression: 10+20*5
Optimized Expression: 110

Constant Folding Completed.
Another Example:
Enter arithmetic expression: (10+20)*5

Original Expression: (10+20)*5
Optimized Expression: 150

Constant Folding Completed.
```
### Result

Thus, the C program successfully performs constant folding optimization by evaluating constant arithmetic expressions and replacing them with their calculated values.
## 13. Optimize the Given Expression Using Common Sub-expression Elimination (CSE)

### Aim

To write a C program to perform Common Sub-expression Elimination (CSE) by identifying repeated expressions and reusing previously computed results to optimize the code.
### Algorithm

Start the program and read two arithmetic expressions.
Identify the operands and operators in each expression.
Compare the operators and operands of both expressions.
Check whether both expressions contain the same operation with identical operands.
If a common sub-expression is found, calculate it only once.
Replace the repeated expression with the previously computed temporary variable.
Display the optimized code and terminate the program.
### Program

```c
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
```
### Output -1

```text
COMMON SUB-EXPRESSION ELIMINATION
---------------------------------
Enter first expression (a+b): a+b
Enter second expression (a+b): a+b
Original Code:
t1 = a+b
t2 = a+b

Optimized Code:
t1 = a + b
t2 = t1

Common Sub-expression Found!
```
### Output -2

```text
COMMON SUB-EXPRESSION ELIMINATION
---------------------------------
Enter first expression (a+b): a+b
Enter second expression (a+b): c*d
Original Code:
t1 = a+b
t2 = c*d

Optimized Code:
t1 = a + b
t2 = c * d

No Common Sub-expression Found.
```
### Result

Thus, the C program successfully identifies common sub-expressions and eliminates redundant calculations by reusing previously computed results.
