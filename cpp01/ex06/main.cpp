#include "harlFilter.hpp"

int level(std::string str)
{
	if(str.empty())
		return -2;
	if(str == "DEBUG")
		return DEBUG;
	if(str == "INFO")
		return INFO;
	if(str == "WARNING")
		return WARNING;
	if(str == "ERROR")
		return ERROR;
	return -1;
}



int main(int cmd,char **str)
{
	harlFilter harl;

	if(cmd > 2)
	{
		std::cout << "Can only filter one complaning" << std::endl;
		return 1;
	}
	if(!str[1])
	{
		std::cout << "Emptiness is not a complaint" << std::endl;
		return 1;
	}
	harl.complain(level(str[1]));
	return 0;
}