#include "Array.hpp"
#include <iostream>

int main ()
{
    Array<int> arr(3);
    arr[0] = 54;
    arr[1] = 69;
    arr[2] = 80;

    for (unsigned int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;

    Array<int>arr2(arr);
    arr2[0] = 888;
    std::cout << "arr1 - OG : " << arr[0] << std::endl;
    std::cout << "arr2 - copy : " << arr2[0] << std::endl;
    std::cout << std::endl;

    Array<int>arr3;
    arr3 = arr;

    std::cout << "arr1[2] : " << arr[2] << std::endl;
    std::cout << "arr3[2] : " << arr2[2] << std::endl;
    std::cout << "arr3 size : " << arr2.size() << std::endl << std::endl;

    Array<std::string> stringArr(4);
    stringArr[0] = "hello";
    stringArr[1] = "im under water";
    stringArr[2] = "pls help";
    stringArr[2] = "eeeeeeeeeee";

    for (unsigned int i = 0; i < stringArr.size(); i++)
        std::cout << stringArr[i] << " ";
    std::cout << std::endl;


    Array<float> empty;
    std::cout << "empty array size : " << empty.size() << std::endl;

}