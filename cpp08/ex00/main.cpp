#include "easyfind.hpp"

int main()
{
	try
	 {
	std::vector<int> vector = {1,2,3,4,5,6};
	std::cout << ::easyfind(vector,5) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}