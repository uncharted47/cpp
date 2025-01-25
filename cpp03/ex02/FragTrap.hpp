#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{
	private:
		/* data */
	public :
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &copy);
		virtual ~FragTrap(void);
		FragTrap const &operator = (FragTrap const &rhs);
		void highFivesGuys(void);
};

#endif