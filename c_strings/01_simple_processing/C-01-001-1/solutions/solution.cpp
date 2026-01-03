/**
 * @file solution.cpp
 * @author Mihail Croitor
 * @brief `Substring` task solution
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <string>

int main() {
    std::string S;
    std::getline(std::cin, S);
    int POS, N;
    std::cin >> POS >> N;
    if (N > (int)S.size() - POS) {
        N = S.size() - POS;
    }
    std::cout << S.substr(POS, N) << std::endl;
    return 0;
}