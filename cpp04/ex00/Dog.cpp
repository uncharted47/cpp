#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	if(this != &copy)
		this->_type = copy._type;
	*this = copy;
}

Dog::~Dog(void) {
	std::cout << "Dog Destructor called" << std::endl;
}

Dog const	&Dog::operator = (Dog const &rhs)
{
	std::cout << "Dog assignation operator called" << std::endl;
	if(this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "woof woof" << std::endl;
}