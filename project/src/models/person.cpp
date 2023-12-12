#include "models/person.hpp"

#include "utils.hpp"

std::string to_string(PersonType type) {
    switch (type) {
        case PersonType::kPerson:
            return "person";
        case PersonType::kStudent:
            return "student";
        case PersonType::kProfessor:
            return "professor";
    }
}

Person::Person(Id id, std::string first_name, std::string last_name)
    : id_(std::move(id)),
      first_name_(std::move(first_name)),
      last_name_(std::move(last_name)) {}

PersonType Person::GetType() const {
    return PersonType::kPerson;
}

nlohmann::json Person::ToJson() const {
    return nlohmann::json(*this);
}

const Person::Id& Person::GetId() const {
    return id_;
}

const std::string& Person::GetFirstName() const {
    return first_name_;
}

const std::string& Person::GetLastName() const {
    return last_name_;
}

Person::Id Person::GenerateId() {
    return uuids::to_string(GenerateUuid());
}
