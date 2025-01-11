#include "Brain.hpp"


Brain::Brain(void) {


	std::cout << "Brain Default constructor called" << std::endl;

	for (int i = 0; i < 100; i++)
	{
		std::stringstream ss;
		ss << "Idea number " << i;
		ideas[i] = ss.str();
	}
	ideasCount = 100;
}

Brain::Brain(Brain const &copy)
{

	std::cout << "Brain Copy constructor called" << std::endl;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = copy.ideas[i];
		ideasCount = copy.ideasCount;
	}
	*this = copy;
}

Brain::~Brain(void) {
	std::cout << "Brain Destructor called" << std::endl;
}

Brain const	&Brain::operator = (Brain const &rhs)
{
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.ideas[i];
		ideasCount = rhs.ideasCount;
	}
	return (*this);
}

std::string Brain::getIdea(int i) const
{
	if(i < 0 || i >= 100)
		return ("Invalid index");
	return(ideas[i]);
}


int Brain::getIdeasCount(void) const
{
	return (ideasCount);
}