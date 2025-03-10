#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>
#include <cmath>
#include <iomanip>
#include <limits.h>
class ScalarConverter
{
	private:
		static int _int;
		static float _float;
		static char _char;
		static double _double;

	public :
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &copy);
		~ScalarConverter(void);
		ScalarConverter const &operator = (ScalarConverter const &rhs);
		static void convert(std::string &literal);
		static void convertString(const std::string &literal);
		static void convertChar(const std::string &literal);
		static void convertFloat(const std::string &literal);
		static void convertInt(const std::string &literal);
		static void convertDouble(const std::string &literal);

};

#endif