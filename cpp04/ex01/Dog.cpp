#include "Dog.hpp"


Dog::Dog(void) {
	_type = "Dog";
	_Brain = new Brain();
	std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(Dog const &copy)
{
	std::cout << "Dog Copy constructor called" << std::endl;
	if(this != &copy)
		this->_type = copy._type;
	*this = copy;
}

Dog::Dog(std::string type, Brain *Brain_ptr) : Animal(type)
{
	if(!Brain_ptr)
		this->_Brain = new Brain();
	else
		this->_Brain = Brain_ptr;
	std::cout << "Dog parameterized constructor called" << std::endl;
}


Dog::~Dog(void) {
	std::cout << "Dog Destructor called" << std::endl;
	delete _Brain;
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

void Dog::Ideas(void) const
{
	std::cout << "Dog has ideas" << std::endl;
	for(int i = 0; i < _Brain->getIdeasCount(); i++)
		std::cout << _Brain->getIdea(i) << std::endl;
}