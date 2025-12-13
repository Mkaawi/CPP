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
	if (nums.size() < 2)
		throw std::logic_error("not enough members");
	
	std::vector<int> sorted = nums;
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] = sorted[0];
	for (int i = 0; i < sorted.size(); i++)
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
	
	std::vector<int> sorted = nums;
	std::sort(sorted.begin(), sorted.end());

	int longest = sorted[1] = sorted[0];
	for (int i = 0; i < sorted.size(); i++)
	{
		int j = sorted[i + 1] - sorted[i];
		if (j > longest)
			longest = j;
	}
	return longest;
}