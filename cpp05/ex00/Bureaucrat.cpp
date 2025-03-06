#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) :_name("Uknown")
{
	_grade = -1;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if(grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::~Bureaucrat(void) {
}

Bureaucrat	&Bureaucrat::operator = (Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

std::string Bureaucrat::getName(void) const{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::increment(){
	if((_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrement(){
	if((_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat)
{
	stream << bureaucrat.getName() <<", bureaucrat grade " << bureaucrat.getGrade() ;
	return stream;
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too Low!";
}
