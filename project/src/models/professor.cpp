#include "models/professor.hpp"

Professor::Professor(
    Id id, std::string first_name, std::string last_name, Money salary
)
    : Person(std::move(id), std::move(first_name), std::move(last_name)),
      salary_(salary) {}

PersonType Professor::GetType() const {
    return PersonType::kProfessor;
}

nlohmann::json Professor::ToJson() const {
    return nlohmann::json(*this);
}

Money Professor::GetSalary() const {
    return salary_;
}

void Professor::SetSalary(Money salary) {
    if (salary < 0) {
        throw std::invalid_argument("Salary cannot be negative");
    }
    salary_ = salary;
}
