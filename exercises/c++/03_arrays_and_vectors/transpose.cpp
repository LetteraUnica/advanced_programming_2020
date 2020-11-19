#include <iostream>
#include <array>

template <typename T>
void print_matrix(const T& a, const int row, const int col){
    for (int i = 0; i<row; i++) {
        for (int j = 0; j<col; j++) {
            std::cout << a[i*col + j] << " ";
        }
        std::cout<<std::endl;
    }
}

template <typename T>
void init_matrix(T& a){
    int i = 0;
    for (auto& x : a) {
        x = i;
        i++;
    }
}

template <typename T>
void transpose(T& a, const int row, const int col) {
    if(row==col){
        for (int i = 0; i < row; i++)
            for (int j = 0; j < i; j++)
                std::swap(a[i*col + j], a[j*col + i]);
    }
    else {
        const T b{a};
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                a[j*row + i] = b[i*col + j];
    }
}


int main() {
    const int n = 2;
    const int m = 5;
    std::array<double, n*m> A{};
    init_matrix(A);
    print_matrix(A, n, m);
    transpose(A, n, m);
    print_matrix(A, m, n);

    return 0;
}


