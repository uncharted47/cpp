#include "ScalarConverter.hpp"

int main(int cmd, char **str)
{

	if(cmd !=  2)
	{
		std::cerr << "Invalid Input!" << std::endl;
		return (1);
	}
	std::string input = str[1];
	ScalarConverter::convert(input);

	return 0;
}
