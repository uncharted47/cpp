#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>
class Animal
{
	protected:
		std::string _type;

	public :
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &copy);
		virtual ~Animal(void);
		Animal const &operator = (Animal const &rhs);
		virtual void makeSound(void) const;
		std::string getType(void) const;
};

#endif