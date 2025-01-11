#ifndef ICE_HPP
# define ICE_HPP
#include "AMateria.hpp"
class Ice : public AMateria
{
	public :
		Ice(void);
		Ice(Ice const &copy);
		Ice(std::string const & type);
		~Ice(void);
		Ice const &operator = (Ice const &rhs);
		AMateria* clone() const;
};

#endif