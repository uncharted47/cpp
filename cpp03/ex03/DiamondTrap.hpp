#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap : public ScavTrap, public FragTrap 
{
	private:
		std::string _name;
	public :
		DiamondTrap(void);
		DiamondTrap(std::string &name);
		DiamondTrap(DiamondTrap const &copy);
		~DiamondTrap(void);
		DiamondTrap const &operator = (DiamondTrap const &rhs);
		void whoAmI(void);

};

#endif