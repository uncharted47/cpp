#include "ScavTrap.hpp"


int main(void)
{
	ScavTrap scavtrap("ScavTrap");
	ScavTrap scavtrap2(scavtrap);
	ScavTrap scavtrap3;

	scavtrap3 = scavtrap;

	scavtrap3.attack("insect");
	scavtrap3.takeDamage(5);
	scavtrap3.beRepaired(5);
	scavtrap3.guardGate();
	scavtrap3.guardGate();


	return 0;
}