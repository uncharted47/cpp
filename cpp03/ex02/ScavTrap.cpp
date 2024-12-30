#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) {
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = copy;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap 	&ScavTrap::operator = (const ScavTrap  &obj)
{

	this->Name = obj.Name;
	this->Hitpoints = obj.Hitpoints;
	this->EnergyPoints = obj.EnergyPoints;
	this->AttackDamage = obj.AttackDamage;
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	return (*this);
}


ScavTrap::ScavTrap(std::string name)
{
	Name = name;
	Hitpoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap parameterized Construct is called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if(_guardMode)
	{
		std::cout << "ScavTrap is already in Gate keeper mode" << std::endl;
		return ;
	}
	_guardMode = true;
	std::cout << "ScavTrap has entered in Gate keeper mode" << std::endl;
}