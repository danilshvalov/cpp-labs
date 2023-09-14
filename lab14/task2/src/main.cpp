#include <iostream>
#include <string>
#include <vector>

/// @brief Печать в стандартный вывод контейнера через заданный разделитель
/// @tparam T Тип контейнера
/// @param values Контейнер, который нужно распечатать
/// @param sep Разделитель элементов
template <typename T>
void Print(const T& values, const std::string& sep) {
    bool first = true;
    for (const auto& v : values) {
        if (!first) {
            std::cout << sep;
        }
        first = false;
        std::cout << v;
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> data = {1, 2, 3};
    Print(data, ", ");
}
