#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to check if the stack is empty
bool isEmpty(char* stack, int top) {
    return (top == -1);
}

// Function to push an element onto the stack
void push(char* stack, int* top, char data) {
    stack[++(*top)] = data;
}

// Function to pop the top element from the stack
char pop(char* stack, int* top) {
    if (isEmpty(stack, *top)) {
        printf("Stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack[(*top)--];
}

// Function to check if the parentheses are balanced
bool areParenthesesBalanced(const char* exp) {
    char stack[100];
    int top = -1; // Initialize stack top

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(stack, &top, exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(stack, top)) {
                return false;
            } else {
                char ch = pop(stack, &top);
                if ((exp[i] == ')' && ch != '(') ||
                    (exp[i] == '}' && ch != '{') ||
                    (exp[i] == ']' && ch != '[')) {
                    return false;
                }
            }
        }
    }

    return isEmpty(stack, top); // True if stack is empty (all parentheses balanced)
}

int main() {
    const char* expression1 = "{()}[]";      // Balanced expression
    const char* expression2 = "{(])}";       // Unbalanced expression

    if (areParenthesesBalanced(expression1)) {
        printf("Expression 1 is balanced.\n");
    } else {
        printf("Expression 1 is not balanced.\n");
    }

    if (areParenthesesBalanced(expression2)) {
        printf("Expression 2 is balanced.\n");
    } else {
        printf("Expression 2 is not balanced.\n");
    }

    return 0;
}
