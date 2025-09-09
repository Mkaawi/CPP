#pragma once

#include "AForm.hpp"
#include <string>

class Intern
{
    public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

    class InvalidFormNameException : public std::exception
    {
        public:
            const char* what() const throw()
			{
    	    	return "Invalid form name: form does not exist";
        	}
    };
};