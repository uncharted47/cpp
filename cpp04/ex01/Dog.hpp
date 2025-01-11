#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"
class Dog : public Animal
{
  private:
	Brain *_Brain;

  public:
	Dog(void);
	Dog(Dog const &copy);
	~Dog(void);
	Dog(std::string type, Brain *Brain);
	Dog const &operator=(Dog const &rhs);
	void Ideas(void) const;
	void makeSound(void) const;
};

#endif