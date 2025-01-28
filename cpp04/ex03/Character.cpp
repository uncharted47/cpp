#include "Character.hpp"

t_materia* Character::equiped_list = 0;

Character::Character(void) {
	std::cout << "Character Default constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		materia[i] = NULL;
	materia_list = NULL;
}

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character parameterized constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		materia[i] = NULL;
	materia_list = NULL;

}

t_materia *Character::cloneMateria() const
{
	if (!materia_list)
		return NULL;

	t_materia *new_list = new t_materia;
	new_list->materia = materia_list->materia->clone();
	new_list->next = NULL;

	t_materia *current_new = new_list;
	t_materia *current_old = materia_list->next;

	while (current_old)
	{
		current_new->next = new t_materia;
		current_new->materia = current_old->materia->clone();
		current_new->next = NULL;
		current_old = current_old->next;
	}

	return new_list;
}


Character::Character(Character const &copy)
{
	std::cout << "Character Copy constructor called" << std::endl;
	for(int i = 0; i < 4; i++)
		materia[i] = NULL;
	if(this != &copy)
	{
		for(int i = 0; i < 4; i++)
		{
			if(materia[i])
				delete materia[i];
			if(copy.materia[i])
				materia[i] = copy.materia[i]->clone();
		}
	}
}

void removeFromlist(AMateria *m, t_materia **materialist)
{
	t_materia *materia_list = *materialist;
	if(!materia_list)
		return;
	if(materia_list->materia == m)
	{
		t_materia *tmp = materia_list;
		materia_list = materia_list->next;
		delete tmp;
		*materialist = materia_list;
		return;
	}
	t_materia *tmp = materia_list;
	while(tmp->next)
	{
		if(tmp->next->materia == m)
		{
			t_materia *tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			delete tmp2;
			return;
		}
		tmp = tmp->next;
	}
}

Character::~Character(void) {
	std::cout << "Character Destructor called" << std::endl;
	for(int i = 0; i < 4; i++)
	{
		if(materia[i])
			delete materia[i];
	}
	while(materia_list)
	{
		t_materia *tmp = materia_list;
		materia_list = materia_list->next;
		delete tmp->materia;
		delete tmp;
	}
	materia_list = NULL;
}

Character const	&Character::operator = (Character const &rhs)
{
	if(this != &rhs)
	{
		for(int i = 0; i < 4; i++)
		{
			if(materia[i])
				delete materia[i];
			if(rhs.materia[i])
				materia[i] = rhs.materia[i]->clone();
		}
	}
	materia_list = rhs.cloneMateria();
	std::cout << "Character assignation operator called" << std::endl;
	return (*this);
}

void Character::equip(AMateria* m)
{
	if(!m)
		return;
	t_materia *tmp = Character::equiped_list;
	while(tmp)
	{
		if(tmp->materia == m)
		{
			std::cout << "Materia already equiped" << std::endl;
			return;
		}
		tmp = tmp->next;
	}
	int i;

	for(i = 0; i < 4; i++)
	{
		if(!materia[i])
		{
			materia[i] = m;
			removeFromlist(m, &materia_list);
			addtolist(m, &Character::equiped_list);
			return;
		}
	}
	if(i == 4)
	{
		std::cout << "No more space for materia" << std::endl;
		return;
	}

}

void Character::unequip(int idx)
{
	if(idx < 0 || idx > 4 || !materia[idx])
		return;
	removeFromlist(materia[idx], &equiped_list);
	addtolist(materia[idx], &materia_list);
	materia[idx] = NULL;
}

void addtolist(AMateria *m, t_materia **materialist)
{
	if(!m)
		return;

	t_materia *materia_list = *materialist;
	if(!materia_list)
		{
			materia_list = new t_materia;
			materia_list->materia = m;
			materia_list->next = NULL;
			*materialist = materia_list;
			return;
		}
	t_materia *tmp = *materialist;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = new t_materia;
	tmp->next->materia = m;
	tmp->next->next = NULL;

}

t_materia *Character::getMateriaList() const
{
	return (materia_list);
}


void Character::clearList()
{
	t_materia *tmp = equiped_list;
	while(tmp)
	{
		t_materia *tmp2 = tmp;
		tmp = tmp->next;
		delete tmp2;
	}
	equiped_list = NULL;
}



void Character::use(int idx, ICharacter& target)
{
	if(idx < 0 || idx > 4 || !materia[idx])
		return;
	materia[idx]->use(target);
}


std::string const & Character::getName() const
{
	return (_name);
}