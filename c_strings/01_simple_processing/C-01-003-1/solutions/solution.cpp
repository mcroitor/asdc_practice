/**
 * @file solution.cpp
 * @author Mihail Croitor
 * @brief `left` task solution
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
    int N;
    std::cin >> N;
    if (N > (int)S.size()) {
        N = S.size();
    }
    std::cout << S.substr(0, N) << std::endl;
    return 0;
}