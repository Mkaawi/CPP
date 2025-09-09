#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool is_signed;
    const int grade_to_sign;
    const int grade_to_execute;
public:
    AForm();
    AForm(std::string name, bool is_signed, int grade_to_sign, int grade_to_execute);
    virtual ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    std::string getName() const { return name; }
    bool getIsSigned() const { return is_signed; }
    int getGradeToSign() const { return grade_to_sign; }
    int getGradeToExecute() const { return grade_to_execute; }

    void beSigned(const Bureaucrat &b);

    virtual void execute(const Bureaucrat &executor) const = 0;

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
    class FormNotSignedException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Form is not signed!";
        }
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
