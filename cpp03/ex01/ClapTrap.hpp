#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>
class ClapTrap
{
	protected:
		std::string Name;
		int Hitpoints;
		int EnergyPoints;
		int AttackDamage;
	public :
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &copy);
		~ClapTrap(void);
		std::string getName(void) const;
		ClapTrap const &operator = (ClapTrap const &rhs);
		virtual void attack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif