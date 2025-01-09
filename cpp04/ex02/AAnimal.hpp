#ifndef AANIMAL_HPP
# define AANIMAL_HPP
#include <iostream>
class AAnimal
{
	protected:
		std::string _type;

	public :
		AAnimal(void);
		AAnimal(std::string type);
		AAnimal(AAnimal const &copy);
		virtual ~AAnimal(void);
		AAnimal const &operator = (AAnimal const &rhs);
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif