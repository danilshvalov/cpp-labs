#include <cmath>
#include <iostream>

std::tuple<int, double, double> FindRoots(double a, double b, double c) {
    double d = std::pow(b, 2) - 4 * a * c;
    if (d < 0) {
        return {0, 0, 0};
    }

    d = std::sqrt(d);
    if (d > 0) {
        return {2, (-b - d) / 2, (-b + d) / 2};
    } else {
        double x = -b / 2;
        return {1, x, x};
    }
}

int main() {
    std::cout << "Введите коэффициенты a, b, c через пробел: ";
    double a, b, c;
    std::cin >> a >> b >> c;

    std::tuple<int, double, double> roots = FindRoots(a, b, c);
    int root_count = std::get<0>(roots);
    double x1 = std::get<1>(roots);
    double x2 = std::get<2>(roots);
    if (root_count == 2) {
        std::cout << "Корни уравнения x1 = " << x1 << ", x2 = " << x2
                  << std::endl;
    } else if (root_count == 1) {
        std::cout << "Корень уравнения один x1 = x2 = " << x1 << std::endl;
    } else {
        std::cout << "Корней нет" << std::endl;
    }
}
