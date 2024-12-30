#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "FragTrap.hpp"
class DiamondTrap : public FragTrap , public ScavTrap
{
	private:
		std::string _name;
	public :
		DiamondTrap(void);
		DiamondTrap(DiamondTrap const &copy);
		~DiamondTrap(void);
		DiamondTrap const &operator = (DiamondTrap const &rhs);
};

#endif