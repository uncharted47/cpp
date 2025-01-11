#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal Default constructor called" << std::endl;
	this->_type = "";
}

Animal::Animal(Animal const &copy)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	this->_type = copy._type;
	*this = copy;
}
Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal Destructor called" << std::endl;
}

Animal const	&Animal::operator = (Animal const &rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void Animal::makeSound(void) const
{
	std::cout << "cats don't bark" << std::endl;
}

std::string Animal::getType(void) const
{
	return (this->_type);
}