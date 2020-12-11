#include <iostream>

template <typename T>
class vector {
    T* elem;
    std::size_t size_;

    // Constructor
    public:
    vector(const std::size_t size) : 
    elem{new T[size]},
    size_{size} {}
    
    // Destructor
    ~vector() { delete[] elem; }

    std::size_t size() const { return size_; }
    
    T& operator [](const std::size_t i) { return elem[i]; }

    const T& operator [](const std::size_t i) const { return elem[i]; }

    void fill(T a) {
        for (auto i = 0u; i<size_; i++) {
            elem[i] = a;
        }
    }

    vector<T> operator *(const vector<T>& b) {
        vector<double> c{this->size_};
        for (auto i = 0u; i<this->size_; i++) {
            c[i] = this->elem[i] * b[i];
        }

        return c;
    }

    vector<T> operator +(const vector<T>& b) {
        vector<double> c{this->size_};
        for (auto i = 0u; i<this->size_; i++) {
            c[i] = (this->elem)[i] + b[i];
        }

        return c;
    }

};


template <typename T>
std::ostream& operator <<(std::ostream& os, const vector<T>& v) {
    for (auto i = 0u; i<v.size(); i++) {
        os << v[i] << " ";
    }

    return os;
}

int main() {

    vector<double> v{10};

    v.fill(43.12);

    std::cout << v << std::endl;

    v[4] = 532.2;
    std::cout << v+v*v << std::endl;

    return 0;
}