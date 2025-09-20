#include "ScalarConverter.hpp"
#include "Utils.hpp"

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &other){ (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){ (void)other; return (*this); }

void ScalarConverter::convert(const std::string& str)
{
    Ltype type = getType(str);

    if (type == CHAR)
        convertToChar(str[1]);
    else if(type == INT)
        convertToInt(str);
    else if(type == FLOAT)
        convertToFloat(str);
    else if(type == DOUBLE)
        convertToDouble(str);
    else if(type == PSEUDO)
        convertToPseudo(str);
    else
        std::cout << "invalid input" << std::endl;
}
