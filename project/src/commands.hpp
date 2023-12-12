#pragma once

#include "exceptions.hpp"
#include "person_database.hpp"

struct CommandInfo {
    std::string name;
    std::string description;
};

class Command {
   public:
    virtual const std::string& GetName() const = 0;

    virtual const std::string& GetDescription() const = 0;

    virtual void Execute(std::istream& in, std::ostream& out) = 0;

    virtual ~Command() = default;
};

class DatabaseReadCommand : public Command {
   public:
    inline static const std::string kName = "db-read";
    inline static const std::string kDescription =
        "Read person database from file";

    explicit DatabaseReadCommand(PersonDatabase& db);

    const std::string& GetName() const override;

    const std::string& GetDescription() const override;

    void Execute(std::istream& in, std::ostream& out) override;

   private:
    PersonDatabase& db_;
};

class DatabaseWriteCommand : public Command {
   public:
    inline static const std::string kName = "db-write";
    inline static const std::string kDescription =
        "Write person database to file";

    explicit DatabaseWriteCommand(PersonDatabase& db);

    const std::string& GetName() const override;

    const std::string& GetDescription() const override;

    void Execute(std::istream& in, std::ostream& out) override;

   private:
    PersonDatabase& db_;
};

class DatabaseInspectCommand : public Command {
   public:
    inline static const std::string kName = "db-inspect";
    inline static const std::string kDescription =
        "Verbose print person database data";

    explicit DatabaseInspectCommand(PersonDatabase& db);

    const std::string& GetName() const override;

    const std::string& GetDescription() const override;

    void Execute(std::istream& in, std::ostream& out) override;

   private:
    PersonDatabase& db_;
};

class DatabasePrettyPrintCommand : public Command {
   public:
    inline static const std::string kName = "db-pretty";
    inline static const std::string kDescription =
        "Pretty print person database data";

    explicit DatabasePrettyPrintCommand(PersonDatabase& db);

    const std::string& GetName() const override;

    const std::string& GetDescription() const override;

    void Execute(std::istream& in, std::ostream& out) override;

   private:
    PersonDatabase& db_;
};

class AddPersonCommand : public Command {
   public:
    inline static const std::string kName = "add-person";
    inline static const std::string kDescription = "Add person to database";

    explicit AddPersonCommand(PersonDatabase& db);

    const std::string& GetName() const override;

    const std::string& GetDescription() const override;

    void Execute(std::istream& in, std::ostream& out) override;

   private:
    PersonDatabase& db_;
};

class AddStudentCommand : public Command {
   public:
    inline static const std::string kName = "add-student";
    inline static const std::string kDescription = "Add student to database";

    explicit AddStudentCommand(PersonDatabase& db);

    const std::string& GetName() const override;

    const std::string& GetDescription() const override;

    void Execute(std::istream& in, std::ostream& out) override;

   private:
    PersonDatabase& db_;
};

class AddProfessorCommand : public Command {
   public:
    inline static const std::string kName = "add-professor";
    inline static const std::string kDescription = "Add professor to database";

    explicit AddProfessorCommand(PersonDatabase& db);

    const std::string& GetName() const override;

    const std::string& GetDescription() const override;

    void Execute(std::istream& in, std::ostream& out) override;

   private:
    PersonDatabase& db_;
};

class HelpCommand : public Command {
   public:
    inline static const std::string kName = "help";
    inline static const std::string kDescription = "Print help info";

    explicit HelpCommand(std::vector<CommandInfo> commands_info);

    const std::string& GetName() const override;

    const std::string& GetDescription() const override;

    void Execute(std::istream& in, std::ostream& out) override;

   private:
    size_t GetMaxCommandName() const;

    std::vector<CommandInfo> commands_info_;
};

class QuitCommand : public Command {
   public:
    inline static const std::string kName = "quit";
    inline static const std::string kDescription = "Close program";

    const std::string& GetName() const override;

    const std::string& GetDescription() const override;

    void Execute(std::istream& in, std::ostream& out) override;
};
