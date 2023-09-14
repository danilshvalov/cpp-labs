#include <iostream>

/// @brief Получение массива, элементы которого являются максимумом из двух
/// данных массивов на каждой из позиций
/// @param size Размер массивов
/// @param a Первый массив
/// @param b Второй массив
/// @return Массив, содержащий максимумы из двух массивов на каждой из позиций
int* max_vect(int size, int a[], int b[]) {
    int* result = new int[size];
    for (int i = 0; i < size; ++i) {
        result[i] = std::max(a[i], b[i]);
    }
    return result;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 2};
    int b[] = {7, 6, 5, 4, 3, 2, 1, 3};
    int size = sizeof(a) / sizeof(a[0]);

    int* c;
    c = max_vect(size, a, b);
    for (int i = 0; i < size; i++) {
        std::cout << c[i] << ' ';
    }
    std::cout << std::endl;

    delete[] c;
}
