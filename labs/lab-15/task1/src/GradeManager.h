#pragma once

#include <map>
#include <string>

struct StudentGrade {
    std::string student_name;
    char grade;
};

class GradeManager {
   private:
    std::map<std::string, StudentGrade> grade_by_student_name;

   public:
    void addStudentGrade(const std::string& student_name, char grade);

    StudentGrade* findStudentGrade(const std::string& student_name);
};
