#pragma once

#include "models/person.hpp"

#include <nlohmann/json.hpp>

#include <string>

class Student : public Person {
   public:
    explicit Student(
        Id id,
        std::string first_name,
        std::string last_name,
        std::string group,
        Money scholarship
    );

    PersonType GetType() const override;

    nlohmann::json ToJson() const override;

    const std::string& GetGroup() const;

    Money GetScholarship() const;

    void SetScholarship(Money scholarship);

   private:
    std::string group_;
    Money scholarship_;
};

namespace nlohmann {
template <>
struct adl_serializer<Student> {
    static Student from_json(const json& data) {
        return Student{
            data.at("id").get<Person::Id>(),
            data.at("first_name").get<std::string>(),
            data.at("last_name").get<std::string>(),
            data.at("group").get<std::string>(),
            data.at("scholarship").get<Money>(),
        };
    }

    static void to_json(json& data, const Student& s) {
        data = static_cast<const Person&>(s);
        data["group"] = s.GetGroup();
        data["scholarship"] = s.GetScholarship();
    }
};
}  // namespace nlohmann
