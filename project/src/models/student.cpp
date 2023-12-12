#include "models/student.hpp"

Student::Student(
    Id id,
    std::string first_name,
    std::string last_name,
    std::string group,
    Money scholarship
)
    : Person(std::move(id), std::move(first_name), std::move(last_name)),
      group_(std::move(group)) {
    SetScholarship(scholarship);
}

PersonType Student::GetType() const {
    return PersonType::kStudent;
}

nlohmann::json Student::ToJson() const {
    return nlohmann::json(*this);
}

const std::string& Student::GetGroup() const {
    return group_;
}

Money Student::GetScholarship() const {
    return scholarship_;
}

void Student::SetScholarship(Money scholarship) {
    if (scholarship < 0) {
        throw std::invalid_argument("Scholarship cannot be negative");
    }
    scholarship_ = scholarship;
}
