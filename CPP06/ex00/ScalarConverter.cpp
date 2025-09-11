#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(std::string input) : input(input)
{
}

ScalarConverter::ScalarConverter() : input("")
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other) : input(other.input)
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    if (this != &other)
        this->input = other.input;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const ScalarConverter &p)
{
    os << "Input: " << p.getInput();
    return os;
}