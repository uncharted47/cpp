#include "Zombie.hpp"



Zombie* zombieHorde( int N, std::string name )
{
	Zombie *Horde;

	if(N <= 0)
	{
		std::cout << "Invalid number of zombies" << std::endl;
		return NULL;
	}
	Horde = new Zombie[N];
	if (Horde == NULL)
	{
		std::cout << "Memory allocation failed" << std::endl;
		return NULL;
	}
	for(int i = 0; i < N ; i++)
		Horde[i].setName(name);

	return Horde;
}



int main()
{
	Zombie *Horde = NULL;

	Horde = zombieHorde(5, "Zombie");
	if(Horde == NULL)
		return 1;
	for(int i = 0; i < 5 ; i++)
		Horde[i].announce();
	delete [] Horde;
	return 0;
}
