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

AForm *makeShrubberyCreation(const std::string &target) {
    return (new ShrubberyCreationForm(target));
}

AForm *makeRobotomyRequest(const std::string &target) {
    return (new RobotomyRequestForm(target));
}

AForm *makePresidentialPardon(const std::string &target) {
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) 
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    typedef AForm* (*functions)(const std::string &target);
    
    functions ptr[] = {
        &makeShrubberyCreation,
        &makeRobotomyRequest,
        &makePresidentialPardon
    };

    for (int i = 0; i < 3 ; i++) 
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formNames[i] << std::endl;
            return ptr[i](target);
        }
    }
    throw InvalidFormNameException();
}