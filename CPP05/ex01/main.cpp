#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // Test 1: Successful signing
    try
    {
        Bureaucrat boss("CEO", 1);
        Form importantDoc("Mega Contract", false, 1, 1); // Fixed

        std::cout << boss << std::endl;
        std::cout << importantDoc << std::endl;

        boss.signForm(importantDoc);            // This should work
        std::cout << importantDoc << std::endl; // Check that it's now signed
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n---\n"
              << std::endl;

    // (grade too low)
    try
    {
        Bureaucrat intern("Tim", 150);
        Form secretPlan("World Domination Plan", false, 1, 1); // Fixed

        std::cout << intern << std::endl;
        std::cout << secretPlan << std::endl;

        intern.signForm(secretPlan); // This should fail
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n---\n"
              << std::endl;

    // Test 3: Instantiating a Form with invalid grades
    try
    {
        Form invalidForm("Invalid", false, 0, 160); // Fixed
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}