#include <iostream>
#include <stack>

/**
 * Для каждого элемента массива найдите следующий элемент справа,
 * который больше текущего. Если такого нет, выведите -1.
 * 
 * Используйте стек для решения за O(N).
 */

int main() {
    int n;
    std::cin >> n;

    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;

        while (!s.empty() && s.top() < x) {
            std::cout << x << ' ';
            s.pop();
        }

        s.push(x);
    }

    while (!s.empty()) {
        std::cout << -1 << ' ';
        s.pop();
    }

    return 0;
}