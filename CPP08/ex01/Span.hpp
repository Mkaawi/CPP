#pragma once

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

class Span
{
    private:
        unsigned int size;
        std::vector<int> nums;
    public:
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int num);

        template<typename iter>
        void Span::addRange(iter begin, iter end);

        int shortestSpan() const;
        int longestSpan() const;
};

template<typename iter>
void Span::addRange(iter begin, iter end)
{
    while (begin++ != end)
        addNumber(*begin);
}