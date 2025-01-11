#include "AMateria.hpp"

AMateria::AMateria(void) {
	std::cout << "AMateria Default constructor called" << std::endl;
	this->_type = "none";
}


AMateria::AMateria(AMateria const &copy)
{
	std::cout << "AMateria Copy constructor called" << std::endl;
	*this = copy;
}

AMateria::~AMateria(void) {
	std::cout << "AMateria Destructor called" << std::endl;
	
}

AMateria const	&AMateria::operator = (AMateria const &rhs)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << " * uses some " << this->_type << " on " << target.getName() << " *" <<std::endl;
}

std::ostream &operator<<(std::ostream &out, AMateria const &rhs)
{
	out << rhs.getType();
	return (out);
}
