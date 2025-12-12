#pragma once

#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int val)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), val);
    if (iter == container.end())
        throw std::exception();
    return iter;
}