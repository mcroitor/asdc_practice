/**
 * @file solution.c
 * @author Mihail Croitor
 * @brief `ToLower` task solution
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
char to_lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + ('a' - 'A');
    }
    return c;
}

void ToLower(char* S) {
    for (int i = 0; S[i] != '\0'; i++) {
        S[i] = to_lower(S[i]);
    }
}

int main() {
    char S[1001];
    fgets(S, sizeof(S), stdin);
    
    // Remove newline character if present
    for (int i = 0; S[i] != '\0'; i++) {
        if (S[i] == '\n') {
            S[i] = '\0';
            break;
        }
    }

    ToLower(S);
    
    printf("%s\n", S);
    return 0;
}