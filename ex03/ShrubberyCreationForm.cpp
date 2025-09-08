#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", false, 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    
    std::string filename = this->target + "_shruberry";
    std::ofstream outfile(filename.c_str());

    if (outfile.is_open())
    {
        outfile << "           # #### ####\n";
        outfile << "       ### \\/#|### |/####\n";
        outfile << "      ##\\/#/ \\||/##/_/##/_#\n";
        outfile << "    ###  \\/###|/ \\/ # ###\n";
        outfile << "  ##_\\_#\\_\\## | #/###_/_####\n";
        outfile << " ## #### # \\ #| /  #### ##/##\n";
        outfile << "  __#_--###`  |{,###---###-~\n";
        outfile << "            \\ }{\n";
        outfile << "             }}{\n";
        outfile << "             }}{\n";
        outfile << "        ejm  {{}\n";
        outfile << "       , -=-~{ .-^- _\n";
        outfile.close();
        std::cout << "Tree created for " << this->target << std::endl;
    }
    else
        std::cout << "ERROR : Tree can't be created for " << this->target << std::endl;
}