#include <iostream>
#include <string>

int main() {
    std::string input;
    
    std::cout << "mini-shell $ ";
    while (std::getline(std::cin, input)) {
        if (input == "exit") {
            break;
        }

        if (!input.empty()) {
            std::cout << input << std::endl;
        }

        std::cout << "mini-shell $ ";
    }

    std::cout << "Goodbye" << std::endl;    
    return 0;
}