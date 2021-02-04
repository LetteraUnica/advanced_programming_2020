#include <iostream>
#include <memory>
#include <utility>


template <typename T>
class tree {

    struct node {
        std::unique_ptr<node> left;
        std::unique_ptr<node> right;
        int key;
        T value;

        // Default constructor
        explicit node(const T& x, const int k): 
            value{x}, 
            key{k} {}

        // Copy costructor
        node(const T& x, const int k, node* l, node* r):
            value{x}, 
            key{k},
            left{l},
            right{r} {}

        // Destructor
        ~node() noexcept = default;
        
        // Move constructor
        explicit node(T&& x, const int k): 
            value{std::move(x)},
            key{std::move(k)}

        // Move
    }
};