#include <cmath>
#include <iostream>

/// @brief Нахождение корней квадратного уравнения по коэффициентам
/// @param[in] a Старший коэффициент
/// @param[in] b Средний коэффициент
/// @param[in] c Свободный член
/// @param[out] x1 Первый корень
/// @param[out] x2 Второй корень
/// @return 1, если корня два, 0, если корень один, -1, если корней нет
int Myroot(double a, double b, double c, double& x1, double& x2) {
    double d = std::pow(b, 2) - 4 * a * c;
    if (d < 0) {
        return -1;
    }

    d = std::sqrt(d);
    if (d > 0) {
        x1 = (-b - d) / 2;
        x2 = (-b + d) / 2;
        return 1;
    } else {
        x1 = x2 = -b / 2;
        return 0;
    }
}

int main() {
    std::cout << "Введите коэффициенты a, b, c через пробел: ";
    double a, b, c;
    std::cin >> a >> b >> c;

    double x1, x2;
    int result = Myroot(a, b, c, x1, x2);
    if (result == 1) {
        std::cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2
                  << std::endl;
    } else if (result == 0) {
        std::cout << "Корень уравнения один x1 = x2 = " << x1 << std::endl;
    } else {
        std::cout << "Корней нет" << std::endl;
    }
}
