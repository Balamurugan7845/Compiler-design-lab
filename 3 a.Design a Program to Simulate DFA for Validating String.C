#include <stdio.h>
#include <string.h>
#include <conio.h>

int transition[3][2] = {
    {1, 0},
    {1, 2},
    {1, 0}
};

isAcceptState(int state) {
    return state == 2;
}

int main() {
    char input[100];
    int currentState = 0, i, nextState, inputIdx;
    clrscr();
    printf("--- DFA String Validation Simulator ---\n");
    printf("Language Rule: Accepts strings ending with '01'\n");
    printf("Enter a binary string: ");
    scanf("%s", input);

    printf("\nExecution Trace:\n");
    printf("Initial State: q%d\n", currentState);

    for (i = 0; input[i] != '\0'; i++) {
	char ch = input[i];


	if (ch != '0' && ch != '1') {
	    printf("\nError: Invalid input symbol '%c'\n", ch);
	    return 1;
	}

	 inputIdx = ch - '0';
	 nextState = transition[currentState][inputIdx];

	printf("  q%d --('%c')--> q%d\n", currentState, ch, nextState);
	currentSta	te = nextState;
    }

    printf("Final State  : q%d\n", currentState);


    if (isAcceptState(currentState)) {
	printf("\nResult: STRING ACCEPTED\n");
    } else {
	printf("\nResult: STRING REJECTED\n");
    }
    getch();

    return 0;
}