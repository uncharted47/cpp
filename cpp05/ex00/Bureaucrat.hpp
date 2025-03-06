#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
#include <iostream>
#include <exception>


class Bureaucrat
{
	private :
		std::string const _name;
		int _grade;
	public :
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);
		Bureaucrat &operator = (Bureaucrat const &rhs);
		std::string getName(void) const;
		int getGrade(void) const;
		void increment(void);
		void decrement(void);
		class GradeTooHighException : virtual public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : virtual public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};
std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

#endif