#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

// contructors

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

//methods

void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    else
        grade++;
}

void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    else
        grade--;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat& p)
{
    os << p.getName() << " : " << p.getGrade();
    return(os);
}

