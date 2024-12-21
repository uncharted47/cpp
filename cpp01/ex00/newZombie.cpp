#include "Zombie.hpp"

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