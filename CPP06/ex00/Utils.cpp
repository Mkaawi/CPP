#include "Utils.hpp"

bool isPseudo(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
        return 1;
}

void AllImpossible() 
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

bool parseInt(const std::string &str)
{
    
}

void convertToChar(const char &c)
{
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void convertToInt(const std::string &str)
{
    if (parseInt(str))
    {

    }
    else
        AllImpossible();
}
void convertToFloat(const std::string &str)
{
}
void convertToDouble(const std::string &str)
{
}
void convertToPseudo(const std::string &str)
{
}

Ltype getType(const std::string &str)
{
    size_t i = 0;
    bool gotDot = 0;
    bool gotDigit = 0;
    bool gotF = 0;

    if (str.length() == 3 && str.front() == '\'' && str.back() == '\'')
        return (CHAR);
    if (isPseudo(str))
        return (PSEUDO);
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (i < str.length())
    {
        if (std::isdigit(str[i]))
            gotDigit = 1;
        else if (str[i] == '.' && !gotDot)
            gotDot = 1;
        else if (str[i] == 'f' && i == (str.length() - 1))
            gotF = 1;
        else
            return (INVALID);
        i++;
    }
    if (!gotDigit)
        return (INVALID);
    if (gotF)
        return (FLOAT);
    if (gotDot)
        return (DOUBLE);
    return (INT);
}
