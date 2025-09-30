#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data og;
    og.nb = 5;
    og.str = "biologica";

    std::cout << "OG : " << &og << " / number : " << og.nb << " / string : " << og.str << std::endl;

    uintptr_t serialized = Serializer::serialize(&og);
    std::cout << "serialized : " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);

    std::cout << "deserialized : " << deserialized << " / number : " << og.nb << " / string : " << og.str << std::endl;

}