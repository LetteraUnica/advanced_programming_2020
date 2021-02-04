#include <iostream>


enum color {red, yellow, green};

enum class scoped_color{red, yellow, green};


void print_color(const color c) {
    switch (c)
    {
    case red:
        std::cout << "red" << std::endl;
        break;
    case yellow:
        std::cout << "yellow" << std::endl;
        break;
    case green:
        std::cout << "green" << std::endl;
        break;
    
    
    default:
        std::cout << "no color" << std::endl;
        break;
    }
}

void print_color(const scoped_color c) {
    switch (c)
    {
    case scoped_color::red:
        std::cout << "red" << std::endl;
        break;
    case scoped_color::yellow:
        std::cout << "yellow" << std::endl;
        break;
    case scoped_color::green:
        std::cout << "green" << std::endl;
        break;
    
    
    default:
        std::cout << "no color" << std::endl;
        break;
    }
}


int main(int argc, char* argv[]) {
    color c{red};

    std::cout << c << red << std::endl;
    print_color(c);

    scoped_color b{scoped_color::yellow};
    print_color(b);

    return 0;
}