#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"
class ScavTrap : virtual public ClapTrap
{
	private:
		bool _guardMode;
	public :
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &copy);
		~ScavTrap(void);
		ScavTrap &operator = (const ScavTrap &rhs);
		void guardGate(void);
		virtual void attack(std::string const & target);
};

#endif