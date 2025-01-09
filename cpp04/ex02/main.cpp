#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
	Dog *dog = new Dog();
	Cat *cat = new Cat();


	dog->makeSound();
	cat->makeSound();
	dog->Ideas();
	cat->Ideas();
	delete dog;
	delete cat;
	return (0);
}