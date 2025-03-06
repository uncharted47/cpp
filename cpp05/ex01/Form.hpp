#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    Form();
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(Form const &copy);
    ~Form();
    Form &operator=(Form const &rhs);

    // Getters
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Member functions
    void beSigned(const Bureaucrat &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &stream, const Form &form);

#endif