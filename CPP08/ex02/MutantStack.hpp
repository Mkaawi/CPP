#pragma once

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    public :
        typedef typename std::stack<T>::container_type::iterator iter;
        typedef typename std::stack<T>::container_type::const_iterator const_iter;

        iter begin()
        {
            return this->c.begin();
        }
        iter end()
        {
            return this->c.end();
        }
        iter begin() const
        {
            return this->c.begin();
        }
        iter end() const
        {
            return this->c.end();
        }
};