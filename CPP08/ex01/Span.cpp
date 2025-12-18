#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}
Span::Span(const Span &other)
{
	*this = other;
}
Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		maxSize = other.maxSize;
		nums = other.nums;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int num)
{
	if (nums.size() >= maxSize)
		throw std::length_error("Span is full");
	nums.push_back(num);
}

int Span::shortestSpan() const
{
	if (nums.size() < 2)
		throw std::logic_error("not enough members");
	
	std::vector<int> sorted = nums;
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		int j = sorted[i + 1] - sorted[i];
		if (j < shortest)
			shortest = j;
	}
	return shortest;
}
int Span::longestSpan() const
{
	if (nums.size() < 2)
		throw std::logic_error("not enough members");
	
    int max = *std::max_element(nums.begin(), nums.end());
    int min = *std::min_element(nums.begin(), nums.end());
    
    return max - min;
}

unsigned int Span::getMax() const
{
	return maxSize;
}
unsigned int Span::getSize() const
{
	return nums.size();
}
