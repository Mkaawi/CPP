#include "ScalarConverter.hpp"
#include "Utils.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

void ScalarConverter::convert(const std::string &str)
{
    Ltype type = getType(str);

    switch (type)
    {
    case CHAR:
        convertToChar(str[1]);
        break;
    case INT:
        convertToInt(str);
        break;
    case FLOAT:
        convertToFloat(str);
        break;
    case DOUBLE:
        convertToDouble(str);
        break;
    case PSEUDO:
        convertToPseudo(str);
        break;
    default:
        AllImpossible();
        break;
    }
}
