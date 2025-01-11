#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Animal* animals[100];

	for (int i = 0; i < 100; i++)
	{
		if(i < 50)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}




	for (int i = 0; i < 100; i++)
	{
		if(i < 50)
			delete animals[i];
		else
			delete animals[i];
	}
	return (0);
}