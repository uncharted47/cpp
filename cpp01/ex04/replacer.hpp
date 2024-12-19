#ifndef REPLACER_HPP
#define REPLACER_HPP
#include <string>
#include <fstream>
#include <iostream>


class Replacer
{
	private:
		std::string FileName;
		std::string S1;
		std::string S2;
	public:
		Replacer(std::string fileName, std::string s1, std::string s2);
		Replacer(void);
		~Replacer(void);
		void	replace(void);

};

#endif