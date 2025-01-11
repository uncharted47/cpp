#include "Ice.hpp"

Ice::Ice(void) {
	this->_type = "ice";
	std::cout << "Ice Default constructor called" << std::endl;
}

Ice::Ice(Ice const &copy)
{
	if(this != &copy)
	{
		this->_type = copy._type;
	}
	*this = copy;
}

Ice::~Ice(void) {
	std::cout << "Ice Destructor called" << std::endl;
}

Ice const	&Ice::operator = (Ice const &rhs)
{
	if(this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}


AMateria* Ice::clone() const
{
	return (new Ice());
}