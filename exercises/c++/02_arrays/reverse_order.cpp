#include <iostream>

// Function declaration
// template <typename T>
// double* allocate_array(const T n);

template <typename T>
void print_array(T* a, std::size_t n) {
    for(std::size_t i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

// Function definition
template <typename T>
double* allocate_array(const T n) {
    return new double[n]{};
}

template<typename T>
void print_reverse(T* data, std::size_t n) {
    for(std::size_t i{1}; i<=n; i++) {
        std::cout << data[n-i] << "\n";
    }
}

int main() {
    std::string line;
    std::size_t n;

    std::cin >> n;
    double* data = allocate_array(n);
    
    std::cout << "Inserisci gli elementi" << std::endl;
    for(std::size_t i{0}; i<n; i++) {
        std::cin >> data[i];
    }

    print_reverse(data, n);
    
    delete[] data;

    return 0;
}