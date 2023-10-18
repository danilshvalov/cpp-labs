#include <fstream>
#include <iostream>

/// @brief Сортировка массива по неубыванию
/// @param nums Массив, который нужно отсортировать
/// @param size Размер массива
void SortArray(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        int min = i;

        for (int j = i + 1; j < size; j++) {
            min = (nums[j] < nums[min]) ? j : min;
        }

        std::swap(nums[i], nums[min]);
    }
}

/// @brief Вывод массива в поток
/// @param out Поток, в который нужно вывести массив
/// @param nums Массив, который нужно вывести
/// @param size Размер массива
void PrintArray(std::ostream& out, int nums[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            out << ' ';
        }
        out << nums[i];
    }
    out << std::endl;
}

int main() {
    std::cout << "Введите размер массива: ";
    int size;
    std::cin >> size;
    int mas[size];
    for (int i = 0; i < size; i++) {
        std::cout << "mas[" << i << "]=";
        std::cin >> mas[i];
    }

    std::cout << "Введите название файла: ";
    std::string filename;
    std::cin >> filename;

    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл \"" << filename << "\""
                  << std::endl;
        return 1;
    }

    PrintArray(file, mas, size);
    SortArray(mas, size);
    PrintArray(file, mas, size);
}
