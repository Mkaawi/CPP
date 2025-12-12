#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
    std::vector<int> vect;
    for (int i = 0; i < 10; i++)
        vect.push_back(i);
    try
    {
        std::vector<int>::iterator iter = easyfind(vect, 9);
        std::cout << "found: " << *iter << std::endl;
        vect.push_back(99);
        iter = easyfind(vect, 99);
        std::cout << "found: " << *iter << std::endl;
        iter = easyfind(vect, 955);

    }
    catch(const std::exception& e)
    {
        std::cout << "found nothing" << std::endl;
    }
}