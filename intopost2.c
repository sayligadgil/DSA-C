#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

// Stack structure
typedef struct {
    char arr[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack *s) {
    s->top = -1;
}
int isempty(Stack *s) {
return s->top = -1;
}
// Function to push an element onto the stack
void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->arr[++(s->top)] = c;
    }
}

// Function to pop an element from the stack
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->arr[(s->top)--];
}

// Function to peek the top element of the stack
char peek(Stack *s) {
    if (s->top == -1) {
        return -1;
    }
    return s->arr[s->top];
}

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Function to check if a character is an operand
int isOperand(char c) {
    return (isalnum(c));  // Returns true if character is a number or letter
}

// Function to check precedence of operators
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/'|| c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(char* infix) {
    Stack s;
    initStack(&s);
    int i = 0, k = 0;
    char postfix[MAX];

    while (infix[i] != '\0') {
        char current = infix[i];

        if (isOperand(current)) {  // If the character is an operand (number/variable)
            postfix[k++] = current;
        } else if (current == '(') {  // If the character is an opening parenthesis
            push(&s, current);
        } else if (current == ')') {  // If the character is a closing parenthesis
            while (peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }
            pop(&s);  // Pop '(' from the stack
        } else if (isOperator(current)) {  // If the character is an operator
            while (s.top != -1 && precedence(peek(&s)) >= precedence(current)) {
                postfix[k++] = pop(&s);
            }
            push(&s, current);
        }
        i++;
    }

    // Pop any remaining operators in the stack
    while (s.top != -1) {
        postfix[k++] = pop(&s);
    }

    postfix[k] = '\0';  // Null-terminate the postfix expression
    printf("Postfix Expression: %s\n", postfix);
}

int main() {
    char infix[MAX];

    // Input the infix expression
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Convert to postfix
    infixToPostfix(infix);

    return 0;
}
