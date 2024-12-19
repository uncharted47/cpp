#ifndef HARL_HPP
# define HARL_HPP
#include <iostream>
class Harl
{
	public :
		void debug();
		void info();
		void warning();
		void error();
};

typedef struct level
{
	std::string name;
	void (Harl::*func)();
} level;



#endif