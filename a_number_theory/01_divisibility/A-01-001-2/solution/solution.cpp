#include <iostream>

size_t cycle_length(size_t n) {
    size_t length = 1;
    while (n != 1) {
        if (n % 2 == 1) {
            n = 3 * n + 1;
        } else {
            n = n / 2;
        }
        length++;
    }
    return length;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t i, j;
    std::cin >> i >> j;

    size_t max_cycle_length = 0;
    size_t number_with_max_cycle = i;

    for (size_t num = i; num <= j; ++num) {
        size_t current_cycle_length = cycle_length(num);
        if (current_cycle_length > max_cycle_length) {
            max_cycle_length = current_cycle_length;
            number_with_max_cycle = num;
        }
    }

    std::cout << number_with_max_cycle << " " << max_cycle_length << "\n";

    return 0;
}