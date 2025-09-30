#include "whatever.hpp"
#include <iostream>

int main ()
{
    int a = 4;
    int b = 5;

    std::string s1 = "hamid";
    std::string s2 = "doban";

    std::cout << "before : a : " << a << "  / b : " << b << std::endl;
    ::swap(a, b);
    std::cout << "after : a : " << a << "  / b : " << b << std::endl;

    std::cout << "min(a, b) : " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) : " << ::max(a, b) << std::endl;
    
    std::cout << "before : s1 : " << s1 << "  / s2 : " << s2 << std::endl;
    ::swap(s1, s2);
    std::cout << "after : s1 : " << s1 << "  / s2 : " << s2 << std::endl;

    std::cout << "min(s1, s2) : " << ::min(s1, s2) << std::endl;
    std::cout << "max(s1, s2) : " << ::max(s1, s2) << std::endl;
}