#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal Default constructor called" << std::endl;
	_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

WrongAnimal const	&WrongAnimal::operator = (WrongAnimal const &rhs)
{

	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if(this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong animal noise Wrong animal noise" << std::endl;
}


std::string WrongAnimal::getType(void) const
{
	return (_type);
}