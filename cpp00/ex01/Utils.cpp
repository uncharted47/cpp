#include "Phonebook.hpp"


int test_number(std::string str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if(std::isdigit(str[i]) == 0)
			return (0);
	}
	return (str.length() > 0 && str.length() < 12 && str.length() > 8);
}



void getline(std::string &string,std::string msg)
{
	if(std::cin.eof())
	{
		std::cout << std::endl;
		std::cout << "EOF detected" <<std::endl;
		std::cout << std::endl;
		std::cout << "Exiting..." << std::endl;
		exit(1);
	}
		std::getline(std::cin,string);
	while(string.length() <=0)
	{
		std::cout << "Field can't be empty" <<std::endl;
		std::cout << msg ;
		std::getline(std::cin,string);
	}
}