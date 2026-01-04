#include <iostream>
#include <unordered_map>

std::unordered_map<size_t, size_t> cache;

size_t cycle_length(size_t n) {
    if (n == 1) {
        return 1;
    }
    
    if (cache.find(n) != cache.end()) {
        return cache[n];
    }
    
    size_t original_n = n;
    size_t length;
    
    if (n % 2 == 1) {
        length = 1 + cycle_length(3 * n + 1);
    } else {
        length = 1 + cycle_length(n / 2);
    }
    
    cache[original_n] = length;
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

    std::cout << number_with_max_cycle << " " << max_cycle_length;

    return 0;
}