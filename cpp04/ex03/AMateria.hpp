#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;


	public :
		AMateria(void);
		AMateria(AMateria const &copy);
		virtual ~AMateria(void);
		AMateria const &operator = (AMateria const &rhs);
		AMateria(std::string const & type);
// [...]
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif