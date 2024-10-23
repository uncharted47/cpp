#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << " : BraiiiiiiinnnzzzZ...";
}

Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	std::cout << zombie->getName() << " : BraiiiiiiinnnzzzZ..." << std::endl;
	return zombie;
}

void Zombie::randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	std::cout << zombie.name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::getName()
{
	return(this->name);
}