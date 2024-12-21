#include "harlFilter.hpp"

int level(std::string str)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < 4; i++)
	{
		if(!str.compare(levels[i]))
			return i;
	}
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