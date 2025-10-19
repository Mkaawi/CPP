# include "iter.hpp"

template<typename T>
void print(T element)
{
    std::cout << element << std::endl;
}

int main ()
{
    std::string charArray[] = {"Hello", "im under watter", "pls help"};
    int intArray[] = {1, 2, 3, 4};

    ::iter(charArray, 3,  print<std::string>);
    ::iter(intArray, 4, print<int>);

}