#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) :_name("default") {
		std::cout << "Default constructor called" << std::endl;
        this->Hitpoints = FragTrap::Hitpoints;
        this->EnergyPoints = 50;
		this->AttackDamage = FragTrap::AttackDamage;
		ClapTrap::_name = this->_name + "_clap_name";
}

DiamondTrap::DiamondTrap(std::string &name) :ClapTrap(name + "_clap_name"), _name(name) {
		std::cout << "DiamondTrap parametrized constructor called" << std::endl;
        this->EnergyPoints = 50;
}


DiamondTrap::DiamondTrap(DiamondTrap const &copy)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = copy;
}

DiamondTrap::~DiamondTrap(void) {
		std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap const	&DiamondTrap::operator = (DiamondTrap const &obj)
{
	std::cout << "DiamondTrap assignation operator called" << std::endl;
	if (this != &obj)
	{
		this->_name = obj._name;
		this->Hitpoints = obj.Hitpoints;
		this->EnergyPoints = obj.EnergyPoints;
		this->AttackDamage = obj.AttackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}