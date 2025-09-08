#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
}

AForm::AForm(std::string name, bool is_signed, int grade_to_sign, int grade_to_execute)
    : name(name), is_signed(is_signed), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_execute > 150)
        throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : name(other.name), is_signed(other.is_signed),
                                grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
    os << "Form " << f.getName() << ", is signed: " << (f.getIsSigned() ? "yes" : "no") << ", grade required to sign: " 
                                        << f.getGradeToSign() << ", grade required to execute: " << f.getGradeToExecute();
    return os;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > this->grade_to_sign)
        throw GradeTooLowException();
    this->is_signed = true;
}