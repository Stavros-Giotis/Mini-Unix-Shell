#include <iostream>
#include <string>
#include "../include/input_helper.hpp"

int main() {
    std::string input;
    
    std::cout << "mini-shell $ ";
    while (std::getline(std::cin, input)) {
        if (input == "exit") {
            break;
        }

        if (!input.empty()) {
            std::vector<std::string> words = stringP(input);
            std::cout << "Parsed " << words.size() << " arguments.\n";
        }

        std::cout << "mini-shell $ ";
    }

    std::cout << "Goodbye" << std::endl;    
    return 0;
}