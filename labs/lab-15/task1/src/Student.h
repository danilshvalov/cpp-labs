#pragma once
#include <string>

#include "IdCard.h"

using namespace std;

class Student {
   public:
    // Конструктор класса Student
    Student(string, string, IdCard*);
    Student();

    // Установка имени студента
    void set_name(string);
    // Получение имени студента
    string get_name();
    // Установка фамилии студента
    void set_last_name(string);
    // Получение фамилии студента
    string get_last_name();
    // Установка промежуточных оценок
    void set_scores(int[]);
    // Установка среднего балла
    void set_average_score(double);
    // Получение среднего балла
    double get_average_score();
    // Вывод информации о студенте
    void display() const;

    void setIdCard(IdCard* c);
    IdCard getIdCard();

    friend bool operator<(const Student&, const Student&);
    friend bool operator>(const Student&, const Student&);
    friend bool operator==(const Student&, const Student&);
    friend bool operator!=(const Student&, const Student&);

   private:
    // Промежуточные оценки
    int scores[5];
    // Средний балл
    double average_score;
    // Имя
    string name;
    // Фамилия
    string last_name;
    // Карточка
    IdCard* iCard;
};

class compareStudent {
   public:
    bool operator()(const Student* ptrSt1, const Student* ptrSt2) const {
        return *ptrSt1 < *ptrSt2;
    }
};
