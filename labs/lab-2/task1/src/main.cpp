#include <iostream>
#include <vector>

/// @brief Проверить, является ли число суперпростым
/// @details В функции используется алгоритм "Решето Эратосфена" для нахождения
/// всех простых чисел начиная от 2 заканчивая самим числом. После этого
/// проверяется, является ли номер числа также простым числом
/// @param number Число, которое необходимо проверить
/// @return true, если число является суперпростым, false иначе
bool IsSuperPrimeNumber(int64_t number) {
    if (number < 2) {
        return false;
    }

    std::vector<bool> is_prime(number + 1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    size_t prime_count = 0;
    for (int64_t i = 2; i <= number; ++i) {
        if (is_prime[i]) {
            ++prime_count;
            for (int64_t j = 2; i * j <= number; ++j) {
                is_prime[i * j] = false;
            }
        }
    }

    return is_prime[number] && is_prime[prime_count];
}

int main() {
    std::cout << "Введите число: ";
    int64_t number;
    std::cin >> number;

    std::cout << "Число " << number;
    if (!IsSuperPrimeNumber(number)) {
        std::cout << " не";
    }
    std::cout << " является суперпростым" << std::endl;
}
