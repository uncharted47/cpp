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
	std::cout << this->name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
	Zombie *zombie = new Zombie(name);
	if(zombie == NULL)
	{
		std::cout << "Memory allocation failed" << std::endl;
		return NULL;
	}
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

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::Zombie(void)
{
	this->name = "";
}
