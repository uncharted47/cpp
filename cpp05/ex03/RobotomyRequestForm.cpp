#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Unknown")	{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target)	{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & orig) :
	AForm(orig)	{
}

RobotomyRequestForm const &RobotomyRequestForm::operator= (RobotomyRequestForm const &rhs)
{
	if(this != &rhs)
		_target = rhs._target;
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const	{
	return (_target);
}

RobotomyRequestForm::~RobotomyRequestForm()	{
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const	{
	if (!getIsSigned())
		throw AForm::FormNotSigned();
	else if (getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else	{
		std::cout << "Brrrrrrrrrrrrrrrrrrrrrrrrrrr..." << std::endl;
		srand (time(NULL));
		int rando = rand();
		if (rando % 2)
			std::cout << _target << " has been robotomized succefully";
		else
			std::cout << _target << "'s robotomization failed";
		std::cout << std::endl;
	}
}