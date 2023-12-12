#pragma once

#include "models/person.hpp"
#include "models/professor.hpp"
#include "models/student.hpp"

#include <nlohmann/json.hpp>

#include <fstream>
#include <memory>
#include <string>
#include <unordered_map>

class PersonDatabase {
   public:
    void Read(std::istream& in);

    void ReadFromFile(const std::string& filename);

    void Write(std::ostream& out);

    void WriteToFile(const std::string& filename);

    void AddPerson(std::shared_ptr<Person> person);

    void PrettyPrint(std::ostream& out);

    template <typename T, typename... Args>
    void Add(Args&&... args) {
        auto person = std::make_shared<T>(std::forward<Args>(args)...);
        persons_[person->GetId()] = std::move(person);
    }

   private:
    std::unordered_map<Person::Id, std::shared_ptr<Person>> persons_;
};

namespace nlohmann {
template <>
struct adl_serializer<std::shared_ptr<Person>> {
    template <typename T>
    static std::shared_ptr<Person> MakePerson(const json& data) {
        return std::make_shared<T>(data.get<T>());
    }

    static std::shared_ptr<Person> from_json(const json& data) {
        auto type = data["type"].get<PersonType>();
        switch (type) {
            case PersonType::kPerson:
                return MakePerson<Person>(data);
            case PersonType::kStudent:
                return MakePerson<Student>(data);
            case PersonType::kProfessor:
                return MakePerson<Professor>(data);
        }
        return std::make_shared<Person>(data.get<Person>());
    }

    static void to_json(json& data, const std::shared_ptr<Person>& p) {
        data = p->ToJson();
    }
};
}  // namespace nlohmann
