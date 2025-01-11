#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>

typedef struct s_materia
{
	AMateria			*materia;
	struct s_materia	*next;
}						t_materia;

class Character : public ICharacter
{
  private:
	std::string _name;
	AMateria *materia[4];
	t_materia *materia_list;
	static t_materia *equiped_list;

  public:
	Character(std::string name);
	Character(void);
	Character(Character const &copy);
	~Character(void);
	Character const &operator=(Character const &rhs);
	void equip(AMateria *m);
	t_materia *getMateriaList() const;
	void unequip(int idx);
	void use(int idx, ICharacter &target);
	std::string const &getName() const;
	static void clearList(void);
	t_materia *cloneMateria() const;
};
void					addtolist(AMateria *m, t_materia **materia_list);
void					removeFromlist(AMateria *m, t_materia **materialist);
#endif