#include <iostream>
#include <vector>

/// @class Point
/// @brief Точка, задаваемая координатами двумя декартовыми координатами
struct Point {
    double x;
    double y;
};

/// @brief Поиск площади многоугольника с помощью формулы площади Гаусса по
/// вершинам многоугольника, которые заданы декартовыми точками на плоскости
/// @param points Точки, являющиеся вершинами многоугольника
/// @return Площадь многоугольника
double FindFigureSquare(const std::vector<Point>& points) {
    double sum = 0;
    for (size_t i = 0; i < points.size(); ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i + 1) % points.size()];
        sum += p1.x * p2.y - p2.x * p1.y;
    }
    return std::abs(sum) / 2.0;
}

int main() {
    std::cout << "Введите количество вершин многоугольника: ";
    size_t points_count;
    std::cin >> points_count;

    std::vector<Point> points;
    points.reserve(points_count);
    for (size_t i = 0; i < points_count; ++i) {
        std::cout << "Введите координаты x и y для " << i + 1 << " вершины: ";
        double x, y;
        std::cin >> x >> y;
        points.push_back(Point{x, y});
    }

    double square = FindFigureSquare(points);

    std::cout << "Площадь многоугольника: " << square << std::endl;
}
