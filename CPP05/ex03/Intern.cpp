#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cctype>

Intern::Intern()
{
}
Intern::Intern(const Intern &other)
{
    (void)other;
}
Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}
Intern::~Intern()
{
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) 
{
    if (formName == "ShrubberyCreationForm") 
    {
        AForm* form = new ShrubberyCreationForm(target);
        std::cout << "Intern creates " << form->getName() << std::endl;
        return form;
    }

    else if (formName == "RobotomyRequestForm") 
    {
        AForm* form = new RobotomyRequestForm(target);
        std::cout << "Intern creates " << form->getName() << std::endl;
        return form;
    }
    
    else if (formName == "PresidentialPardonForm") 
    {
        AForm* form = new PresidentialPardonForm(target);
        std::cout << "Intern creates " << form->getName() << std::endl;
        return form;
    }
    else
        throw InvalidFormNameException();
}