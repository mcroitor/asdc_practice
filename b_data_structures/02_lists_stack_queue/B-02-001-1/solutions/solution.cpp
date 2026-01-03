/**
 * @file solution.cpp
 * @brief Solution to the "Card Game" problem.
 * @details This program simulates a card game between two players based on the rules provided.
 * It reads the initial decks of both players and the maximum number of moves, then determines the
 * outcome of the game.
 * @author Mihail Croitor <mcroitor@gmail.com>
 * @date 2025-12-19
 * @version 0.1
 */

#include <iostream>
#include <deque>
#include <algorithm>
#include <iterator>

int main() {
    int n, K;
    std::cin >> n >> K;

    std::deque<int> player1, player2;

    std::copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(player1));

    std::copy_n(std::istream_iterator<int>(std::cin), n, std::back_inserter(player2));

    while(K-- && !player1.empty() && !player2.empty()) {
        int card1 = player1.front();
        int card2 = player2.front();
        player1.pop_front();
        player2.pop_front();

        if ((card1 > card2 && !(card1 == n && card2 == 1)) || (card1 == 1 && card2 == n)) {
            player1.push_back(card2);
            player1.push_back(card1);
        } else if (card1 != card2) {
            player2.push_back(card1);
            player2.push_back(card2);
        }
    }

    if (player1.size() > player2.size()) {
        std::cout << "1 " << player1.size() - player2.size() << "\n";
    } else if (player2.size() > player1.size()) {
        std::cout << "2 " << player2.size() - player1.size() << "\n";
    } else {
        std::cout << "0 0\n";
    }

    return 0;
}