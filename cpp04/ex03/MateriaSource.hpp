#ifndef MateriaSource_HPP
# define MateriaSource_HPP
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <iostream>
#include "Ice.hpp"
#include "Cure.hpp"
class MateriaSource : public IMateriaSource
{
	private:
		AMateria *materia[4];
	public :
		MateriaSource(void);
		MateriaSource(MateriaSource const &copy);
		~MateriaSource(void);
		MateriaSource const &operator = (MateriaSource const &rhs);
		void learnMateria(AMateria *materia);
		AMateria *createMateria(std::string const & type);
};

#endif