#include "input_helper.hpp"
#include <iostream>
#include <sstream>

std::vector<std::string> stringP(std::string input) {
    std::stringstream ss(input);
    std::string word;

    std::vector<std::string> words;
    while (std::getline(ss, word, ' ')) {
        if (!word.empty()) {
            words.push_back(word);
        }
    }

    std::cout << "Vector contents:\n";
    for (size_t i = 0; i < words.size(); ++i) {
        std::cout << "[" << i << "] " << words[i] << std::endl;
    }
    return words;
}
