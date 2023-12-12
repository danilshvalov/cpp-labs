#pragma once

#include "commands.hpp"

#include <iostream>
#include <memory>

class Menu {
   public:
    void AddCommand(std::unique_ptr<Command> command);

    void Attach(std::istream& in, std::ostream& out);

   private:
    void AddHelpCommand();

    void AddDefaultCommands();

    std::unordered_map<std::string, std::unique_ptr<Command>> commands_;
};

Menu CreateDefaultMenu(PersonDatabase& db);
