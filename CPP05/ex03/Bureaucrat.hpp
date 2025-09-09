#pragma once

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat
{
private:
    const std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    std::string getName() const { return name; }
    int getGrade() const { return grade; }

    void decrementGrade();
    void incrementGrade();
    void signForm(AForm &f) const;
    void executeForm(const AForm& form) const;

    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade is too high!";
        }
    };
    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw() {
            return "Grade is too low!";
        }
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat& p);
