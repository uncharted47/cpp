#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <iostream>
class WrongAnimal
{
	protected:
		std::string _type;
	public :
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &copy);
		virtual ~WrongAnimal(void);
		WrongAnimal const &operator = (WrongAnimal const &rhs);
		virtual void makeSound(void) const;
		std::string getType(void) const;
};

#endif