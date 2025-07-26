#include "ScalarConverter.hpp"



char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0;
double ScalarConverter::_double = 0;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter const	&ScalarConverter::operator = (ScalarConverter const &rhs)
{

	if(this != &rhs){
	_char = rhs._char;
	_int = rhs._int;
	_double = rhs._double;
	_float = rhs._float;
	}
	return (*this);
}


void ScalarConverter::convert(std::string &literal)
{
	int decimalCount = 0;

	if (literal.length() == 1 && !isdigit(literal[0])) {
		convertChar(literal);
		return;
	}

	if (literal == "-inff" || literal == "+inff" || literal == "nanf") {
		convertFloat(literal);
		return;
	}

	if (literal == "-inf" || literal == "+inf" || literal == "nan") {
		convertDouble(literal);
		return;
	}

	for (size_t i = 0; i < literal.length(); ++i) {
		if (i == 0 && (literal[i] == '+' || literal[i] == '-')) {
			continue;
		}
		if (literal[i] == '.' && decimalCount == 0) {
			decimalCount++;
			continue;
		}
		if (decimalCount == 1 && i == literal.length() - 1 && literal[i] == 'f' && literal[i - 1] != '.') {
			convertFloat(literal);
			return;
		}
		if (!isdigit(literal[i])) {
			std::cout << "Invalid Input" << std::endl;
			return;
		}
	}

	if (decimalCount == 1) {
		convertDouble(literal);
	} else {
		convertInt(literal);
	}
}


void ScalarConverter::convertFloat(const std::string &literal)
{
    _float = atof(literal.c_str());
    _int = static_cast<int>(_float);
    _double = static_cast<double>(_float);

    // char output
    if (!isascii(_int))	{
        std::cout << "char: impossible" << std::endl;
    } else {
        _char = static_cast<char>(_int);
        if (isprint(_char))
            std::cout << "char: '" << _char << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    // int output
    if (_float > static_cast<float>(INT_MAX) || _float < static_cast<float>(INT_MIN) || std::isnan(_float) || std::isinf(_float))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << _int << std::endl;

    // float output
    if (std::isinf(_float)) {
        std::cout << "float: " << (_float > 0 ? "+inf" : "-inf") << "f" << std::endl;
    } else if (std::isnan(_float)) {
        std::cout << "float: nanf" << std::endl;
    } else {
        std::cout << "float: " << _float << "f" << std::endl;
    }

    // double output
    if (std::isinf(_double)) {
        std::cout << "double: " << (_double > 0 ? "+inf" : "-inf") << std::endl;
    } else if (std::isnan(_double)) {
        std::cout << "double: nan" << std::endl;
    } else {
        std::cout << "double: " << _double << std::endl;
    }
}

void ScalarConverter::convertDouble(const std::string &literal)
{
    _double = atof(literal.c_str());
    _int = static_cast<int>(_double);
    _float = static_cast<float>(_double);

    // char output
    if (!isascii(_int))	{
        std::cout << "char: impossible" << std::endl;
    } else {
        _char = static_cast<char>(_int);
        if (isprint(_char))
            std::cout << "char: '" << _char << "'" << std::endl;
        else
            std::cout << "char: Non displayable"<< std::endl;
    }

    // int output
    if (_double > INT_MAX  || _double < INT_MIN || std::isnan(_double) || std::isinf(_double))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << _int << std::endl;

    // float output
    if (std::isinf(_float)) {
        std::cout << std::fixed << std::setprecision(1)
                  << "float: " << (_float > 0 ? "+inf" : "-inf") << "f" << std::endl;
    } else if (std::isnan(_float)) {
        std::cout << "float: nanf" << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision(1)
                  << "float: " << _float << "f" << std::endl;
    }

    // double output
    if (std::isinf(_double)) {
        std::cout << "double: " << (_double > 0 ? "+inf" : "-inf") << std::endl;
    } else if (std::isnan(_double)) {
        std::cout << "double: nan" << std::endl;
    } else {
        std::cout << "double: " << _double << std::endl;
    }
}


void	ScalarConverter::convertChar(const std::string &rep)	{

	_char = rep[0];
	_int = static_cast<int>(rep[0]);
	_float = static_cast<float>(rep[0]);
	_double = static_cast<double>(rep[0]);

	std::cout << "char: '" << _char<< "'" << std::endl;
	std::cout << "int: " << _int<< std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double<< std::endl;
}

void	ScalarConverter::convertInt(const std::string &rep)	{
	long long tmp = atol(rep.c_str());
	_int= atoi(rep.c_str());
	_double= static_cast<double>(tmp);
	_float= static_cast<float>(tmp);
	if (!isascii(_int))	{
		std::cout << "char: impossible" << std::endl;
	}
	else	{
		_char= static_cast<char>(_int);
		if (isprint(_char))
			std::cout << "char: '" << _char<< "'" << std::endl;
		else
			std::cout << "char: Non Printable" << std::endl;

	}
	if (tmp > INT_MAX  || tmp < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << _float<< "f" << std::endl;
	std::cout << "double: " << _double << std::endl;

}