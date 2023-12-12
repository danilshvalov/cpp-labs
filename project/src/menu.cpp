#include "menu.hpp"

void Menu::AddCommand(std::unique_ptr<Command> command) {
    commands_[command->GetName()] = std::move(command);
}

void Menu::Attach(std::istream& in, std::ostream& out) {
    AddDefaultCommands();

    out << "Available commands:" << std::endl;
    commands_[HelpCommand::kName]->Execute(in, out);

    while (in) {
        try {
            std::string command_name;
            in >> command_name;
            auto it = commands_.find(command_name);
            if (it == commands_.end()) {
                out << "Unknown command: " << command_name << std::endl;
                continue;
            }

            // remove extra chars from input
            std::string tmp;
            std::getline(in, tmp);

            it->second->Execute(in, out);
        } catch (const QuitCommandException&) {
            break;
        } catch (const std::exception& e) {
            out << "Error: " << e.what() << std::endl;
        }
    }
}

void Menu::AddHelpCommand() {
    std::vector<CommandInfo> commands_info;
    for (const auto& [_, command] : commands_) {
        commands_info.push_back(CommandInfo{
            command->GetName(),
            command->GetDescription(),
        });
    }
    auto command = std::make_unique<HelpCommand>(std::move(commands_info));
    AddCommand(std::move(command));
}

void Menu::AddDefaultCommands() {
    AddCommand(std::make_unique<QuitCommand>());
    AddHelpCommand();
}

Menu CreateDefaultMenu(PersonDatabase& db) {
    Menu menu;
    menu.AddCommand(std::make_unique<DatabaseReadCommand>(db));
    menu.AddCommand(std::make_unique<DatabaseWriteCommand>(db));
    menu.AddCommand(std::make_unique<DatabaseInspectCommand>(db));
    menu.AddCommand(std::make_unique<DatabasePrettyPrintCommand>(db));
    menu.AddCommand(std::make_unique<AddPersonCommand>(db));
    menu.AddCommand(std::make_unique<AddStudentCommand>(db));
    menu.AddCommand(std::make_unique<AddProfessorCommand>(db));
    return menu;
}
