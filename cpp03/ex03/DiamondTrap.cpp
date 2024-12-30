#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) {
	std::cout << "default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &copy)
{
		std::cout << "copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap(void) {
		std::cout << "destructor called" << std::endl;
}

DiamondTrap const	&DiamondTrap::operator = (DiamondTrap const &obj)
{


	std::cout << "copy assignement operator called" << std::endl;
		return (*this);
}