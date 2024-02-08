#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define maxsize 30
struct Stud {
    char name[maxsize];
    int top;
};
typedef struct Stud S;
int overflow(S S1) {
    return S1.top == maxsize - 1;
}
void push(S *S1, char ele) {
    if(overflow(*S1)) {
        printf("Stack is full\n");
    } else {
        S1->name[++S1->top] = ele;
    }
}
int underflow(S S1) {
    return S1.top == -1;
}
char pop(S *S1) {
    if (underflow(*S1))
        return '\0';
    return S1->name[S1->top--];
}
int G(char symb) { //Input Precedence
    switch (symb) {
        case '+':   case '-':
            return 1;
        case '*':   case '/':
            return 3;
        case '$':   case '^':
            return 6;
        case '(':
            return 9;
        case ')':
            return 0;
        default:
            return -1; // Default case for alphanumeric characters
    }
}
int F(char symb) { //Stack Precedence
    switch (symb) {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '$':
        case '^':
            return 5;
        case '(':
            return 0;
        case '#':
            return -1;
        default:
            return -1; // Default case for alphanumeric characters
    }
}
void if_pf(char infix[], char postfix[]) {
    char symb;
    S S1;
    S1.top = -1;
    push(&S1, '#');
    int j = 0;
    for (int i = 0; i < strlen(infix); i++) {
        symb = infix[i];
        if (isalnum(symb)) {
            postfix[j] = symb;
            j++;
        } else {
            if (symb == '(') {
                push(&S1, symb);
            } else if (symb == ')') {
                while (S1.name[S1.top] != '(') {
                    char ele = pop(&S1);
                    postfix[j] = ele;
                    j++;
                }
                // Pop '(' from the stack
                pop(&S1);
            } else {
                while (G(symb) <= F(S1.name[S1.top])) {
                    char ele = pop(&S1);
                    postfix[j] = ele;
                    j++;
                }
                push(&S1, symb);
            }
        }
    }
    while (S1.top != -1 && S1.name[S1.top] != '#') {
        char ele = pop(&S1);
        postfix[j] = ele;
        j++;
    }
    postfix[j] = '\0';
}
int main() {
    char infix[30];
    char postfix[30];
    printf("Enter the infix expression: ");
    gets(infix);
    if_pf(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
