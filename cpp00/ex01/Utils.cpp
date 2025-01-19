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
	std::getline(std::cin,string);
	if(std::cin.eof())
	{
		std::cout << std::endl;
		std::cout << "EOF detected" <<std::endl;
		std::cout << std::endl;
		std::cout << "Exiting..." << std::endl;
		exit(1);
	}
	while(string.length() <=0)
	{
		std::cout << "Field can't be empty" <<std::endl;
		std::cout << msg ;
		std::getline(std::cin,string);
	}
}

int valid_string(std::string string)
{
	for(size_t i = 0; i < string.length(); i++)
	{
		if(std::isalpha(string[i]) == 0)
		{
			std::cout << "Invalid input" << std::endl;
			return (0);
		}
	}
	return (1);

}

std::string truncate(std::string &str)
{
	std::string tmp;
	if(str.length() > 10)
	{
		tmp = str.substr(0,9);
		tmp.append(".");
		return(tmp);
	}
	return (str);
}