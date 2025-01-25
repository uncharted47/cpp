#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap Default constructor called" << std::endl;
	Hitpoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
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

	this->_name = obj._name;
	this->Hitpoints = obj.Hitpoints;
	this->EnergyPoints = obj.EnergyPoints;
	this->AttackDamage = obj.AttackDamage;
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	return (*this);
}


ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_name = name;
	Hitpoints = 100;
	EnergyPoints = 50;
	AttackDamage = 20;
	std::cout << "ScavTrap parameterized Construct is called" << std::endl;
}

void ScavTrap::guardGate(void)
{
	if(!this->Hitpoints)
	{
		std::cout << "ScavTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	if(_guardMode)
	{
		std::cout << "ScavTrap is already in Gate keeper mode" << std::endl;
		return ;
	}
	_guardMode = true;
	std::cout << "ScavTrap has entered in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	if(!this->Hitpoints)
	{
		std::cout << "ScavTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}

	if(!this->EnergyPoints)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy!" <<std::endl;
		return ;
	}
	this->EnergyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
}