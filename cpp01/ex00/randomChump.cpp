#include "Zombie.hpp"

void randomChump(std::string name)
{
	Zombie zombie = Zombie(name);
	std::cout << zombie.getName() << " : BraiiiiiiinnnzzzZ..." << std::endl;
}