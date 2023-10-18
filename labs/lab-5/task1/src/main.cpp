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

/// @brief Нахождение суммы элементов массива
/// @param nums Массив, элементы которого надо просуммировать
/// @param size Размер массива
/// @return Сумма элементов массива
int FindSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i];
    }
    return sum;
}

/// @brief Нахождение суммы отрицательных элементов массива
/// @param nums Массив, отрицательные элементы которого надо просуммировать
/// @param size Размер массива
/// @return Сумма отрицательных элементов массива
int FindNegativeSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] < 0) {
            sum += nums[i];
        }
    }
    return sum;
}

/// @brief Нахождение суммы положительных элементов массива
/// @param nums Массив, положительные элементы которого надо просуммировать
/// @param size Размер массива
/// @return Сумма положительных элементов массива
int FindPositiveSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (nums[i] > 0) {
            sum += nums[i];
        }
    }
    return sum;
}

/// @brief Нахождение суммы элементов, находящихся на нечетных позициях массива
/// @param nums Массив, элементы которого надо просуммировать
/// @param size Размер массива
/// @return Сумма элементов массива
int FindOddIndexSum(int nums[], int size) {
    int sum = 0;
    for (int i = 1; i < size; i += 2) {
        sum += nums[i];
    }
    return sum;
}

/// @brief Нахождение суммы элементов, находящихся на четных позициях массива
/// @param nums Массив, элементы которого надо просуммировать
/// @param size Размер массива
/// @return Сумма элементов массива
int FindEvenIndexSum(int nums[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i += 2) {
        sum += nums[i];
    }
    return sum;
}

/// @brief Нахождение позиций минимума и максимума в массиве
/// @param nums Массив, в котором нужно найти позиции минимума и максимума
/// @param size Размер массива
/// @return Позиции минимума и максимума в массиве
std::pair<int, int> FindMinMaxPos(int nums[], int size) {
    int min_pos = 0;
    int max_pos = 0;
    for (int i = 0; i < size; ++i) {
        if (nums[i] < nums[min_pos]) {
            min_pos = i;
        }
        if (nums[i] > nums[max_pos]) {
            max_pos = i;
        }
    }
    return {min_pos, max_pos};
}

/// @brief Нахождение произведения элементов между минимумом и максимумом
/// @param nums Массив, в котором нужно найти произведение элементов между
/// минимумом и максимумов
/// @param size Размер массива
/// @return Произведение элементов между минимумом и максимумом
int FindMultBetweenMinAndMax(int nums[], int size) {
    auto [left, right] = FindMinMaxPos(nums, size);
    if (left > right) {
        std::swap(left, right);
    }

    if (right - left < 3) {
        return 0;
    }

    int mult = nums[left++];
    for (int i = left; i < right; ++i) {
        mult *= nums[i];
    }
    return mult;
}

int main() {
    const int size = 5;
    int mas[size];
    for (int i = 0; i < size; i++) {
        std::cout << "mas[" << i << "]=";
        std::cin >> mas[i];
    }

    const int sum = FindSum(mas, size);
    std::cout << "Sum: " << sum << std::endl;

    const double avg = static_cast<double>(sum) / size;
    std::cout << "Avg: " << avg << std::endl;

    std::cout << "Sum negative: " << FindNegativeSum(mas, size) << std::endl;
    std::cout << "Sum positive: " << FindPositiveSum(mas, size) << std::endl;
    std::cout << "Sum odd index: " << FindOddIndexSum(mas, size) << std::endl;
    std::cout << "Sum even index: " << FindEvenIndexSum(mas, size) << std::endl;

    const auto [min_pos, max_pos] = FindMinMaxPos(mas, size);
    std::cout << "Min pos: " << min_pos << std::endl;
    std::cout << "Max pos: " << max_pos << std::endl;
    std::cout << "Multiplication between min and max: "
              << FindMultBetweenMinAndMax(mas, size) << std::endl;

    SortArray(mas, size);
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            std::cout << ' ';
        }
        std::cout << mas[i];
    }
    std::cout << std::endl;
}
