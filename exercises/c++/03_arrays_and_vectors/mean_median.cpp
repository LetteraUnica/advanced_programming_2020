#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_vector(const std::vector<T> &v) {
    for(const auto& x : v)
        std::cout << x << " ";
    std::cout << std::endl;
}

template <typename T>
double mean(std::vector<T> &v) {
    double sum = 0;
    
    for(auto &x : v)
        sum += x;
    
    return sum/v.size();
}

template <typename T>
double median(std::vector<T> &v) {
    std::sort(v.begin(), v.end());

    int n = v.size();
    if (n%2 == 0)
        return (v[n/2 - 1] + v[n/2]) / 2;

    return v[n/2];
}

int main() {
    std::vector<double> v{};
    for(std::string line; std::getline(std::cin, line);) {
        v.push_back(std::stod(line));
    }

    print_vector(v);
    std::cout << mean(v) << " " << median(v) << std::endl;

    return 0;
}