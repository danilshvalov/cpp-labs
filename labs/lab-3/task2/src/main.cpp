#include <cmath>
#include <iostream>

/// @brief Нахождение кубического корня с помощью std::pow
/// @param n Число из которого нужно извлечь кубический корень
/// @return Кубический корень данного числа
double Sqrt3Pow(double n) {
    return std::pow(n, 1.0 / 3.0);
}

/// @brief Нахождение кубического корня с помощью итеративного алгоритма
/// @param n Число из которого нужно извлечь кубический корень
/// @return Кубический корень данного числа
double Sqrt3Iter(double n, size_t iter_count) {
    double result = n;
    for (size_t i = 0; i < iter_count; ++i) {
        result = (n / std::pow(result, 2) + 2 * result) / 3;
    }
    return result;
}

int main() {
    std::cout << "Введите число: ";
    double n;
    std::cin >> n;

    std::cout << "Введите количество итераций: ";
    size_t iter_count;
    std::cin >> iter_count;

    std::cout << "Pow: " << Sqrt3Pow(n) << std::endl;
    std::cout << "Iter: " << Sqrt3Iter(n, iter_count) << std::endl;
}
