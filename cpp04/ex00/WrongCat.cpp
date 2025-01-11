#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	_type = "WrongCat";
	std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy)
{
std::cout << "WrongCat Copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat const	&WrongCat::operator = (WrongCat const &rhs)
{
	std::cout << "WrongCat assignation operator called" << std::endl;
	if(this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "Wrong cat noise Wrong cat noise" << std::endl;
}