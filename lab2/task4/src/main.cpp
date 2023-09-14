#include <iostream>
#include <map>
#include <random>
#include <vector>

/// @brief Тип очков, которые получает пользователь при попадании
using Score = int64_t;

/// @brief Тип процента
using Percentage = int;

/// @class Point
/// @brief Точка, задаваемая координатами двумя декартовыми координатами
struct Point {
    double x;
    double y;
};

/// @brief Точка цели, в которую должен попасть пользователь
const Point kTargetPoint = Point{0.0, 0.0};

/// @brief Словарь соответствия максимального расстояния от точки выстрела до
/// точки цели и количества очков, которое получит пользователь за выстрел
const std::map<double, Score> kScoreByMaxRadius = {
    {1.0, 10.0},
    {2.0, 5.0},
    {3.0, 1.0},
};

/// @class UserLevel
/// @brief Уровень пользователя исходя из его процента попаданий
enum class UserLevel {
    kSniper,
    kGoodShooter,
    kBegginer,
    kYellowMouthed,
};

/// @brief Словарь соответствия минимального процента попаданий и уровня
/// пользователя, который он может получить за все выстрелы
const std::map<Percentage, UserLevel> kUserLevelByPercentage = {
    {90, UserLevel::kSniper},
    {75, UserLevel::kGoodShooter},
    {50, UserLevel::kBegginer},
};

/// @brief Функция определения уровня пользователя по его проценту попаданий
/// @param percentage Процент попадания пользователя
/// @return Уровень пользователя
UserLevel FindUserLevel(Percentage percentage) {
    for (auto it = kUserLevelByPercentage.rbegin();
         it != kUserLevelByPercentage.rend();
         ++it) {
        if (percentage >= it->first) {
            return it->second;
        }
    }
    return UserLevel::kYellowMouthed;
}

/// @brief Функция нахождения минимального количества выстрелов, которое мог
/// совершить пользователь для достижения необходимого количества очков
/// @param required_score Необходимое количество очков для завершения игры
/// @return Минимальное количество выстрелов
size_t FindMinShots(Score required_score) {
    return std::round(
        static_cast<double>(required_score) /
        kScoreByMaxRadius.lower_bound(0)->second
    );
}

/// @brief Превращение уровня пользователя в строку
/// @param level Уровень пользователя
/// @return Строковое представление уровня пользователя
std::string ToString(UserLevel level) {
    switch (level) {
        case UserLevel::kSniper:
            return "Снайпер";
        case UserLevel::kGoodShooter:
            return "Хороший стрелок";
        case UserLevel::kBegginer:
            return "Начинающий";
        case UserLevel::kYellowMouthed:
            return "Желторотик";
    }
}

/// @brief Нахождение расстояния между двумя точками на плоскости
/// @param lhs Первая точка на плоскости
/// @param rhs Вторая точка на плоскости
/// @return Расстояние между двумя точками на плоскости
double FindDistance(const Point& lhs, const Point& rhs) {
    return std::sqrt(std::pow(lhs.x - rhs.x, 2) + std::pow(lhs.y - rhs.y, 2));
}

/// @brief Генерация псевдо-случайного вещественного числа в отрезке [from, to]
/// @param from Минимальная граница генерируемого числа
/// @param to Максимальная граница генерируемого числа
/// @return Псевдо-случайное число в отрезке [from, to]
double RandomDouble(double from, double to) {
    std::uniform_real_distribution<double> unif(from, to);
    std::default_random_engine re;
    return unif(re);
}

/// @brief Нахождение количества очков пользователя за выстрел
/// @param shot_point Точка, в которую выстрелил пользователь
/// @param target_point Точка, в которую должен был попасть пользователь
/// @return Количество очков, которое получил пользователь за выстрел
Score FindShotScore(const Point& shot_point, const Point& target_point) {
    auto it =
        kScoreByMaxRadius.lower_bound(FindDistance(shot_point, target_point));
    if (it != kScoreByMaxRadius.end()) {
        return it->second;
    } else {
        return 0;
    }
}

/// @brief Чтение количества очков, которое необходимо для завершения игры
Score ReadScore() {
    Score score;
    std::cout << "Введите победное количество очков: ";
    std::cin >> score;
    return score;
}

/// @brief Чтение координат точки, разделенных пробелом
Point ReadPoint() {
    std::cout << "Введите координаты: ";
    Point point;
    std::cin >> point.x >> point.y;
    return point;
}

int main() {
    const Score required_score = ReadScore();
    Score user_score = 0;
    size_t total_shots = 0;

    while (user_score < required_score) {
        ++total_shots;
        const Point shot_point = ReadPoint();
        const Score shot_score = FindShotScore(shot_point, kTargetPoint);

        if (shot_score == 0) {
            std::cout << "Промах!" << std::endl;
        } else {
            user_score += shot_score;
            std::cout << "Попадание! Новое количество очков: " << user_score
                      << std::endl;
        }
    }

    const size_t minimal_shots = FindMinShots(required_score);
    const Percentage percentage = minimal_shots * 100 / total_shots;
    const UserLevel level = FindUserLevel(percentage);

    std::cout << "Игра окончена" << std::endl;
    std::cout << "Процент попаданий: " << percentage << '%' << std::endl;
    std::cout << "Ваш уровень «" << ToString(level) << "»" << std::endl;
}
