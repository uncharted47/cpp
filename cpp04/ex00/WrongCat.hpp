#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
	public :
		WrongCat(void);
		WrongCat(WrongCat const &copy);
		~WrongCat(void);
		WrongCat const &operator = (WrongCat const &rhs);
		void makeSound(void) const;
};

#endif