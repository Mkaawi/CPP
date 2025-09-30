# pragma once

#include <cstdint>
#include <iostream>

struct Data
{
    int nb;
    std::string str;
};

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer();
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

/*uintptr_t: special unsigned integer type that's guaranteed to be 
large enough to hold any pointer */