#pragma once

#include <nlohmann/json.hpp>

#include <string>

using Money = double;

enum class PersonType {
    kPerson,
    kStudent,
    kProfessor,
};

std::string to_string(PersonType type);

NLOHMANN_JSON_SERIALIZE_ENUM(
    PersonType,
    {
        {PersonType::kPerson, "person"},
        {PersonType::kStudent, "student"},
        {PersonType::kProfessor, "professor"},
    }
)

class Person {
   public:
    using Id = std::string;

    explicit Person(Id id, std::string first_name, std::string last_name);

    virtual PersonType GetType() const;

    virtual nlohmann::json ToJson() const;

    virtual ~Person() = default;

    const Id& GetId() const;

    const std::string& GetFirstName() const;

    const std::string& GetLastName() const;

    static Id GenerateId();

   private:
    Id id_;
    std::string first_name_;
    std::string last_name_;
};

namespace nlohmann {
template <>
struct adl_serializer<Person> {
    static Person from_json(const json& data) {
        return Person{
            data.at("id").get<Person::Id>(),
            data.at("first_name").get<std::string>(),
            data.at("last_name").get<std::string>(),
        };
    }

    static void to_json(json& data, const Person& p) {
        data = json{
            {"id", p.GetId()},
            {"type", p.GetType()},
            {"first_name", p.GetFirstName()},
            {"last_name", p.GetLastName()}
        };
    }
};
}  // namespace nlohmann
