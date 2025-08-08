#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
		Bureaucrat primeMinister("Prime Minister", 1);
		Bureaucrat vicePrimeMinister("Vice Prime Minister", 2);
		Bureaucrat politician("Politician", 3);
		Form constitution("constitution",1,1);
		Form NewLaw("ban on vapes",2,5);

	try
	{
		std::cout << constitution << std::endl;
		std::cout << NewLaw << std::endl;
		vicePrimeMinister.signForm(constitution);
		primeMinister.signForm(constitution);
		vicePrimeMinister.signForm(NewLaw);
		politician.signForm(NewLaw);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}