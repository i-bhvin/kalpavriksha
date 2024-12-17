#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100


typedef struct {
    int data[MAX];
    int top;
} IntStack;


typedef struct {
    char data[MAX];
    int top;
} OpStack;


void initIntStack(IntStack* stack) {
    stack->top = -1;
}


void pushInt(IntStack* stack, int value) {
    if (stack->top >= MAX - 1) {
        printf("Error: Stack overflow.\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}


int popInt(IntStack* stack) {
    if (stack->top < 0) {
        printf("Error: Invalid Expression.\n");
        exit(1);
    }
    return stack->data[stack->top--];
}


int peekInt(IntStack* stack) {
    if (stack->top < 0) {
        printf("Error: Stack is empty.\n");
        exit(1);
    }
    return stack->data[stack->top];
}


void initOpStack(OpStack* stack) {
    stack->top = -1;
}


void pushChar(OpStack* stack, char value) {
    if (stack->top >= MAX - 1) {
        printf("Error: Stack overflow.\n");
        exit(1);
    }
    stack->data[++stack->top] = value;
}


char popChar(OpStack* stack) {
    if (stack->top < 0) {
        printf("Error: Invalid Expression.\n");
        exit(1);
    }
    return stack->data[stack->top--];
}


char peekChar(OpStack* stack) {
    if (stack->top < 0) {
        printf("Error: Invalid Expression.\n");
        exit(1);
    }
    return stack->data[stack->top];
}


bool isDigit(char c) {
    return c >= '0' && c <= '9';
}


bool isSpace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}


int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) {
                printf("Error: Division by zero.\n");
                exit(1);
            }
            return a / b;
        default:
            printf("Error: Invalid Expression.\n");
            exit(1);
    }
}

int stringLength(const char* str){
    int i=0;
    while(str[i] != '\0') i++;
    return i;
}


int evaluateExpression(const char* expression) {
    IntStack values;
    OpStack operators;
    initIntStack(&values);
    initOpStack(&operators);

    for (int i = 0; i < stringLength(expression); i++) {
        char c = expression[i];

        
        if (isSpace(c)) continue;

        
        if (isDigit(c)) {
            int num = 0;
            while (i < strlen(expression) && isDigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            i--; 
            pushInt(&values, num);
        }
        
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (operators.top >= 0 && precedence(peekChar(&operators)) >= precedence(c)) {
                int b = popInt(&values);
                int a = popInt(&values);
                char op = popChar(&operators);
                pushInt(&values, applyOperation(a, b, op));
            }
            pushChar(&operators, c);
        }

        else {
            printf("Error: Invalid expression.\n");
            exit(1);
        }
    }

    while (operators.top >= 0) {
        int b = popInt(&values);
        int a = popInt(&values);
        char op = popChar(&operators);
        pushInt(&values, applyOperation(a, b, op));
    }

    return popInt(&values);
}

int main() {
    char expression[MAX];

    printf("Enter a mathematical expression: ");
    if (fgets(expression, MAX, stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    expression[strcspn(expression, "\n")] = '\0';

    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}
