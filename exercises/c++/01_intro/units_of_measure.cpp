#include <iostream>
#include <string>

bool check_double(std::string line, int pos) {
    bool is_int, is_double;
    is_int = true;
    is_double = true;

    for (int i = 0; i < pos; i++) {
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

    return is_double;
}


int check_input(std::string line, std::string unit) {
    
    int i=0;

    while(line[i]!=' ' && i<line.length()) {
        if(!isdigit(line[i]) && line[i]!='.') {
            return 1;
        }
        i++;
    }

    if(!check_double(line, i)) {
        return 2;
    }
    i++;
    int pos = i;

    if(unit.length() != line.length() - i) {
        return 3;
    }

    while(i<line.length()) {
        if(line[i] != unit[i-pos]) {
            return 4;
        }
        i++;
    }

    return 0;
}

std::string slice(std::string line, std::string cut_value) {
    std::string cut_string;
    int i=0;
    while (i<line.length() || line[i]==cut_value[0]) {
        cut_string[i] = line[i];
        i++;
    }

    return cut_string;
}

int main() {
    std::string line;
    while(std::getline(std::cin, line)) {
        if(check_input(line, "inch")) {
            std::cout << "Syntax error" << std::endl;
            return 1;
        }
        std::cout << std::stod(line)*0.0254 << " m" << std::endl;
    }

    return 0;
}