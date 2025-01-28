#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	std::cout << "MateriaSource Default constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &copy)
{
	std::cout << "MateriaSource Copy constructor called" << std::endl;
	if(this != &copy)
	{
		for(int i = 0; i < 4; i++)
			materia[i] = copy.materia[i]->clone();
	}
	*this = copy;
}

MateriaSource::~MateriaSource(void) {
	std::cout << "MateriaSource Destructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		delete materia[i];
}

MateriaSource const	&MateriaSource::operator = (MateriaSource const &rhs)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for(int i = 0; i < 4; i++)
			materia[i] = rhs.materia[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if(!materia)
		return;
	for(int i = 0; i < 4; i++)
	{
		if(!this->materia[i])
		{
			this->materia[i] = materia;
			return ;
		}
	}
	std::cout << "Can't learn anymore materia" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const & type)
{
	for(int i = 0; i < 4; i++)
	{
		if(materia[i] && materia[i]->getType() == type)
			return (materia[i]->clone());
	}
	return (NULL);
}