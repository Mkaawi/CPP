#include "Span.hpp"

int main()
{
    Span sp(5);

    sp.addNumber(15);
    sp.addNumber(1);
    sp.addNumber(6);
    sp.addNumber(22);
    sp.addNumber(3);

    std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
    std::cout << "longest span : " << sp.longestSpan() << std::endl;

    Span sp2(25);

    
    std::vector<int> nums;
    nums.push_back(50);
    for (int i = 6; i <= 25; i++)
        nums.push_back(i);

    sp2.addRange(nums.begin(), nums.end());
    std::cout << std::endl << "Shortest span : " << sp2.shortestSpan() << std::endl;
    std::cout << "longest span : " << sp2.longestSpan() << std::endl;
}