#include <iostream>
#include <memory>
#include <utility>


template <typename T, typename K, typename O>
class bst {

    struct node {
        std::unique_ptr<node> left;
        std::unique_ptr<node> right;
        K key;
        T value;

        // Default constructor
        // I don't want explicit conversion to node
        explicit node(const T& x, const int k): 
            value{x}, 
            key{k} {}

        // Copy costructor
        node(const T& x, const K& k, node* l, node* r):
            value{x}, 
            key{k},
            left{l},
            right{r} {}

        // Destructor
        ~node() noexcept = default;
        
        // Move constructor
        // explicit node(T&& x, const int k): 
        //     value{std::move(x)},
        //     key{std::move(k)}

        // Move
    };

    std::unique_ptr<node> root;
    // std::size_t _size;

    // Add constructors and destructors
    bst() = default;
    
    ~bst() = default;
    // Insert and item in the tree
    void insert(const T& value, const K& key, O less);
};

template <typename T, typename K, typename O>
void bst<T, K, O>::insert(const T& value, const K& key, O less) {
    auto tmp = root.get();
    new_node = new node{value, key};
    
    if (!tmp) {
        // The tree is empty
        root.reset(new_node)
        return;
    }

    while(true) {  
        if(value > tmp->key){
            if(tmp->right.get() == nullptr) {
                tmp->right.reset(new_node)
                break;
            }
            tmp = tmp->right.get()
        }

        else {
            if(tmp->left.get() == nullptr) {
                tmp->left.reset(new_node)
                break;
            }
            tmp = tmp->left.get()
        }
    }
}