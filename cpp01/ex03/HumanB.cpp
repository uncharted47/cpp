#include "HumanB.hpp"

HumanB::HumanB(void) {}

HumanB::HumanB(std::string name) : name(name) {
	this->weapon = NULL;
}

HumanB::~HumanB(void) {}

void HumanB::attack(void)
{
	if(this->weapon == NULL || this->weapon->getType().empty())
	{
		std::cout << this->name << " has no weapon" << std::endl;
		return;
	}
	std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
void HumanB::setType(Weapon weapon)
{
	this->weapon = &weapon;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}