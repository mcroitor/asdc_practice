#include <stdio.h>
#include <stdbool.h>

bool isOpeningBracket(char ch) {
    return ch == '(' || ch == '{' || ch == '[';
}

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

typedef struct {
    char data[1000];
    int top;
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

bool isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

bool push(Stack* stack, char ch) {
    if (stack->top >= 999) return false; // Stack overflow
    stack->data[++(stack->top)] = ch;
    return true;
}

bool pop(Stack* stack, char* ch) {
    if (isStackEmpty(stack)) return false; // Stack underflow
    *ch = stack->data[(stack->top)--];
    return true;
}

bool isValidBrackets(const char* str) {
    Stack stack;
    initStack(&stack);
    
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        
        if (isOpeningBracket(ch)) {
            push(&stack, ch);
        } else {
            char topChar;
            if (!pop(&stack, &topChar) || !isMatchingPair(topChar, ch)) {
                return false;
            }
        }
    }
    
    return isStackEmpty(&stack);
}

int main() {
    char str[1001];
    if (fgets(str, sizeof(str), stdin) == NULL) {
        str[0] = '\0';
    }
    // Remove newline if present
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
    }
    
    if (isValidBrackets(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}