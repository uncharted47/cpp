#include "Cat.hpp"

Cat::Cat(void) {
	_Brain = new Brain();
	this->_type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(Cat const &copy)
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat(void) {
	std::cout << "Cat Destructor called" << std::endl;
	delete _Brain;
}

Cat::Cat(std::string type, Brain *Brain_ptr) : Animal(type)
{
	if(!Brain_ptr)
		this->_Brain = new Brain();
	else
		this->_Brain = Brain_ptr;
	std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat const	&Cat::operator = (Cat const &rhs)
{
	if(this != &rhs)
	{
		this->_type = rhs._type;
	}
	std::cout << "Cat assignation operator called" << std::endl;
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow" << std::endl;
}