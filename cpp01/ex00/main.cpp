#include "Zombie.hpp"

int main()
{
    Zombie Zombie_A = Zombie("FOO");
	Zombie_A.announce();
    Zombie* Zombie_B = newZombie("plant");
    if(Zombie_B == NULL)
        return 1;
    Zombie_A.randomChump("root");
    delete Zombie_B;
    return 0;
}