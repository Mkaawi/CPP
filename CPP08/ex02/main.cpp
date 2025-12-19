#include "MutantStack.hpp"
#include <iostream>

int main()
{
    MutantStack<int> stack;

    stack.push(11);
    stack.push(55);
    stack.push(32);

    std::cout << "top : " << stack.top() << std::endl;
    std::cout << "others : ";
    for (MutantStack<int>::iter i = stack.begin(); i != stack.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl;
}