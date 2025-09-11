#pragma once

#include <iostream>

class ScalarConverter
{
private:
    std::string input;
public:
    ScalarConverter();
    ScalarConverter(std::string input);
    ~ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    std::string getInput() const { return input; }
};

std::ostream &operator<<(std::ostream &os, const ScalarConverter &p);

