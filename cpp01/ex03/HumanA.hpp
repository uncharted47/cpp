#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public :
		HumanA(void);
		HumanA(std::string name , Weapon& weapon);
		~HumanA(void);
		void attack(void);
		void setType(Weapon &weapon);

};

#endif