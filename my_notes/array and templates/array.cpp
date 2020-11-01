#include <iostream>

int main() {
    // Static arrays
    int ai[4]{1,2,3,4};
    float af[9];

    std::cout << ai << std::endl;

    std::cout << *ai << std::endl;
    
    std::cout << *(ai+1) << std::endl;
    std::cout << ai[1] << std::endl;
    
    return 0;
}