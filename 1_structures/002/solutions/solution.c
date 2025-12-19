/**
 * @file solution.c
 * @brief Solution to the "Card Game" problem.
 * @details This program simulates a card game between two players based on the rules provided.
 * It reads the initial decks of both players and the maximum number of moves, then determines the
 * outcome of the game.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2025-12-19
 * @version 0.1
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void Push(Queue* q, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (q->rear) {
        q->rear->next = newNode;
    } else {
        q->front = newNode;
    }
    q->rear = newNode;
    q->size++;
}

void Pop(Queue* q) {
    if (q->front) {
        Node* temp = q->front;
        q->front = q->front->next;
        if (!q->front) {
            q->rear = NULL;
        }
        free(temp);
        q->size--;
    }
}

int Top(Queue* q) {
    if (q->front) {
        return q->front->data;
    }
    return -1; // or some error value
}

int Size(Queue* q) {
    return q->size;
}


int main() {
    int n, K;
    scanf("%d %d", &n, &K);

    Queue* player1 = createQueue();
    Queue* player2 = createQueue();

    for (int i = 0; i < n; i++) {
        int card;
        scanf("%d", &card);
        Push(player1, card);
    }

    for (int i = 0; i < n; i++) {
        int card;
        scanf("%d", &card);
        Push(player2, card);
    }

    while(K-- && Size(player1) > 0 && Size(player2) > 0) {
        int card1 = Top(player1);
        int card2 = Top(player2);
        Pop(player1);
        Pop(player2);

        if ((card1 > card2 && !(card1 == n && card2 == 1)) || (card1 == 1 && card2 == n)) {
            Push(player1, card1);
            Push(player1, card2);
        } else if (card1 != card2) {
            Push(player2, card2);
            Push(player2, card1);
        }
    }

    if (Size(player1) > Size(player2)) {
        printf("1 %d\n", Size(player1) - Size(player2));
    } else if (Size(player2) > Size(player1)) {
        printf("2 %d\n", Size(player2) - Size(player1));
    } else {
        printf("0 0\n");
    }

    return 0;
}