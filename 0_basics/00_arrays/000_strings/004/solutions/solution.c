/**
 * @file solution.c
 * @author Mihail Croitor
 * @brief Custom string length function (my_strlen) implementation
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>

int my_strlen(const char* S) {
    int length = 0;
    while (S[length] != '\0' && S[length] != '\n') {
        length++;
    }
    return length;
}

int main() {
    char S[1001];
    fgets(S, sizeof(S), stdin);

    int len = my_strlen(S);

    printf("%d\n", len);
    return 0;
}