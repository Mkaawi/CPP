#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool is_signed;
    const int grade_to_sign;
    const int grade_to_execute;

public:
    Form();
    Form(std::string name, bool is_signed, int grade_to_sign, int grade_to_execute);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    std::string getName() const { return name; }
    bool getIsSigned() const { return is_signed; }
    int getGradeToSign() const { return grade_to_sign; }
    int getGradeToExecute() const { return grade_to_execute; }
    void beSigned(const Bureaucrat &b);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Grade is too high!";
        }
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Grade is too low!";
        }
    };
};

std::ostream &operator<<(std::ostream &os, const Form &f);
