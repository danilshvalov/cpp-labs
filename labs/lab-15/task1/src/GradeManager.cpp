#include "GradeManager.h"

void GradeManager::addStudentGrade(
    const std::string& student_name, char grade
) {
    grade_by_student_name[student_name] = StudentGrade{student_name, grade};
}

StudentGrade* GradeManager::findStudentGrade(const std::string& student_name) {
    if (auto it = grade_by_student_name.find(student_name);
        it != grade_by_student_name.end()) {
        return &it->second;
    } else {
        return nullptr;
    }
}
