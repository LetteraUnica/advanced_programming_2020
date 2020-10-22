#include <iostream>
#include <typeinfo>

template <typename T, typename U>

T sum(const T a, const U b);

int main(){
    float f1 = 12.3, f2=13.4;
    int i = 4;
    char c1 = '6', c2 = '0';
    
    std::cout << sum(f1, f2) << '\n'
        << sum(f2,i) << std::endl;
        
    return 0;
}

template <typename T, typename U>
T sum(const T a, const U b) {
    return a + b;
}