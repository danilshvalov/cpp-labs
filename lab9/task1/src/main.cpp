#include <cmath>
#include <iostream>
#include <stdexcept>

/// @class Triangle
/// @brief Класс, представляющий собой треугольник
class Triangle {
   public:
    explicit Triangle(double first, double second, double third)
        : first_(first), second_(second), third_(third) {
        if (first_ > second_ + third_ || second_ > first_ + third_ ||
            third_ > first_ + second_) {
            throw std::invalid_argument{
                "Side of triangle cannot be greater than sum of other sides",
            };
        }
    }

    explicit Triangle(double side) : Triangle(side, side, side) {}

    /// @brief Нахождение площади треугольника
    double Square() const {
        double p = (first_ + second_ + third_) / 2;
        return std::sqrt(p * (p - first_) * (p - second_) * (p - third_));
    }

   private:
    double first_;
    double second_;
    double third_;
};

/// @brief Обработка случая равностороннего треугольника
void ProcessEquilateralTriangle() {
    std::cout << "Введите сторону треугольника: ";
    double side;
    std::cin >> side;

    Triangle triangle{side};
    std::cout << "Площадь равностороннего треугольника: " << triangle.Square()
              << std::endl;
}

/// @brief Обработка случая разностороннего треугольника
void ProccessVersatileTrinagle() {
    std::cout << "Введите стороны треугольника через пробел: ";
    double a, b, c;
    std::cin >> a >> b >> c;

    Triangle triangle{a, b, c};
    std::cout << "Площадь разностороннего треугольника: " << triangle.Square()
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
