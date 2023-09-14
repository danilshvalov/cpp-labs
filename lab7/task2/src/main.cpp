#include <cmath>
#include <iostream>

/// @class Roots
/// @brief Решения квадратного уравнения
struct Roots {
    int root_count;
    double x1;
    double x2;
};

/// @brief Нахождение корней квадратного уравнения по коэффициентам
/// @param[in] a Старший коэффициент
/// @param[in] b Средний коэффициент
/// @param[in] c Свободный член
/// @return Решение квадратного уравнения
Roots FindRoots(double a, double b, double c) {
    double d = std::pow(b, 2) - 4 * a * c;
    if (d < 0) {
        return Roots{0};
    }

    d = std::sqrt(d);
    if (d > 0) {
        return Roots{2, (-b - d) / 2, (-b + d) / 2};
    } else {
        double x = -b / 2;
        return Roots{1, x, x};
    }
}

int main() {
    std::cout << "Введите коэффициенты a, b, c через пробел: ";
    double a, b, c;
    std::cin >> a >> b >> c;

    Roots roots = FindRoots(a, b, c);
    if (roots.root_count == 2) {
        std::cout << "Корни уравнения x1 = " << roots.x1
                  << ", x2 = " << roots.x2 << std::endl;
    } else if (roots.root_count == 1) {
        std::cout << "Корень уравнения один x1 = x2 = " << roots.x1
                  << std::endl;
    } else {
        std::cout << "Корней нет" << std::endl;
    }
}
