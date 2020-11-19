#include <iostream>
#include <string>

// Adds the character "c" at position "pos" in the string "line"
void add_char(std::string &line, int pos, char c) {
    for(int i=line.length(); i>pos; i--) {
        line[i] = line[i - 1];
    }
    line[pos] = c;
}

// Finds the last space in the string "line" between "posmin" and "posmax"
int find_last_space(std::string line, int posmin, int posmax){
    int i=posmax;
    while(line[i] != ' ' && i>posmin) {
        i--;
    }
    return i;
}

void cut_line(std::string line) {
    int last_space=0;
    int previous_space=0;

    while((int)line.length() - 80 - last_space > 0) {
        last_space = find_last_space(line, previous_space, previous_space+79);
        if(last_space == previous_space) {
            last_space += 80;
            add_char(line, last_space-1, '\n');
        }
        else {
            line[last_space] = '\n';
        }
        previous_space = last_space;
    }
    std::cout << line << std::endl;
}

int main(){
    std::string line;
    while(std::getline(std::cin, line)){
        cut_line(line);
    }
    return 0;
}