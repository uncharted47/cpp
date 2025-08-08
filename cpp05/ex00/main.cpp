#include "Bureaucrat.hpp"


int main(void)
{
	Bureaucrat primeMinister("Prime Minister", 1);
	Bureaucrat vicePrimeMinister("Vice Prime Minister", 2);
	Bureaucrat politician("Politician", 3);

	try
	{
		std::cout << primeMinister << std::endl;
		std::cout << vicePrimeMinister << std::endl;
		std::cout << politician << std::endl;
		primeMinister.decrement();
		vicePrimeMinister.increment();
		vicePrimeMinister.increment();
		politician.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


}