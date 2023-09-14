#include <iomanip>
#include <iostream>
#include <stdexcept>

/// @brief Количество секунд в минуте
const int kSecondsInMinute = 60;

/// @brief Количество минут в часе
const int kMinutesInHour = 60;

/// @brief Количество секунд в часе
const int kSecondsInHour = kSecondsInMinute * kMinutesInHour;

/// @brief Количество часов в дне
const int kHoursInDay = 24;

/// @brief Количество секунд в дне
const int kSecondsInDay = kSecondsInHour * kHoursInDay;

/// @class Time
/// @brief Класс, представляющий время в формате часы, минуты, секунды
class Time {
   public:
    int hours;
    int minutes;
    int seconds;

    explicit Time() : Time(0, 0, 0, false) {}

    explicit Time(int hours, int minutes, int seconds)
        : Time(hours, minutes, seconds, true) {}

    /// @brief Преобразование времени в секунды начиная с 00:00:00
    int ToSeconds() const {
        return hours * kSecondsInHour + minutes * kSecondsInMinute + seconds;
    }

    /// @brief Секунд начиная с 00:00:00 во время в формате часы, минуты,
    /// секунды
    static Time FromSeconds(int total_seconds) {
        total_seconds %= kSecondsInDay;
        int seconds = total_seconds % kSecondsInMinute;
        total_seconds /= kSecondsInMinute;
        int minutes = total_seconds % kMinutesInHour;
        total_seconds /= kMinutesInHour;
        int hours = total_seconds;
        return Time{hours, minutes, seconds, false};
    }

    friend Time operator+(const Time& lhs, const Time& rhs) {
        return FromSeconds(lhs.ToSeconds() + rhs.ToSeconds());
    }

    friend Time operator+(const Time& lhs, double rhs) {
        int seconds = static_cast<int>(rhs) * kSecondsInMinute +
                      static_cast<int>(rhs * 100) % 100;
        return FromSeconds(lhs.ToSeconds() + seconds);
    }

    friend Time operator+(double lhs, const Time& rhs) {
        return rhs + lhs;
    }

    friend Time operator-(const Time& lhs, const Time& rhs) {
        int seconds = lhs.ToSeconds() - rhs.ToSeconds();
        if (seconds < 0) {
            seconds += kSecondsInDay;
        }
        return FromSeconds(seconds);
    }

    friend bool operator==(const Time& lhs, const Time& rhs) {
        return lhs.ToSeconds() == rhs.ToSeconds();
    }

    friend bool operator!=(const Time& lhs, const Time& rhs) {
        return !(lhs == rhs);
    }

    friend bool operator<(const Time& lhs, const Time& rhs) {
        return lhs.ToSeconds() < rhs.ToSeconds();
    }

    friend bool operator<=(const Time& lhs, const Time& rhs) {
        return lhs < rhs || lhs == rhs;
    }

    friend bool operator>(const Time& lhs, const Time& rhs) {
        return lhs != rhs && !(lhs < rhs);
    }

    friend bool operator>=(const Time& lhs, const Time& rhs) {
        return !(lhs < rhs);
    }

    /// @brief Чтение времени из потока в формате HH:MM:SS
    /// @param in Поток, из которого нужно считать
    /// @param[out] time Время, в которое будет считана информация
    friend std::istream& operator>>(std::istream& in, Time& time) {
        in >> time.hours;
        in.get();
        in >> time.minutes;
        in.get();
        in >> time.seconds;
        time.JustifyTime();
        return in;
    }

    /// @brief Вывод времени в поток
    /// @param out Поток, в который нужно вывести время
    /// @param time Время, которое нужно вывести в поток
    friend std::ostream& operator<<(std::ostream& out, const Time& time) {
        out << std::setw(2) << std::setfill('0') << time.hours;
        out << ':';
        out << std::setw(2) << std::setfill('0') << time.minutes;
        out << ':';
        out << std::setw(2) << std::setfill('0') << time.seconds;
        return out;
    }

   private:
    explicit Time(int hours, int minutes, int seconds, bool validate)
        : hours(hours), minutes(minutes), seconds(seconds) {
        if (validate) {
            JustifyTime();
        }
    }

    /// @brief Обмен данных о времени между собой
    /// @param other Время, с которым нужно поменять данные
    void Swap(Time& other) {
        std::swap(hours, other.hours);
        std::swap(minutes, other.minutes);
        std::swap(seconds, other.seconds);
    }

    /// @brief Приведение времени к нормальному виду
    void JustifyTime() {
        FromSeconds(ToSeconds() % kSecondsInDay).Swap(*this);
    }
};

int main() {
    std::cout << "Enter first time in format \"HH:MM:SS\": ";
    Time t1;
    std::cin >> t1;

    std::cout << "Enter second time as double: ";
    double t2;
    std::cin >> t2;

    std::cout << "t1 + t2: " << t1 + t2 << std::endl;
    std::cout << "t1 + t2: " << t2 + t1 << std::endl;
}
