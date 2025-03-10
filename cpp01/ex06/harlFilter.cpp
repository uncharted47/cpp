#include "harlFilter.hpp"

void harlFilter::debug()
{
	std::cout << "[ DEBUG ]" << std::endl;
	 std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" <<std::endl;
}
void harlFilter::info()
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void harlFilter::warning()
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."<<std::endl
 	<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void harlFilter::error()
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void harlFilter::complain(int level)
{
	if(level == -2)
	{
		std::cout << "[emptiness is not complaning]" << std::endl;
		return;
	}
	switch (level)
	{
		case DEBUG:
			debug();
			break;
		case INFO:
			info();
			break;
		case WARNING:
			warning();
			break;
		case ERROR:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}