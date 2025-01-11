#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
class Cat : public Animal
{

	public :
		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);
		Cat const &operator = (Cat const &rhs);
		void makeSound(void) const;
};

#endif