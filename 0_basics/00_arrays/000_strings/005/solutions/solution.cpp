/**
 * @file solution.cpp
 * @author Mihail Croitor
 * @brief `ToLower` task solution
 * @version 0.1
 * @date 2025-12-19
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string S;
    std::getline(std::cin, S);
    for (char& c : S) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    std::cout << S << std::endl;
    return 0;
}