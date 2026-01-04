#include <iostream>

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

    // Массивы для хранения остатков и цифр дробной части
    const size_t MAX_SIZE = 1000001; // B <= 1000000, максимум столько уникальных остатков
    size_t remainder_positions[MAX_SIZE]; // позиция каждого остатка (-1 если не встречался)
    char decimal_digits[MAX_SIZE];       // цифры дробной части
    
    // Инициализация: -1 означает "остаток не встречался"
    for (size_t i = 0; i < MAX_SIZE; ++i) {
        remainder_positions[i] = SIZE_MAX;
    }
    
    size_t position = 0;
    size_t repeat_start = SIZE_MAX;
    
    while (remainder != 0) {
        // Проверяем, встречали ли этот остаток раньше
        if (remainder_positions[remainder] != SIZE_MAX) {
            repeat_start = remainder_positions[remainder];
            break;
        }
        
        // Запоминаем позицию текущего остатка
        remainder_positions[remainder] = position;
        
        // Выполняем шаг деления
        remainder *= 10;
        size_t digit = remainder / B;
        decimal_digits[position] = '0' + digit;
        remainder = remainder % B;
        position++;
    }
    
    // Вывод результата
    if (repeat_start == SIZE_MAX) {
        // Нет повторения - конечная десятичная дробь
        for (size_t i = 0; i < position; ++i) {
            std::cout << decimal_digits[i];
        }
    } else {
        // Есть повторение
        // Выводим неповторяющуюся часть
        for (size_t i = 0; i < repeat_start; ++i) {
            std::cout << decimal_digits[i];
        }
        // Выводим повторяющуюся часть в скобках
        std::cout << "(";
        for (size_t i = repeat_start; i < position; ++i) {
            std::cout << decimal_digits[i];
        }
        std::cout << ")";
    }
    
    return 0;
}
