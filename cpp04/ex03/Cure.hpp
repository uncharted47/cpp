#ifndef CURE_HPP
# define CURE_HPP
#include "AMateria.hpp"
class Cure : public AMateria
{
	public :
		Cure(void);
		Cure(Cure const &copy);
		Cure(std::string const & type);
		~Cure(void);
		Cure const &operator = (Cure const &rhs);
		AMateria* clone() const;
};

#endif