#include "Zombie.hpp"



int main()
{
	Zombie *Horde = NULL;

	Horde = zombieHorde(5, "Zombie");
	if(Horde == NULL)
		return 1;
	if(Horde == NULL)
		return 1;
	for(int i = 0; i < 5 ; i++)
		Horde[i].announce();
	delete [] Horde;
	return 0;
}
