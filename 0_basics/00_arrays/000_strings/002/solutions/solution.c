/**
 * @file solution.c
 * @author Mihail Croitor
 * @brief `right` task solution
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <string.h>

int main() {
    char S[1001];
    fgets(S, sizeof(S), stdin);
    size_t len = strlen(S);
    if (len > 0 && S[len - 1] == '\n') {
        S[--len] = '\0';
    }
    int N;
    scanf("%d", &N);
    int POS = (int)len - N;
    if (POS < 0) {
        POS = 0;
    }
    
    for (int i = POS; i < POS + N && S[i] != '\0'; i++) {
        putchar(S[i]);
    }
    putchar('\n');
    return 0;
}