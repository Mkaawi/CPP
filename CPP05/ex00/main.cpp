#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("abbas", 1);
        Bureaucrat b("msouud", 150);
        
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    
        a.incrementGrade();
        b.decrementGrade();
    
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}