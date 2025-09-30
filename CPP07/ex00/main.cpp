#include "whatever.hpp"
#include <iostream>

int main ()
{
    int a = 4;
    int b = 5;

    ::swap(a, b);
    std::cout << "a : " << a << " b : " << b << std::endl;
}