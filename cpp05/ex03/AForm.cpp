#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &copy)
    : _name(copy._name), _isSigned(copy._isSigned),
      _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
        _isSigned = rhs._isSigned;
    return *this;
}

std::string AForm::getName() const
{
    return _name;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* AForm::FormNotSigned::what() const throw()
{
    return "Form Not signed!";
}

std::ostream &operator<<(std::ostream &stream, const AForm &form)
{
    stream << "Form: " << form.getName() << std::endl
           << ", Sign Status: " << (form.getIsSigned() ? "Signed" : "Not Signed") << std::endl
           << ", Grade to Sign: " << form.getGradeToSign() << std::endl
           << ", Grade to Execute: " << form.getGradeToExecute() << std::endl;
    return stream;
}