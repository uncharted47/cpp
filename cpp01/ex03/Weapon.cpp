#include "Weapon.hpp"

Weapon::Weapon(void) {
	this->type = "no weapon";
}

Weapon::Weapon(std::string type)
{
	this->type = type;
}

Weapon::~Weapon(void) {}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string Weapon::getType(void)
{
	return (this->type);
}
