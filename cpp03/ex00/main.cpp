#include "ClapTrap.hpp"


int main(void)
{
	ClapTrap claptrap("Claptrap");
	ClapTrap claptrap2(claptrap);
	ClapTrap claptrap3 = claptrap;

	claptrap.attack("target1");
	claptrap.takeDamage(5);
	claptrap.beRepaired(3);

	claptrap2.attack("target2");
	claptrap2.takeDamage(10);
	claptrap2.beRepaired(7);

	claptrap3.attack("target3");
	claptrap3.takeDamage(5);
	claptrap3.beRepaired(10);

	return 0;
}