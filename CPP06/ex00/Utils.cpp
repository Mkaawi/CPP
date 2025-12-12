#include "Utils.hpp"
#include <iomanip>

bool isPseudo(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff")
        return 1;
    return 0;
}

void AllImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

bool parseFloat(const std::string &str, float &res)
{
    char *endptr;
    float tmp = std::strtof(str.c_str(), &endptr);
    std::string remaining(endptr);
    if (*endptr != '\0' && remaining != "f" && remaining != "F")
        return (false);
    res = tmp;
    return (true);
}

bool parseDouble(const std::string &str, double &res)
{
    char *endptr;
    double tmp = strtod(str.c_str(), &endptr);
    if (*endptr != '\0')
        return (false);
    res = tmp;
    return (true);
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
    double res;
    if (parseDouble(str, res))
    {
        if (res < INT_MIN || res > INT_MAX)
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << std::fixed << std::setprecision(1) 
                      << static_cast<float>(res) << "f" << std::endl;
            std::cout << "double: " << res << std::endl;
            return;
        }
        std::cout << "int: " << res << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) 
                  << static_cast<float>(res) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(res) << std::endl;
    }
    else
    {
        AllImpossible();
    }
}

void convertToFloat(const std::string &str)
{
    float res;
    if (parseFloat(str, res))
    {
        if (!isprint(res))
            std::cout << "Char : Non Displayable" << std::endl;
        else
            std::cout << "Char: '" << static_cast<char>(res) << "'" << std::endl;
        if (res > INT_MAX || res < INT_MIN)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(res) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << res << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(res) << std::endl;
    }
    else
        AllImpossible();
}

void convertToDouble(const std::string &str)
{
    double res;
    if (parseDouble(str, res))
    {
        if (!isprint(res))
            std::cout << "Char : Non Displayable" << std::endl;
        else
            std::cout << "Char: '" << static_cast<char>(res) << "'" << std::endl;
        if (res > INT_MAX || res < INT_MIN)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(res) << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) << res << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(res) << std::endl;
    }
    else
        AllImpossible();
}

void convertToPseudo(const std::string &str)
{
    std::string fVal, dVal;
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (str == "nan" || str == "nanf")
    {
        fVal = "nanf";
        dVal = "nan";
    }
    else if (str == "+inf" || str == "+inff")
    {
        fVal = "+inff";
        dVal = "+inf";
    }
    else if (str == "-inf" || str == "-inff")
    {
        fVal = "-inff";
        dVal = "-inf";
    }
    std::cout << "float: " << fVal << std::endl;
    std::cout << "double: " << dVal << std::endl;
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
