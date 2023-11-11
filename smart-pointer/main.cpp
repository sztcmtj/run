#include "shared_pointer.h"
#include <string>

int main() {
    SharedPointer p1(new std::string("shared_pointer1"));
    std::cout << "-----------------------------------------" << std::endl;
    std::cout << *(p1.get()) << std::endl;
    SharedPointer<std::string> p2;
    p2 = p1;
    std::cout << "ssssss " << !p2 << std::endl;
    p1.release();
    std::cout << "-----------------------------------------" << std::endl;
    SharedPointer p3(new std::string("shared_pointer3"));
    p2 = p3;
}