#include <iostream>
#include <stack>
#include <string>
#include <map>

bool isValid(std::string s) {
    std::stack<char> st;
    // Словарь соответствия закрывающей скобки открывающей
    std::map<char, char> brackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        // Если это закрывающая скобка
        if (brackets.count(c)) {
            // Проверяем: стек не пуст и на вершине подходящая открывающая
            if (!st.empty() && st.top() == brackets[c]) {
                st.pop(); // Убираем пару
            } else {
                return false; // Ошибка: нет пары или не тот тип
            }
        } else {
            // Если открывающая — кладем в стек
            st.push(c);
        }
    }
    // Если в конце стек пуст — всё хорошо
    return st.empty();
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    if (isValid(s)) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
    return 0;
}