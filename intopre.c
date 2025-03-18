#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    char arr[MAX];
} Stack;

// Queue structure
typedef struct {
    int front, rear;
    char arr[MAX];
} Queue;

// Stack operations
void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

int isStackFull(Stack *s) {
    return s->top == MAX - 1;
}

void push(Stack *s, char c) {
    if (!isStackFull(s))
        s->arr[++(s->top)] = c;
}

char pop(Stack *s) {
    if (!isStackEmpty(s))
        return s->arr[(s->top)--];
    return -1;  // Return a sentinel value for error
}

// Queue operations
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}

int isQueueEmpty(Queue *q) {
    return q->front == -1;
}

int isQueueFull(Queue *q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue *q, char c) {
    if (!isQueueFull(q)) {
        if (q->front == -1) q->front = 0;
        q->arr[++(q->rear)] = c;
    }
}

char dequeue(Queue *q) {
    if (!isQueueEmpty(q)) {
        char c = q->arr[q->front++];
        if (q->front > q->rear) q->front = q->rear = -1;
        return c;
    }
    return -1;
}

// Utility functions
int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void reverse(char *expr) {
    int start = 0;
    int end = strlen(expr) - 1;
    while (start < end) {
        char temp = expr[start];
        expr[start] = expr[end];
        expr[end] = temp;
        start++;
        end--;
    }
}

// Infix to Prefix conversion function
void infixToPrefix(char *infix, char *prefix) {
    Stack s;
    Queue q;
    int len = strlen(infix);

    initStack(&s);
    initQueue(&q);

    reverse(infix);  // Reverse the infix expression

    for (int i = 0; i < len; i++) {
        char c = infix[i];

        // Operand (letter or number)
        if (isalnum(c)) {
            enqueue(&q, c);
        }
        // Left parenthesis
        else if (c == ')') {
            push(&s, c);
        }
        // Right parenthesis
        else if (c == '(') {
            while (!isStackEmpty(&s) && s.arr[s.top] != ')') {  // Directly check top of stack without peek
                enqueue(&q, pop(&s));
            }
            pop(&s);  // Pop ')'
        }
        // Operator
        else if (isOperator(c)) {
            while (!isStackEmpty(&s) && precedence(c) <= precedence(s.arr[s.top])) {  // Directly check top of stack without peek
                enqueue(&q, pop(&s));
            }
            push(&s, c);
        }
    }

    // Pop remaining operators in stack
    while (!isStackEmpty(&s)) {
        enqueue(&q, pop(&s));
    }

    // Reverse the result stored in queue to get the final prefix expression
    int index = 0;
    while (!isQueueEmpty(&q)) {
        prefix[index++] = dequeue(&q);
    }
    prefix[index] = '\0';  // Null-terminate the string

    reverse(prefix);  // Reverse the final result
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
