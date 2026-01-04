#include <iostream>
#include <unordered_map>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t A, B;

    std::cin >> A >> B;

    size_t integer_part = A / B;
    size_t remainder = A % B;

    std::cout << integer_part;
    if (remainder == 0) {
        return 0;
    }
    std::cout << ".";

    std::unordered_map<size_t, size_t> remainder_position;

    std::string decimal_part;
    size_t position = 0;
    size_t repeat_start = std::string::npos;

    while (remainder != 0) {
        if (remainder_position.find(remainder) != remainder_position.end()) {
            repeat_start = remainder_position[remainder];
            break;
        }
        remainder_position[remainder] = position;

        remainder *= 10;
        size_t digit = remainder / B;
        decimal_part += ('0' + digit);
        remainder = remainder % B;
        position++;
    }

    if (repeat_start == std::string::npos) {
        std::cout << decimal_part;
    } else {
        std::cout << decimal_part.substr(0, repeat_start) << "("
                  << decimal_part.substr(repeat_start) << ")";
    }
    return 0;
}