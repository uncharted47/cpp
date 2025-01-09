#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "Animal Default constructor called" << std::endl;
	this->_type = "";
}

AAnimal::AAnimal(AAnimal const &copy)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	this->_type = copy._type;
	*this = copy;
}
AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "Animal Destructor called" << std::endl;
}

AAnimal const	&AAnimal::operator = (AAnimal const &rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void AAnimal::makeSound(void) const
{
	std::cout << "cats don't bark" << std::endl;
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}