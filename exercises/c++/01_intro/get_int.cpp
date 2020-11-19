#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string line;
    bool is_int, is_double;

    while(std::cin >> line){
        is_int = true;
        is_double = true;

        for (int i = 0; i < line.length(); i++) {
            if (!isdigit(line[i]) && line[i]!='.') {
                is_double = false;
                is_int = false;
                break;
            }

            // In this case is_int tells whether I already found a '.'
            if (line[i]=='.' && !is_int) {
                is_double = false;
                break;
            }

            if (line[i]=='.') {
                is_int = false;
            }
        }

        if(is_int) 
            std::cout << line << " is a int" << std::endl;
        else if(is_double) 
            std::cout << line << " is a double" << std::endl;
        else 
            std::cout << line << " is a string" << std::endl;
    }
    

    return 0;
}