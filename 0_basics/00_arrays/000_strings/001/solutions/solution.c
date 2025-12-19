/**
 * @file solution.c
 * @author Mihail Croitor
 * @brief `Substring` task solution
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>

int main() {
    char S[1001];
    fgets(S, sizeof(S), stdin);
    int POS, N;
    scanf("%d %d", &POS, &N);
    for (int i = POS; i < POS + N && S[i] != '\0'; i++) {
        putchar(S[i]);
    }
    putchar('\n');
    return 0;
}