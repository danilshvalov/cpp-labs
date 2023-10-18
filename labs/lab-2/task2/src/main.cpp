#include <iomanip>
#include <iostream>
#include <vector>

bool IsValidSnilsImpl(int64_t sum, int64_t control_sum) {
    if (sum < 100) {
        return sum == control_sum;
    } else if (sum > 101) {
        return IsValidSnilsImpl(sum % 101, control_sum);
    } else {
        return control_sum == 0;
    }
}

/// @brief Проверяет, является ли номер СНИЛС корректным
/// @param number Номер СНИЛС
/// @return true, если номер корректен, false иначе
bool IsValidSnils(int64_t number) {
    // Последние два числа номера СНИЛС являются контрольной суммой
    const int64_t control_sum = number % 100;
    number /= 100;

    // Контрольная сумма равна сумме произведений цифр и их позиций
    // Отсчет позиций идет с конца и начинается с 1
    int64_t sum = 0;
    for (int64_t pos = 1; number > 0; ++pos) {
        sum += (number % 10) * pos;
        number /= 10;
    }

    return IsValidSnilsImpl(sum, control_sum);
}

/// @brief Превращение номера СНИЛС в строку в формате "000-000-000 00"
/// @param number Номер СНИЛС
/// @return Строка вида "000-000-000 00"
std::string SnilsToString(int64_t number) {
    std::string result = "000-000-000 00";
    size_t div = 1;
    for (size_t i = result.size(); i > 0; --i) {
        if (std::isdigit(result[i - 1])) {
            result[i - 1] = '0' + (number % (div * 10)) / div;
            div *= 10;
        }
    }
    return result;
}

int main() {
    std::cout << "Введите номер СНИЛС: ";
    int64_t number;
    std::cin >> number;

    std::cout << "Номер СНИЛС " << SnilsToString(number);
    if (!IsValidSnils(number)) {
        std::cout << " не";
    }
    std::cout << " является корректным" << std::endl;
}
