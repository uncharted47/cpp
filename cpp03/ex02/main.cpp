#include "FragTrap.hpp"


int main(void)
{

	FragTrap FragTrap1("FragTrap1");
	FragTrap FragTrap2("FragTrap2");

	FragTrap1.attack("FragTrap2");
	FragTrap2.takeDamage(30);
	FragTrap2.beRepaired(20);
	FragTrap1.highFivesGuys();

	return 0;
}