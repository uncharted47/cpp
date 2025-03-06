#ifndef INTERN_HPP
# define INTERN_HPP
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
class Intern
{
	private :

	public :
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
		Intern const &operator = (Intern const &rhs);
		AForm *makeForm(std::string Name,std::string Form);
};

#endif