#include "my_string.h"

// g++ main.cc my_string.cc -o test_my_string
int main(int argc, char* argv[]) {
    String my_str = "aaa";
    my_str += "bbb";
    std::cout << my_str;

}