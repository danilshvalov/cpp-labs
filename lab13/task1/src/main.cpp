#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class human {
   public:
    human(std::string last_name, std::string name, std::string second_name) {
        this->last_name = last_name;
        this->name = name;
        this->second_name = second_name;
    }

    virtual std::string get_full_name() {
        std::ostringstream full_name;
        full_name << this->last_name << " " << this->name << " "
                  << this->second_name;
        return full_name.str();
    }

   private:
    std::string name;
    std::string last_name;
    std::string second_name;
};

class student : public human {
   public:
    student(
        std::string last_name,
        std::string name,
        std::string second_name,
        std::vector<int> scores
    )
        : human(last_name, name, second_name) {
        this->scores = scores;
    }

    virtual float get_average_score() {
        unsigned int count_scores = this->scores.size();
        unsigned int sum_scores = 0;
        float average_score;
        for (unsigned int i = 0; i < count_scores; ++i) {
            sum_scores += this->scores[i];
        }
        average_score = (float)sum_scores / (float)count_scores;
        return average_score;
    }

   private:
    std::vector<int> scores;
};

class teacher : public human {
   public:
    teacher(
        std::string last_name,
        std::string name,
        std::string second_name,
        unsigned int work_time
    )
        : human(last_name, name, second_name) {
        this->work_time = work_time;
    }

    virtual unsigned int get_work_time() {
        return this->work_time;
    }

   private:
    unsigned int work_time;
};

int main() {
    std::vector<int> scores;
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(4);
    scores.push_back(4);
    scores.push_back(5);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);
    scores.push_back(3);

    student* stud = new student("Петров", "Иван", "Алексеевич", scores);

    std::cout << stud->get_full_name() << std::endl;
    std::cout << "Средний балл : " << stud->get_average_score() << std::endl;

    unsigned int teacher_work_time = 40;
    teacher* tch =
        new teacher("Сергеев", "Дмитрий", "Сергеевич", teacher_work_time);

    std::cout << tch->get_full_name() << std::endl;
    std::cout << "Количество часов: " << tch->get_work_time() << std::endl;
}
