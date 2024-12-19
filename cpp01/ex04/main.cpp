#include "replacer.hpp"

bool	emptyArgs(int cmd, char **args)
{
	if (cmd != 4 || !args[1] || !args[2] || !args[3])
	{
		std::cout << "Usage: replacer <file1> <string1> <string2>" << std::endl;
		return (true);
	}
	return (false);
}

bool	isFileExist(std::string fileName)
{
	std::ifstream infile(fileName.c_str());
	return (infile.good());
}

int	main(int cmd, char **args)
{
	if (emptyArgs(cmd, args) || !isFileExist(args[1]))
		return (1);

	Replacer replacer(args[1], args[2], args[3]);
	replacer.replace();
	return (0);
}