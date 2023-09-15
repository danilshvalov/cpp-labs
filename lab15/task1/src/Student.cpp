#include "Student.h"

#include "Group.h"

#include <iostream>
#include <string>

using namespace std;

// Конструктор Student
Student::Student(string name, string last_name, IdCard* id) {
    Student::set_name(name);
    Student::set_last_name(last_name);
    Student::setIdCard(id);
    Student::set_average_score(0);
}

Student::Student() {}
// Установка имени студента
void Student::set_name(std::string student_name) {
    Student::name = student_name;
}

// Получение имени студента
std::string Student::get_name() {
    return Student::name;
}

// Установка фамилии студента
void Student::set_last_name(std::string student_last_name) {
    Student::last_name = student_last_name;
}

// Получение фамилии студента
std::string Student::get_last_name() {
    return Student::last_name;
}

// Установка промежуточных оценок
void Student::set_scores(int scores[]) {
    for (int i = 0; i < 5; ++i) {
        Student::scores[i] = scores[i];
    }
}

// Установка среднего балла
void Student::set_average_score(double ball) {
    Student::average_score = ball;
}

// Получение среднего балла
double Student::get_average_score() {
    return Student::average_score;
}

void Student::setIdCard(IdCard* c) {
    iCard = c;
}

IdCard Student::getIdCard() {
    return *iCard;
}

void Student::display() const  // вывод всех данных о студенте
{
    cout << last_name << " " << name << "\t" << average_score << "\t"
         << iCard->getNumber() << "\t" << iCard->getCategory() << endl;
}

bool operator==(const Student& p1, const Student& p2) {
    return (p1.name == p2.name && p1.last_name == p2.last_name) ? true : false;
}

bool operator<(const Student& p1, const Student& p2) {
    if (p1.last_name == p2.last_name) return (p1.name < p2.name) ? true : false;
    return (p1.last_name < p2.last_name) ? true : false;
}

bool operator!=(Student& p1, Student& p2) {
    return !(p1 == p2);
}

bool operator>(Student& p1, Student& p2) {
    return !(p1 < p2) && !(p2 == p2);
}
