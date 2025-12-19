#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::stack<char> stk;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            stk.push(ch);
        } else {
            if (stk.empty()) {
                std::cout << "NO\n";
                return 0;
            }
            char top = stk.top();
            stk.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                std::cout << "NO\n";
                return 0;
            }
        }
    }

    if (stk.empty()) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}