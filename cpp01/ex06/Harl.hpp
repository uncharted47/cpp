#ifndef HARL_HPP
# define HARL_HPP
# include <iostream>

enum Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};


class Harl
{
 private:
	void debug();
	void info();
	void warning();
	void error();

  public:
	void complain(int level);
};


#endif