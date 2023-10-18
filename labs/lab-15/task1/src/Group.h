#pragma once

#include <algorithm>
#include <set>
#include <string>

#include "Student.h"

using namespace std;

class Group {
   private:
    string name;
    multiset<Student*, compareStudent> masSt;
    multiset<Student*, compareStudent>::iterator iter;

   public:
    Group(string name);
    Group();

    void setName(string newName);
    string getName();
    int getSize();
    void addStudent(Student* newStudent);
    void delStudent(Student* oldStudent);
    Student* findStudent(string searchName, string searchLastName);
    void GroupSort();
    void GroupOut();
};
