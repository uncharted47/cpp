#include "replacer.hpp"

Replacer::Replacer(std::string fileName, std::string s1, std::string s2)
{
	this->FileName = fileName;
	this->S1 = s1;
	this->S2 = s2;
}

Replacer::Replacer(void)
{
}

Replacer::~Replacer(void)
{
}

void replace_two(std::string &line, std::string &s1, std::string &s2)
{
	size_t pos = 0;

	pos = line.find(s1, pos);
	while (pos != std::string::npos)
	{
		line.erase(pos, s1.length());
		line.insert(pos, s2);
		pos = line.find(s1, pos + s2.length());
	}
}


void	Replacer::replace(void)
{
	std::string line;

	std::ifstream infile(this->FileName.c_str());
	if(!infile.is_open())
	{
		std::cerr << "Error: could not open file" << std::endl;
		return;
	}
	std::string out = this->FileName + ".replace";
	std::ofstream outfile(out.c_str(), std::ios::trunc);
	if(!outfile.is_open())
	{
		std::cerr << "Error: could not create file" << std::endl;
		infile.close();
		return;
	}

	while(std::getline(infile, line))
	{
		replace_two(line, this->S1, this->S2);
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();

}