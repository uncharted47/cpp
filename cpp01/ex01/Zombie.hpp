#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <iostream>

class Zombie
{
	private:
		std::string name;

	public:
		Zombie(std::string name);
		Zombie(void);
		Zombie(const Zombie &zombie);
		~Zombie();
		void announce();
		void randomChump(std::string name);
		void setName(std::string name);
		std::string getName();
};
Zombie* newZombie(std::string name);

#endif