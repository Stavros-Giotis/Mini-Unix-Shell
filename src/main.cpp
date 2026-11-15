#include <iostream>
#include <string>
#include "../include/input_helper.hpp"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <vector>

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
            

            
            std::vector<char*>args;
            for(auto& word: words){
                args.push_back(word.data());
            }
            args.push_back(nullptr);
            
            pid_t pid = fork();
            if(pid < 0){
                perror("fork");
                return 1;
            }
            else if(pid == 0){
                if(execvp(args[0], args.data()) == -1) {
                    perror("execvp");
                    _exit(127);
                }
            }
            else {
                waitpid(pid,nullptr,0);
            }
        
        }


        std::cout << "mini-shell $ ";
    }

    std::cout << "Goodbye" << std::endl;    
    return 0;
}