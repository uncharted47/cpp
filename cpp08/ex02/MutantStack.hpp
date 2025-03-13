#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
#include <vector>
#include <iostream>
#include <iomanip>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
	public:
	MutantStack(void);
	typedef typename std::deque<T>::iterator iterator;
	MutantStack(MutantStack const &copy);
	~MutantStack(void);
	MutantStack const &operator=(MutantStack const &rhs);

	iterator begin(void);
	iterator end(void);
};
# include "MutantStack.tpp"
#endif