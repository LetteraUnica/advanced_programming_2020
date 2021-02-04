#include <iostream>
#include <memory>
#include <string>
#include <utility>


namespace my_vector {
    struct Invalid_vector {
        std::string message;
        Invalid_vector(std::string s) : message{std::move(s)} {}
    };

    std::ostream& operator <<(std::ostream& os, const Invalid_vector& s) {
    os << s.message;
    return os;
    }

    template <typename T>
    class vector {
        T* elem;
        unsigned int size_;

        public:

        // Default constructor
        vector(const unsigned int size) {
            size_ = size;

            try {
                elem = new T[size];
            } catch(...) {
                throw Invalid_vector{"Was unable to allocate the vector"};
            }
        }

        // Destructor   
        ~vector() noexcept {
            delete [] elem;
            std::cout << "~Vector\n";
        }

        // Copy constructor
        vector(const vector& v) {
            size_ = v.size_;

            try {
                elem = new T[size_];
            } catch (...) {
                throw Invalid_vector{"Was unable to allocate the vector"};
            }

            std::copy(v.elem, v.elem + size_, elem);
        }

        // Copy assignment
        vector& operator =(vector& v) {

            
            elem.reset();
            auto tmp = v;               // copy the vector
            (*this) = std::move(tmp);   // move the copy in the new vector

            return *this;
        }

        // Move assignment
        vector& operator =(vector&& v) noexcept {
            size_ = std::move(v.size_);
            elem = std::move(v.elem);
            return *this;
        }

        // Move constructor
        vector(vector&&) noexcept = default;

        
        T& operator [](const unsigned int i) noexcept {
            return elem[i];
        }

        const T& operator [](const unsigned int i) const noexcept {
            return elem[i];
        }

        const unsigned int size() const noexcept {
            return size_;
        }

        void fill(const T& value) noexcept {
            for(auto i = 0u; i<size_; i++) {
                elem[i] = value; 
            }
        }
    };

    template <typename T>
    std::ostream& operator <<(std::ostream& os, const vector<T>& v) {
        for(auto i=0u; i<v.size(); i++) {
            os << v[i] << " ";
        }
        return os;
    }
}


int main(int argc, char* argv[]) {
    using namespace my_vector;
    unsigned int size=10;
    
    if(argc > 1) {
        size = std::atoi(argv[1]);
        if (size < 0) {
            std::cout << "The vector size must be positive, size=" << 
            std::to_string(size);
            return 1;
        }
    }


    try {
        vector<double> v{size};
        std::cout << "v = " << v << std::endl;
        vector<double> w{v};
        w.fill(12);
        std::cout << "w = " << w << std::endl;
        std::cout << "v = " << v << std::endl;
        vector<double> z = w;
        z.fill(10);
        std::cout << "w = " << w << std::endl;
        std::cout << "z = " << z << std::endl;
    } catch(const Invalid_vector& s) {
        std::cout << s << std::endl;
    }

    return 0;
}