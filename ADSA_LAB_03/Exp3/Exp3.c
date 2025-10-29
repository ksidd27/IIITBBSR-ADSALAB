#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// ---------- Stack Implementation ----------
struct Stack {
    int top;
    int arr[MAX];
};

void initStack(struct Stack* s) {
    s->top = -1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

void push(struct Stack* s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(struct Stack* s) {
    return s->arr[s->top];
}

// ---------- Infix to Postfix Conversion ----------
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    struct Stack s;
    initStack(&s);

    int i = 0, k = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') {
        if (isalnum(ch)) {
            postfix[k++] = ch; // operand directly to postfix
        }
        else if (ch == '(') {
            push(&s, ch);
        }
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[k++] = pop(&s);
            pop(&s); // remove '('
        }
        else if (isOperator(ch)) {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch))
                postfix[k++] = pop(&s);
            push(&s, ch);
        }
    }

    while (!isEmpty(&s))
        postfix[k++] = pop(&s);

    postfix[k] = '\0';
}

// ---------- Postfix Evaluation ----------
int evaluatePostfix(char postfix[]) {
    struct Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            push(&s, ch - '0'); // convert char to int
        }
        else if (isOperator(ch)) {
            int val2 = pop(&s);
            int val1 = pop(&s);

            switch (ch) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < val2; j++) res *= val1;
                    push(&s, res);
                    break;
                }
            }
        }
    }
    return pop(&s);
}

// ---------- Main Program ----------
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    // Evaluate only if expression is numeric
    int isNumeric = 1;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalpha(postfix[i])) {
            isNumeric = 0;
            break;
        }
    }

    if (isNumeric) {
        int result = evaluatePostfix(postfix);
        printf("Evaluated Result: %d\n", result);
    } else {
        printf("Evaluation skipped (expression contains variables).\n");
    }

    return 0;
}
