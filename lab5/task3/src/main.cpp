#include <iostream>

/// @brief Метод поиска с транспозицией
/// @param nums Массив чисел, в котором нужно произвести поиск
/// @param size Размер массива
/// @param value Значение, которое нужно найти
/// @return Индекс в массиве, если элемент найден, -1 иначе
int TranspositionSearch(int nums[], int size, int value) {
    for (int i = 0; i < size; ++i) {
        if (nums[i] == value) {
            if (i > 0) {
                std::swap(nums[i - 1], nums[i]);
            }
            return i;
        }
    }
    return -1;
}

int main() {
    int nums[] = {5, 1, 7, 3};
    int size = sizeof(nums) / sizeof(nums[0]);

    for (int i = 0; i < size; ++i) {
        int index = TranspositionSearch(nums, size, 7);
        std::cout << "Индекс: " << index << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << nums[i] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << "Индекс несуществующего элемента: "
              << TranspositionSearch(nums, size, 101) << std::endl;
}
