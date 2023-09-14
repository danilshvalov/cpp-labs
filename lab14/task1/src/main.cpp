#include <iostream>

/// @brief Нахождение среднего значения элементов массива
/// @tparam T Тип элементов массива
/// @param nums Массив элементов
/// @param size Размер массива элементов
/// @return Среднее значение элементов массива
template <typename T>
T FindAvg(T nums[], int size) {
    T sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += nums[i];
    }
    return sum / size;
}

int main() {
    const int size = 6;
    int ints[] = {1, 2, 3, 4, 5, 6};
    int longs[] = {1, 2, 3, 4, 5, 6};
    double doubles[] = {1, 2, 3, 4, 5, 6};
    char chars[] = {1, 2, 3, 4, 5, 6};

    std::cout << FindAvg(ints, size) << std::endl;
    std::cout << FindAvg(longs, size) << std::endl;
    std::cout << FindAvg(doubles, size) << std::endl;
    std::cout << static_cast<int>(FindAvg(chars, size)) << std::endl;
}
