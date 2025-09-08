# pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    virtual ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    virtual void execute(const Bureaucrat &executor) const;
};