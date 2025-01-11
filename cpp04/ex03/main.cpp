#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"







int	main(void)
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	ICharacter *me2 = new Character("me2");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me2->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me2->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	delete me2;
	Character::clearList();
	return (0);
}