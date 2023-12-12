#include "menu.hpp"
#include "person_database.hpp"

#include <iostream>

int main() {
    PersonDatabase db;
    Menu menu = CreateDefaultMenu(db);
    menu.Attach(std::cin, std::cout);
}
