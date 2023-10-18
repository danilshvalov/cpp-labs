#include <iostream>
#include <string_view>

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

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Неверное количество параметров. Ожидалось 3 параметра, "
                     "получено "
                  << (argc - 1) << std::endl;
        return 1;
    }

    const std::string_view param = argv[1];
    if (param != "-a" && param != "-m") {
        std::cerr << "Некорректный параметр \"" << param << "\"" << std::endl;
        return 1;
    }

    try {
        int a = std::stoi(argv[2]);
        int b = std::stoi(argv[3]);
        if (param == "-a") {
            std::cout << a + b << std::endl;
        } else if (param == "-m") {
            std::cout << a * b << std::endl;
        }
    } catch (const std::invalid_argument&) {
        std::cout << "Некорректный ввод" << std::endl;
        return 1;
    }
}
