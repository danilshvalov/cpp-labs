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

class Time {
   public:
    int hours;
    int minutes;
    int seconds;

    explicit Time() : Time(0, 0, 0) {}

    explicit Time(int hours, int minutes, int seconds)
        : hours(hours), minutes(minutes), seconds(seconds) {
        Validate();
    }

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
        return Time{hours, minutes, seconds};
    }

    /// @brief Прибавление времени
    /// @param other Время, которое нужно прибавить
    Time& Add(const Time& other) {
        FromSeconds(ToSeconds() + other.ToSeconds()).Swap(*this);
        return *this;
    }

    /// @brief Вычитание времени
    /// @param other Время, которое нужно вычесть
    Time& Sub(const Time& other) {
        int seconds = ToSeconds() - other.ToSeconds();
        if (seconds < 0) {
            seconds += kSecondsInDay;
        }
        FromSeconds(seconds).Swap(*this);
        return *this;
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
        time.Validate();
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
    /// @brief Обмен данных о времени между собой
    /// @param other Время, с которым нужно поменять данные
    void Swap(Time& other) {
        std::swap(hours, other.hours);
        std::swap(minutes, other.minutes);
        std::swap(seconds, other.seconds);
    }

    /// @brief Проверка корректности времени
    void Validate() const {
        if (!(hours >= 0 && hours < 24)) {
            throw std::invalid_argument{"Hours value must be from 0 to 23"};
        }
        if (!(minutes >= 0 && minutes < 60)) {
            throw std::invalid_argument{"Minutes value must be from 0 to 59"};
        }
        if (!(seconds >= 0 && seconds < 60)) {
            throw std::invalid_argument{"Seconds value must be from 0 to 59"};
        }
    }
};

int main() {
    try {
        std::cout << "Enter first time in format \"HH:MM:SS\": ";
        Time t1;
        std::cin >> t1;

        std::cout << "Enter second time in format \"HH:MM:SS\": ";
        Time t2;
        std::cin >> t2;

        std::cout << "t1 + t2: " << t1.Add(t2) << std::endl;
        std::cout << "t1 - t2: " << t1.Sub(t2) << std::endl;
        std::cout << "t2 - t1: " << t2.Sub(t1) << std::endl;

    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}
