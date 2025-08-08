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
	typedef typename std::deque<T>::const_iterator const_iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;
	typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;
	MutantStack(MutantStack const &copy);
	~MutantStack(void);
	MutantStack const &operator=(MutantStack const &rhs);

	iterator begin(void);
	iterator end(void);
	const_iterator begin(void) const;
	const_iterator end(void) const;
	reverse_iterator rbegin(void);
	reverse_iterator rend(void);
	const_reverse_iterator rbegin(void) const;
	const_reverse_iterator rend(void) const;
};
# include "MutantStack.tpp"
#endif