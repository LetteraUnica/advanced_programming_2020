#include <iostream>

template <typename T>
void print_sentinel(const T* a, const std::size_t l);

int main() {
  int a{8}, b{7};
  int* pi{&a};

  const int* pc{&a};
  // *pc = 7; 	// error
  std::cout<<a<<std::endl;  // 7
  std::cout<<*pc<<std::endl;// 7
  a = 15;  // I can obviously change a
  std::cout<<a<<std::endl;  // 15
  std::cout<<*pc<<std::endl;// 15

  int* const cp{&a};
  a = b;    // *cp = 7
  *cp = 33; // a = 33

  // cp = &b;   // error

  const int* const cpc{&a};

  // *cpc = 0;  // error
  // cpc = &n;  // error
  std::cout<<*cpc<<std::endl;
  a = 99;
  std::cout<<*cpc<<std::endl;

  int aa[4]{};
  print_sentinel(aa, 4);

  return 0;
}

template <typename T>
void print_sentinel(const T* a, const std::size_t l) {
  const T* const end{a + l};
  for (; a != end; ++a){
    std::cout << *a << std::endl;
    std::cout << a << std::endl;
  }
  std::cout << end << std::endl;
}
