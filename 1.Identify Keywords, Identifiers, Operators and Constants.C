#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

const char *keywords[] = {
"int", "float", "char", "if", "else",
"while", "for", "return", "void", "main"
};
int num_keywords = 10;
		 int i;
int isKeyword(char *str) {
    for (i = 0; i < num_keywords; i++) {
	if (strcmp(keywords[i], str) == 0) {
	    return 1;
	}
    }
    return 0;
}


int isOperator(char ch) {
    char operators[] = "+-*/=><!%";
    for ( i = 0; i < strlen(operators); i++) {
	if (ch == operators[i]) {
	    return 1;
	}
    }
    return 0;
}

int main() {
    char input[200];
    char buffer[50];
    int i = 0, j = 0;
    clrscr();
    printf("Enter an expression or line of code: ");
    fgets(input, sizeof(input), stdin);

    printf("\n--- Token Identification ---\n");

    while (input[i] != '\0' && input[i] != '\n') {

	if (isspace(input[i])) {
	    i++;
	    continue;
	}


	if (isOperator(input[i])) {
	    printf("Operator   : %c\n", input[i]);
	    i++;
	}

	else if (isdigit(input[i])) {
	    j = 0;
	    while (isdigit(input[i]) || input[i] == '.') {
		buffer[j++] = input[i++];
	    }
	    buffer[j] = '\0';
	    printf("Constant   : %s\n", buffer);
	}

	else if (isalpha(input[i]) || input[i] == '_') {
	    j = 0;
	    while (isalnum(input[i]) || input[i] == '_') {
		buffer[j++] = input[i++];
	    }
	    buffer[j] = '\0';

	    if (isKeyword(buffer)) {
		printf("Keyword    : %s\n", buffer);
	    } else {
		printf("Identifier : %s\n", buffer);
	    }
	}
	else {

	    i++;
	}

    }
    getch();
    return 0;
}