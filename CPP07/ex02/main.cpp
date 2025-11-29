#include "Array.hpp"
#include <iostream>

int main ()
{
    Array<int> arr(3);
    arr[0] = 55;
    arr[1] = 69;
    arr[3] = 80;

    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

}