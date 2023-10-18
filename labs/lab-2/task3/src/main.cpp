#include <array>
#include <iostream>
#include <vector>

/// @brief Существующее количество номиналов монет
constexpr size_t kCoinsCount = 11;

/// @brief Массив, представляющий информацию о монетах
using Coins = std::array<int64_t, kCoinsCount>;

/// @brief Номиналы монет
constexpr Coins kCoinValues = {
    5000,
    2000,
    1000,
    500,
    200,
    100,
    50,
    10,
    5,
    2,
    1,
};

/// @brief Функция размена суммы по монетам существующих номиналов от большего к
/// меньшему
/// @details В функции используется жадный алгоритм, который пытается выдать
/// наибольшее количество монет с высшим номиналом
/// @param sum Сумма, которую необходимо разменять
/// @return Количество монет каждого номинала
Coins ExchangeCoins(int64_t sum) {
    Coins result = {0};
    for (size_t i = 0; i < kCoinValues.size(); ++i) {
        int64_t coin = kCoinValues[i];
        while (sum >= coin) {
            sum -= coin;
            ++result[i];
        }
    }
    return result;
}

int main() {
    std::cout << "Введите сумму: ";
    int64_t sum;
    std::cin >> sum;

    Coins coins = ExchangeCoins(sum);
    std::cout << "Номинал\tКоличество" << std::endl;
    for (size_t i = 0; i < coins.size(); ++i) {
        if (coins[i] > 0) {
            std::cout << kCoinValues[i] << '\t' << coins[i] << std::endl;
        }
    }
}
