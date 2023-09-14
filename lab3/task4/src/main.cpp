#include <iostream>

int FindSeriesSumImpl(int n, int k, int depth) {
    if (n == 0) {
        return 0;
    }
    return FindSeriesSumImpl(n - 1, k, depth + 1) + k * depth;
}

/// @brief Нахождение суммы ряда
/// @param n Количество членов ряда
/// @param k Коэффициент ряда
/// @return Сумма ряда
int FindSeriesSum(int n, int k) {
    return FindSeriesSumImpl(n, k, 1);
}

int main() {
    std::cout << "Введите n: ";
    int n;
    std::cin >> n;

    int sum = FindSeriesSum(n, 5);
    std::cout << "Сумма ряда равна: " << sum << std::endl;
}
