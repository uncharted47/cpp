#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &copy);
    ~AForm();
    AForm &operator=(AForm const &rhs);

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;
    // Exceptions
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    class FormNotSigned : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &stream, const AForm &form);

#endif