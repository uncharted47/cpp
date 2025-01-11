#include "Cure.hpp"

Cure::Cure(void) {
	this->_type = "cure";
	std::cout << "Cure Default constructor called" << std::endl;
}

Cure::Cure(Cure const &copy)
{
	std::cout << "Cure Copy constructor called" << std::endl;
	if(this != &copy)
	{
		this->_type = copy._type;
	}
	*this = copy;
}

Cure::~Cure(void) {
	std::cout << "Cure Destructor called" << std::endl;
}

Cure const	&Cure::operator = (Cure const &rhs)
{
	if(this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}