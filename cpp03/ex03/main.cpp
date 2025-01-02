#include "DiamondTrap.hpp"


int main(void)
{

	std::string name = "DiamondTrap1";
	DiamondTrap DiamondTrap1(name);

	DiamondTrap1.attack("FragTrap2");
	DiamondTrap1.takeDamage(30);
	DiamondTrap1.beRepaired(20);
	DiamondTrap1.highFivesGuys();
	DiamondTrap1.guardGate();
	DiamondTrap1.whoAmI();

	return 0;
}