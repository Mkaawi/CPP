#pragma once

#include <exception>

template <typename T>
class Array
{
private:
    T *data;
    unsigned int len;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T &operator[](unsigned int index)
    {
        if (index >= len)
            throw std::exception();
        return data[index];
    }

    unsigned int size() const
    {
        return len;
    }
};

template <typename T>
Array<T>::Array() : data(NULL), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), len(n) {}

template <typename T>
Array<T>::Array(const Array &other) : data(new T[other.len]()), len(other.len)
{
    *this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] data;
        len = other.len;
        data = new T[len]();
        for (unsigned int i = 0; i < len; i++)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}
