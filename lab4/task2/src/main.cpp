#include <iostream>

/// @brief Функция считывания двух чисел
/// @param a[out] Первое считываемое число
/// @param b[out] Второе считываемое число
/// @return true, если считывание произошло без ошибок, false иначе
bool Input(int& a, int& b) {
    std::cin >> a;
    if (!std::cin.good()) {
        return false;
    }

    std::cin >> b;
    if (!std::cin.good()) {
        return false;
    }

    return true;
}

int main() {
    std::cout << "Введите два числа: ";
    int a, b;
    if (!Input(a, b)) {
        std::cerr << "Некорректные данные";
        return 1;
    }

    int sum = a + b;
    std::cout << "Сумма: " << sum << std::endl;
    return 0;
}
