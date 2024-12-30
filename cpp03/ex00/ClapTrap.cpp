#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "CrapTrap Default constructor called" << std::endl;
	this->Name = "ClapTrap";
	this->Hitpoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "CrapTrap Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called. ClapTrap " << this->Name << " self-destructs." << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->Name);
}

ClapTrap const &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "CrapTrap Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		this->Name = rhs.getName();
		this->Hitpoints = 10;
		this->EnergyPoints = 10;
		this->AttackDamage = 0;
	}
	return (*this);
}

ClapTrap::ClapTrap(std::string name) : Name(name), Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap " << this->Name << " is selfaware" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	if(!this->EnergyPoints)
	{
		std::cout << "ClapTrap " << this->Name << " is out of energy!" <<std::endl;
		return ;
	}
	this->EnergyPoints -= 1;
	std::cout << "ClapTrap " << this->Name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(!this->Hitpoints)
	{
		std::cout << "ClapTrap " << this->Name << " is already dead!" << std::endl;
		return ;
	}
	else if(this->Hitpoints - amount <= 0)
	{
		this->Hitpoints = 0;
		std::cout << "ClapTrap " << this->Name << " has dead!" << std::endl;
		return ;
	}
	this->Hitpoints -= amount;
	std::cout << "ClapTrap " << this->Name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(!this->EnergyPoints)
	{
		std::cout << "ClapTrap " << this->Name << " is out of energy!" << std::endl;
		return ;
	}
	if(this->Hitpoints + amount > 10)
	{
		std::cout << "ClapTrap " << this->Name << " is already at full health!" << std::endl;
		return ;
	}
	this->Hitpoints += amount;
	this->EnergyPoints -= 1;
	std::cout << "ClapTrap " << this->Name << " is repaired for " << amount << " points of health!" << std::endl;
}