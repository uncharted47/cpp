#include <iostream>


int main(void)
{
	std::string string = "HI THIS IS BRAIN";

	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "String address: " << &string << std::endl;
	std::cout << "Pointer address: " << stringPTR << std::endl;
	std::cout << "Reference address: " << &stringREF << std::endl;

	std::cout << "String value: " << string << std::endl;
	std::cout << "Pointer value: " << *stringPTR << std::endl;
	std::cout << "Reference value: " << stringREF << std::endl;

	return 0;
}