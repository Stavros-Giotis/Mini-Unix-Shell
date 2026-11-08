#include "iostream"
#include "string"

int main(){
    std::string input;
    while(input != "exit") {
        std::cout<<"mini-shell $" ;
        std::getline(std::cin,input);
        if(input == "exit") {
            std::cout<<"Goodbye"<<std::endl;    
            return 0;
        }else {
            std::cout << input <<std::endl;
        }
    }  
}