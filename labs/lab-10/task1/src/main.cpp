#include <cmath>
#include <iostream>
#include <stdexcept>

/// @class Dot
/// @brief Класс, представляющий собой точку на декартовой плоскости
struct Dot {
    double x;
    double y;

    Dot() : Dot(0, 0) {}

    Dot(double x, double y) : x(x), y(y) {}

    /// @brief Нахождение расстояния до другой точки
    /// @param point Точка, до которой необходимо найти расстояние
    /// @return Расстояние до заданной точки
    double DistanceTo(const Dot& point) const {
        return std::sqrt(std::pow(point.x - x, 2) + std::pow(point.y - y, 2));
    }
};

/// @class TriangleComposition
/// @brief Класс, представляющий собой треугольник как композиция точек
class TriangleComposition {
   public:
    explicit TriangleComposition(
        double first_x,
        double first_y,
        double second_x,
        double second_y,
        double third_x,
        double third_y
    )
        : first_(first_x, first_y),
          second_(second_x, second_y),
          third_(third_x, third_y) {
        double first_side = FirstSideLength();
        double second_side = SecondSideLength();
        double third_side = ThirdSideLength();
        if (first_side > second_side + third_side ||
            second_side > first_side + third_side ||
            third_side > first_side + second_side) {
            throw std::invalid_argument{
                "Side of triangle cannot be greater than sum of other sides",
            };
        }
    }

    /// @brief Нахождение длины первой стороны
    double FirstSideLength() const {
        return first_.DistanceTo(second_);
    }

    /// @brief Нахождение длины второй стороны
    double SecondSideLength() const {
        return second_.DistanceTo(third_);
    }

    /// @brief Нахождение длины третьей стороны
    double ThirdSideLength() const {
        return third_.DistanceTo(first_);
    }

    /// @brief Нахождение периметра треугольника
    double Perimeter() const {
        double first_side = FirstSideLength();
        double second_side = SecondSideLength();
        double third_side = ThirdSideLength();
        return first_side + second_side + third_side;
    }

    /// @brief Нахождение площади треугольника
    double Square() const {
        double first_side = FirstSideLength();
        double second_side = SecondSideLength();
        double third_side = ThirdSideLength();
        double p = Perimeter() / 2;
        return std::sqrt(
            p * (p - first_side) * (p - second_side) * (p - third_side)
        );
    }

   private:
    Dot first_;
    Dot second_;
    Dot third_;
};

/// @class TriangleAggregation
/// @brief Класс, представляющий собой треугольник как агрегация точек
class TriangleAggregation {
   public:
    explicit TriangleAggregation(Dot first, Dot second, Dot third)
        : first_(first), second_(second), third_(third) {
        double first_side = FirstSideLength();
        double second_side = SecondSideLength();
        double third_side = ThirdSideLength();
        if (first_side > second_side + third_side ||
            second_side > first_side + third_side ||
            third_side > first_side + second_side) {
            throw std::invalid_argument{
                "Side of triangle cannot be greater than sum of other sides",
            };
        }
    }

    /// @brief Нахождение длины первой стороны
    double FirstSideLength() const {
        return first_.DistanceTo(second_);
    }

    /// @brief Нахождение длины второй стороны
    double SecondSideLength() const {
        return second_.DistanceTo(third_);
    }

    /// @brief Нахождение длины третьей стороны
    double ThirdSideLength() const {
        return third_.DistanceTo(first_);
    }

    /// @brief Нахождение периметра треугольника
    double Perimeter() const {
        double first_side = FirstSideLength();
        double second_side = SecondSideLength();
        double third_side = ThirdSideLength();
        return first_side + second_side + third_side;
    }

    /// @brief Нахождение площади треугольника
    double Square() const {
        double first_side = FirstSideLength();
        double second_side = SecondSideLength();
        double third_side = ThirdSideLength();
        double p = Perimeter() / 2;
        return std::sqrt(
            p * (p - first_side) * (p - second_side) * (p - third_side)
        );
    }

   private:
    Dot first_;
    Dot second_;
    Dot third_;
};

int main() {
    TriangleComposition t1(0, 0, 0, 3, 4, 0);
    std::cout << "Side 1: " << t1.FirstSideLength() << std::endl;
    std::cout << "Side 2: " << t1.SecondSideLength() << std::endl;
    std::cout << "Side 3: " << t1.ThirdSideLength() << std::endl;
    std::cout << "Perimeter: " << t1.Perimeter() << std::endl;
    std::cout << "Square: " << t1.Square() << std::endl;

    TriangleAggregation t2(Dot{0, 0}, Dot{0, 3}, Dot{4, 0});
    std::cout << "Side 1: " << t2.FirstSideLength() << std::endl;
    std::cout << "Side 2: " << t2.SecondSideLength() << std::endl;
    std::cout << "Side 3: " << t2.ThirdSideLength() << std::endl;
    std::cout << "Perimeter: " << t2.Perimeter() << std::endl;
    std::cout << "Square: " << t2.Square() << std::endl;
}
