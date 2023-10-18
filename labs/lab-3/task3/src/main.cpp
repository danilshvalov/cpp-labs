#include <cmath>
#include <iostream>

/// @brief Нахождение площади треугольника по его сторонам
/// @param a Первая сторона треугольника
/// @param b Вторая сторона треугольника
/// @param c Третья сторона треугольника
/// @return Площадь треугольника
double FindTriangleSquare(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

/// @brief Нахождение площади равностороннего треугольника по его стороне
/// @param side Сторона треугольника
/// @return Площадь треугольника
double FindTriangleSquare(double side) {
    return FindTriangleSquare(side, side, side);
}

/// @brief Обработка случая равностороннего треугольника
void ProcessEquilateralTriangle() {
    std::cout << "Введите сторону треугольника: ";
    double side;
    std::cin >> side;

    double square = FindTriangleSquare(side);
    std::cout << "Площадь равностороннего треугольника: " << square
              << std::endl;
}

/// @brief Обработка случая разностороннего треугольника
void ProccessVersatileTrinagle() {
    std::cout << "Введите стороны треугольника через пробел: ";
    double a, b, c;
    std::cin >> a >> b >> c;

    double square = FindTriangleSquare(a, b, c);
    std::cout << "Площадь разностороннего треугольника: " << square
              << std::endl;
}

int main() {
    std::cout << "Введите тип треугольника (0 — равносторонний, 1 — "
                 "разносторонний): ";
    int type;
    std::cin >> type;

    switch (type) {
        case 0: {
            ProcessEquilateralTriangle();
            break;
        }
        case 1: {
            ProccessVersatileTrinagle();
            break;
        }
        default: {
            std::cout << "Неверный тип треугольника" << std::endl;
            break;
        }
    }
}
