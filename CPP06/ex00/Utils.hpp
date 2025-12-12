#pragma once

#include "ScalarConverter.hpp"

enum Ltype
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    PSEUDO,
    INVALID
};

void convertToChar(const char& c);
void convertToInt(const std::string& str);
void convertToFloat(const std::string& str);
void convertToDouble(const std::string& str);
void convertToPseudo(const std::string& str);
void AllImpossible();

Ltype getType(const std::string& str);
