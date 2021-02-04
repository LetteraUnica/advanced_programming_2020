#include <iostream>

template <typename T>
class Linked_list {
    struct node {
        T elem;
        node* next;
    };

    node* head;
    unsigned int length;

public:
    Linked_list() :
        head{nullptr},
        length{0}{}

    ~Linked_list() = default;

    void add(const T elem, const unsigned int pos);
    void remove(const unsigned int n);
    void append(const T elem);
    unsigned int get_length() const {
        return length;
    }

    void print_list() const {
        node* current_node = head;
        while(current_node->next != nullptr) {
            std::cout << current_node->elem << " ";
            current_node = current_node->next;
        }
        std::cout << current_node->elem << std::endl;
    }
};

template <typename T>
void Linked_list<T>::append(const T elem) {
    node* new_node = new node();
    new_node->elem = elem;
    new_node->next = nullptr;
    if (head != nullptr) {
        node* current_node = head;
        while(current_node->next != nullptr) {
            current_node = current_node->next;
        }
        
        current_node->next = new_node;
    }
    else
    {
        head = new_node;
    }
    length++;
}

template <typename T>
void Linked_list<T>::add(const T elem, const unsigned int pos) {
    if (pos > length) {
        std::cout << "Error can't insert element in position " << pos <<
        " to a list of lenght " << length << std::endl;
    }
    else if (pos==length)
    {
        append(elem);
    }
    else
    {
        node* new_node = new node();
        new_node->elem = elem;
        new_node->next = nullptr;
        node* temp;
        if (pos==0) {
            temp = head;
            head = new_node;
            new_node->next = temp;
            temp = nullptr;
        }
        else {
            node* current_node = head;
            for(auto i=1u; i<pos; i++) {
                current_node = current_node->next;
            }
            temp = current_node->next;
            current_node->next = new_node;
            new_node->next = temp;
            temp = nullptr;
        }
        length++;
    }
}


int main() {

    Linked_list<double> my_list = Linked_list<double>();

    my_list.append(1);
    my_list.append(2);
    my_list.append(4);
    my_list.append(5);
    my_list.print_list();
    my_list.add(0,0);
    my_list.print_list();
    my_list.add(3,3);
    my_list.print_list();
    return 0;
}