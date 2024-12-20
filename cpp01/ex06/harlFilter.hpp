#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP
# include <iostream>

enum Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
};


class harlFilter
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