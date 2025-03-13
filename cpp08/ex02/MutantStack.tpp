#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) : std::stack<T, std::deque<T> >() {}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &copy) : std::stack<T, std::deque<T> >(copy) {}

template <typename T>
MutantStack<T>::~MutantStack(void) {}

template <typename T>
MutantStack<T> const &MutantStack<T>::operator=(MutantStack const &rhs) {
	if (this != &rhs) {
		std::stack<T, std::deque<T> >::operator=(rhs);
	}
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void) {
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(void) {
	return this->c.end();
}