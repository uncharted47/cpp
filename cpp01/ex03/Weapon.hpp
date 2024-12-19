#ifndef WEAPON_HPP
# define WEAPON_HPP
#include <iostream>
class Weapon
{
	private :
		std::string type;

	public :
		Weapon(std::string type);
		Weapon(void);
		~Weapon(void);
		void setType(std::string type);
		std::string getType(void);

};

#endif