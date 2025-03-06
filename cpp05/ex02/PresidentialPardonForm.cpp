
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("PresidentialPardonForm", 25, 5), _target("Unknown")	{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target)	{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy):
	AForm(copy._target,copy.getGradeToSign(),copy.getGradeToExecute())	{
}

PresidentialPardonForm  &PresidentialPardonForm::operator = (PresidentialPardonForm const &rhs)	{

	if(this != &rhs)
		_target = rhs._target;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const	{
	return (_target);
}

PresidentialPardonForm::~PresidentialPardonForm()	{
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const	{
	if (!getGradeToSign())
		throw AForm::FormNotSigned();
	else if (getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else	{
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox"
				  << std::endl;
	}
}