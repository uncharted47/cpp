#ifndef CAT_HPP
# define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"
class Cat : public AAnimal
{

	private:
		Brain *_Brain;
	public :
		Cat(void);
		Cat(Cat const &copy);
		~Cat(void);
		Cat(const std::string type, Brain *Brain);
		Cat const &operator = (Cat const &rhs);
		void Ideas(void) const;
		void makeSound(void) const;
};

#endif