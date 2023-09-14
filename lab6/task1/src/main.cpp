#include <fstream>
#include <iostream>

int main() {
    std::cout << "Введите название файла: ";
    std::string filename;
    std::cin >> filename;

    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Не удалось открыть файл \"" << filename << "\""
                  << std::endl;
        return 1;
    }

    std::cout << "Введите текст стихотворения:" << std::endl;

    for (std::string line; std::getline(std::cin, line);) {
        if (!line.empty()) {
            file << line << '\n';
        }
    }

    std::cout << "Ввод завершен" << std::endl;
}
