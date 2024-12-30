#include "ClapTrap.hpp"


int main(void)
{
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3 = claptrap;

	claptrap3.attack("insect");
	claptrap3.takeDamage(5);
	claptrap3.beRepaired(5);
	return 0;
}