#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
	std::cout << "FragTrap default contructor called" << std::endl;
	this->_name = "FragTrap";
	this->Hitpoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap const &copy)
{
	std::cout << "FragTrap copy contructor called" << std::endl;
	*this = copy;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap const	&FragTrap::operator = (FragTrap const &obj)
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if(this != &obj)
	{
		this->_name = obj._name;
		this->Hitpoints = obj.Hitpoints;
		this->EnergyPoints = obj.EnergyPoints;
		this->AttackDamage = obj.AttackDamage;
	}
	return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap paramitrized contructor called" << std::endl;
	this->Hitpoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
}

void FragTrap::highFivesGuys(void)
{
	if(!Hitpoints)
	{
		std::cout << "FragTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " high fives guys" << std::endl;
}
