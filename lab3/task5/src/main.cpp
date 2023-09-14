#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

/// @brief Превращение числа в бинарный вид в виде строки
/// @param number Число, которое необходимо преобразовать в бинарный вид
/// @return Строковое представление бинарного вида числа
std::string ToBinary(int number) {
    if (number == 0) {
        return "";
    }
    return ToBinary(number / 2) + std::to_string(number % 2);
}

int main() {
    std::cout << "Введите число: ";
    int number;
    std::cin >> number;

    std::cout << "В бинарном виде: " << ToBinary(number) << std::endl;
}
