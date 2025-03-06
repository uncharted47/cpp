#include "Intern.hpp"
Intern::Intern(void) {}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern(void) {}

Intern const	&Intern::operator = (Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

AForm* Intern::makeForm(std::string Form, std::string Name)
{
	std::string FormList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int i=0;
	for(i = 0; i < 3; ++i)
	{
		if(Form == FormList[i])
			break;
	}
	std::cerr << i << std::endl;
	switch (i)
	{
	case 0:
		return (new PresidentialPardonForm(Name));
		break;
	case 1:
		return (new RobotomyRequestForm(Name));
		break;
	case 2:
		return(new ShrubberyCreationForm(Name));
		break;
	default:
		std::cerr << "Intern can't creat Form" << std::endl;
		break;
	}
	return (NULL);
}

