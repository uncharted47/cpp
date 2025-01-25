#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap Default constructor called" << std::endl;
	this->name = "unknown_ClapTrap";
	this->Hitpoints = 10;
	this->EnergyPoints = 10;
	this->AttackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap const &copy)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap Destructor called "<< std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->name);
}

ClapTrap const &ClapTrap::operator=(ClapTrap const &obj)
{
	std::cout << "ClapTrap Assignation operator called" << std::endl;
	this->name = obj.name;
	this->Hitpoints = obj.Hitpoints;
	this->EnergyPoints = obj.EnergyPoints;
	this->AttackDamage = obj.AttackDamage;
	return (*this);
}

ClapTrap::ClapTrap(std::string name) : name(name), Hitpoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap Paramitrized Constructer Called" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	 if(!this->Hitpoints)
	 {
		 std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		 return ;
	 }
	if(!this->EnergyPoints )
	{
		std::cout << "ClapTrap " << this->name << " is out of energy!" <<std::endl;
		return ;
	}
	this->EnergyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target << " causing " << this->AttackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if(!this->Hitpoints)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return ;
	}
	else if((int)amount >= this->Hitpoints && amount)
	{
		this->Hitpoints = 0;
		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << this->name << " has died!" << std::endl;
		return ;
	}
	this->Hitpoints -= amount;
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(!this->Hitpoints)
	{
		std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
		return ;
	}
	if(!this->EnergyPoints)
	{
		std::cout << "ClapTrap " << this->name << " is out of energy!" << std::endl;
		return ;
	}
	this->Hitpoints += amount;
	this->EnergyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points of health!" << std::endl;
}