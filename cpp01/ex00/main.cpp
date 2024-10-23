#include "Zombie.hpp"
#include <cstdlib> // Include for system()

int main()
{
    Zombie Zombie_A = Zombie("FOO");
	Zombie_A.announce();
    Zombie* Zombie_B = newZombie("plant");
    Zombie_A.randomChump("root");
    delete Zombie_B;
    return 0;
}