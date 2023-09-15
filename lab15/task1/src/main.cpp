#include "GradeManager.h"
#include "IdCard.h"
#include "Student.h"

#include <iostream>
#include <string>

using namespace std;

void printStudentGrade(StudentGrade* grade) {
    if (grade) {
        std::cout << "Оценка " << grade->grade << std::endl;
    } else {
        std::cout << "Оценка не найдена" << std::endl;
    }
}

int main() {
    IdCard* idc = new IdCard(123456, "Базовый");
    IdCard* idc2 = new IdCard(654321, "Базовый");

    Student student1("Петр", "Петров", idc);
    Student student2("Семен", "Смирнов", idc2);

    GradeManager grades;
    grades.addStudentGrade(student1.get_name(), 'A');

    StudentGrade* grade1 = grades.findStudentGrade(student1.get_name());
    printStudentGrade(grade1);

    StudentGrade* grade2 = grades.findStudentGrade(student2.get_name());
    printStudentGrade(grade2);
}
