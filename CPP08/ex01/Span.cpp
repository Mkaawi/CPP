#include "Span.hpp"

Span::Span(unsigned int N) : size(N) {}
Span::Span(const Span &other)
{
	*this = other;
}
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		size = other.size;
		nums = other.nums;
	}
}
Span::~Span() {}

void Span::addNumber(int num)
{
	if (nums.size() >= size)
		throw std::length_error("Span is full");
	nums.push_back(num);
}

int Span::shortestSpan() const
{
	
}
int Span::longestSpan() const
{

}