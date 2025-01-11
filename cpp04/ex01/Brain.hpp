#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>
#include <sstream>
class Brain
{
	private:
		std::string ideas[100];
		int			ideasCount;
	public :
		Brain(void);
		Brain(Brain const &copy);
		virtual ~Brain(void);
		std::string getIdea(int i) const;
		int getIdeasCount(void) const;
		Brain const &operator = (Brain const &rhs);
};

#endif