#include <iostream>
#include <string>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct fraction {
    size_t numerator;
    size_t denominator;

    fraction(size_t num, size_t denom)
        : numerator(num / gcd(num, denom)), denominator(denom / gcd(num, denom)) {}

    fraction(float value) {
        while (value != static_cast<int>(value)) {
            value *= 10;
            denominator *= 10;
        }
        numerator = static_cast<size_t>(value);
        size_t divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

    fraction& operator+=(const fraction& other) {
        size_t common_denominator = denominator * other.denominator;
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator = common_denominator;
        size_t divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
        return *this;
    }
};

fraction& operator+(fraction lhs, const fraction& rhs) {
    lhs += rhs;
    return lhs;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string number;
    std::cin >> number;
    std::string non_repeating, repeating;
    bool in_repeating = false;

    for(size_t i = 0; i < number.size(); ++i) {
        if (number[i] == '(') {
            in_repeating = true;
            continue;
        }
        if (number[i] == ')') {
            break;
        }
        if (in_repeating) {
            repeating += number[i];
        } else {
            non_repeating += number[i];
        }
    }

    fraction result(0, 1);
    if (!non_repeating.empty()) {
        std::size_t decimal_pos = non_repeating.find('.');
        if (decimal_pos == std::string::npos) {
            // non_repeating is an integer
            std::size_t int_value = std::stoull(non_repeating);
            result += fraction(int_value, 1);
        } else {
            std::string integer_part = non_repeating.substr(0, decimal_pos);
            std::string fractional_part = non_repeating.substr(decimal_pos + 1);

            std::size_t int_value = 0;
            if (!integer_part.empty()) {
                int_value = std::stoull(integer_part);
            }

            std::size_t frac_value = 0;
            if (!fractional_part.empty()) {
                frac_value = std::stoull(fractional_part);
            }

            std::size_t denom = 1;
            for (std::size_t i = 0; i < fractional_part.size(); ++i) {
                denom *= 10;
            }

            std::size_t numerator = int_value * denom + frac_value;
            result += fraction(numerator, denom);
        }
    }

    // period to fraction. let x = 0.(repeating), in this case x = repeating / (10^len(repeating) - 1)
    if (!repeating.empty()) {
        size_t len_repeating = repeating.size();
        size_t denom = 1;
        for (size_t i = 0; i < len_repeating; ++i) {
            denom *= 10;
        }
        denom -= 1;

        fraction period_fraction(std::stoul(repeating), denom);

        // shift period fraction to the right position
        size_t shift_denom = 1;
        for (size_t i = 0; i < non_repeating.size(); ++i) {
            shift_denom *= 10;
        }
        period_fraction.denominator *= shift_denom;

        result += period_fraction;
    }

    std::cout << result.numerator << " " << result.denominator;

    return 0;
}