#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>

class Array
{
private:
    T *elements;
    unsigned int n;
public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
};

