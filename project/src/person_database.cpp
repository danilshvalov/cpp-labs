#include "person_database.hpp"

#include <tabulate/table.hpp>

template <typename T>
T OpenFile(const std::string& filename) {
    T file(filename);
    if (!file) {
        throw std::runtime_error("Cannot open " + filename + " file");
    }
    return file;
}

void PersonDatabase::Read(std::istream& in) {
    nlohmann::json data;
    in >> data;
    data.get_to(persons_);
}

void PersonDatabase::ReadFromFile(const std::string& filename) {
    auto file = OpenFile<std::ifstream>(filename);
    Read(file);
}

void PersonDatabase::Write(std::ostream& out) {
    out << nlohmann::json(persons_);
}

void PersonDatabase::WriteToFile(const std::string& filename) {
    auto file = OpenFile<std::ofstream>(filename);
    Write(file);
}

void PersonDatabase::AddPerson(std::shared_ptr<Person> person) {
    assert(person != nullptr);
    persons_[person->GetId()] = std::move(person);
}

void PersonDatabase::PrettyPrint(std::ostream& out) {
    if (persons_.empty()) {
        out << "Database is empty" << std::endl;
        return;
    }

    tabulate::Table table;
    table.add_row({"Id", "Type", "First name", "Last name"});

    for (const auto& [_, person] : persons_) {
        table.add_row({
            person->GetId(),
            to_string(person->GetType()),
            person->GetFirstName(),
            person->GetLastName(),
        });
    }

    table.format().font_align(tabulate::FontAlign::center);

    out << table << std::endl;
}
