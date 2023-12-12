#include "commands.hpp"

DatabaseReadCommand::DatabaseReadCommand(PersonDatabase& db) : db_(db) {}

const std::string& DatabaseReadCommand::GetName() const {
    return kName;
}

const std::string& DatabaseReadCommand::GetDescription() const {
    return kDescription;
}

void DatabaseReadCommand::Execute(std::istream& in, std::ostream& out) {
    out << "Enter database file: ";
    std::string filename;
    in >> filename;
    db_.ReadFromFile(filename);
    out << "Database successfully read" << std::endl;
}

DatabaseWriteCommand::DatabaseWriteCommand(PersonDatabase& db) : db_(db) {}

const std::string& DatabaseWriteCommand::GetName() const {
    return kName;
}

const std::string& DatabaseWriteCommand::GetDescription() const {
    return kDescription;
}

void DatabaseWriteCommand::Execute(std::istream& in, std::ostream& out) {
    out << "Enter database file: ";
    std::string filename;
    in >> filename;
    db_.WriteToFile(filename);
    out << "Database successfully wrote" << std::endl;
}

DatabaseInspectCommand::DatabaseInspectCommand(PersonDatabase& db) : db_(db) {}

const std::string& DatabaseInspectCommand::GetName() const {
    return kName;
}

const std::string& DatabaseInspectCommand::GetDescription() const {
    return kDescription;
}

void DatabaseInspectCommand::Execute(std::istream& in, std::ostream& out) {
    out << "Database:" << std::endl;
    db_.Write(out);
    out << std::endl;
}

AddPersonCommand::AddPersonCommand(PersonDatabase& db) : db_(db) {}

const std::string& AddPersonCommand::GetName() const {
    return kName;
}

const std::string& AddPersonCommand::GetDescription() const {
    return kDescription;
}

void AddPersonCommand::Execute(std::istream& in, std::ostream& out) {
    out << "Enter first name: ";
    std::string first_name;
    in >> first_name;

    out << "Enter last name: ";
    std::string last_name;
    in >> last_name;

    db_.Add<Person>(
        Person::GenerateId(), std::move(first_name), std::move(last_name)
    );
    out << "Person successfully added" << std::endl;
}

HelpCommand::HelpCommand(std::vector<CommandInfo> commands_info)
    : commands_info_(std::move(commands_info)) {
    commands_info_.push_back(CommandInfo{GetName(), GetDescription()});
    std::sort(
        commands_info_.begin(),
        commands_info_.end(),
        [](const CommandInfo& lhs, const CommandInfo& rhs) {
        return lhs.name < rhs.name;
    }
    );
}
const std::string& HelpCommand::GetName() const {
    return kName;
}

const std::string& HelpCommand::GetDescription() const {
    return kDescription;
}

void HelpCommand::Execute(std::istream& in, std::ostream& out) {
    const size_t max_command_name = GetMaxCommandName();
    for (const auto& info : commands_info_) {
        out << info.name << std::setw(max_command_name - info.name.size() + 2)
            << ' ' << info.description << std::endl;
    }
}

size_t HelpCommand::GetMaxCommandName() const {
    size_t max_command_name = 0;
    for (const auto& info : commands_info_) {
        max_command_name = std::max(max_command_name, info.name.size());
    }
    return max_command_name;
}

const std::string& QuitCommand::GetName() const {
    return kName;
}

const std::string& QuitCommand::GetDescription() const {
    return kDescription;
}

void QuitCommand::Execute(std::istream& in, std::ostream& out) {
    out << "Goodbye!" << std::endl;
    throw QuitCommandException();
}

AddStudentCommand::AddStudentCommand(PersonDatabase& db) : db_(db) {}

const std::string& AddStudentCommand::GetName() const {
    return kName;
}

const std::string& AddStudentCommand::GetDescription() const {
    return kDescription;
}

void AddStudentCommand::Execute(std::istream& in, std::ostream& out) {
    out << "Enter first name: ";
    std::string first_name;
    in >> first_name;

    out << "Enter last name: ";
    std::string last_name;
    in >> last_name;

    out << "Enter group number: ";
    std::string group;
    in >> group;

    out << "Enter scholarship: ";
    Money scholarship;
    in >> scholarship;

    db_.Add<Student>(
        Person::GenerateId(),
        std::move(first_name),
        std::move(last_name),
        std::move(group),
        scholarship
    );
    out << "Student successfully added" << std::endl;
}

DatabasePrettyPrintCommand::DatabasePrettyPrintCommand(PersonDatabase& db)
    : db_(db) {}

const std::string& DatabasePrettyPrintCommand::GetName() const {
    return kName;
}

const std::string& DatabasePrettyPrintCommand::GetDescription() const {
    return kDescription;
}

void DatabasePrettyPrintCommand::Execute(std::istream& in, std::ostream& out) {
    db_.PrettyPrint(out);
}

AddProfessorCommand::AddProfessorCommand(PersonDatabase& db) : db_(db) {}
const std::string& AddProfessorCommand::GetName() const {
    return kName;
}

const std::string& AddProfessorCommand::GetDescription() const {
    return kDescription;
}

void AddProfessorCommand::Execute(std::istream& in, std::ostream& out) {
    out << "Enter first name: ";
    std::string first_name;
    in >> first_name;

    out << "Enter last name: ";
    std::string last_name;
    in >> last_name;

    out << "Enter salary: ";
    Money salary;
    in >> salary;

    db_.Add<Professor>(
        Person::GenerateId(),
        std::move(first_name),
        std::move(last_name),
        salary
    );
    out << "Professor successfully added" << std::endl;
}
