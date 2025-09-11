#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern intern;
        Bureaucrat abbas("abbas", 3);
        Bureaucrat bo9al("bo9al", 1);
        // ShrubberyCreationForm tree("bush");
        RobotomyRequestForm robot("robot");
        PresidentialPardonForm pardon("pardon");
        // bo9al.signForm(tree);
        bo9al.signForm(robot);
        bo9al.signForm(pardon);
        // bo9al.executeForm(tree);
        bo9al.executeForm(robot);
        bo9al.executeForm(pardon);
        std::cout << bo9al << std::endl;
        AForm *form = intern.makeForm("shrubbery creation", "berry");
        abbas.signForm(*form);
        abbas.executeForm(*form);

    }

    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}