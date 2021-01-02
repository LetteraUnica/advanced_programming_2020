#include <iostream>


namespace nested {
    int a;
    
    namespace hello {

        void hello1();
        void hello2();
        void hello3();
    }
}


using namespace std; // now I can access the std methods directly

int main(int argc, char* argv[]) {
    
    cout << "hello world!" << endl;
    return 0;
}

// Various methods to define a function in a namespace
void nested::hello::hello1() {
    std::cout << "hello world 1!" << std::endl;
}

namespace nested {
    namespace hello{
        void hello2() {
        std::cout << "hello world 2!" << std::endl;
        }
    }
}

using namespace nested;

void hello::hello3() {
    std::cout << "hello world 3!" << std::endl;
}