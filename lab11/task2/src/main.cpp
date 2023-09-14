#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

/// @class Point
/// @brief Точка, задаваемая координатами двумя декартовыми координатами
struct Point {
    double x;
    double y;

    Point(double x, double y) : x(x), y(y) {}

    /// @brief Нахождения расстояния до центра координат
    /// @return Расстояние до центра координат
    double DistanceToOrigin() const {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    }

    friend std::ostream& operator<<(std::ostream& out, const Point& p) {
        return out << '(' << p.x << ", " << p.y << ')';
    }

    friend bool operator<(const Point& lhs, const Point& rhs) {
        return lhs.DistanceToOrigin() < rhs.DistanceToOrigin();
    }
};

int main() {
    std::vector<Point> v;
    v.push_back(Point(1, 2));
    v.push_back(Point(10, 12));
    v.push_back(Point(21, 7));
    v.push_back(Point(4, 8));
    std::sort(v.begin(), v.end());

    for (auto& point : v) {
        std::cout << point << '\n';
    }
}
