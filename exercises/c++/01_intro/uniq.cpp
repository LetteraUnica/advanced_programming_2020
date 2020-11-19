#include <iostream>
#include <string>

int main(){
    // Read from stdin
    int rep = 1;
    std::string previous_line;
    std::getline(std::cin, previous_line);

    for(std::string line; std::getline(std::cin, line);) {
        if (previous_line != line) {
            std::cout << rep << " " << previous_line << std::endl;
            rep = 1;
        } else {
            rep++;
        }
        previous_line = line;
    }
    std::cout << rep << " " << previous_line << std::endl;
}