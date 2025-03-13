#include "Span.hpp"

Span::Span(void) {
	limit = 0;
	_vector.clear();

}
Span::Span(unsigned int N)
{
	limit = N;
}

Span::Span(Span const &copy)
{
	*this = copy;
}

Span::~Span(void) {}

Span	&Span::operator = (Span const &rhs)
{
	if(this != &rhs )
	{
		limit = rhs.limit;
		_vector.clear();
		for(std::vector<int>::const_iterator it = rhs._vector.begin(); it != rhs._vector.end(); it++)
			_vector.push_back(*it);
	}
	return (*this);
}

void Span::addNumber(int N)
{
	if(!limit)
		throw std::runtime_error("you have reached the limit of number you can add to the span");
	_vector.push_back(N);
	limit--;
}

int Span::shortestSpan(void) const
{
	if(_vector.size() < 2)
		throw std::runtime_error("more than 2 elements need to find a span");


	std::vector<int> tmp_vector = _vector;
	std::sort(tmp_vector.begin() , tmp_vector.end());

	int shortestSpan = tmp_vector[1] - tmp_vector[0];
	for(std::vector<int>::const_iterator it = tmp_vector.begin(); it != tmp_vector.end() && it + 1 != tmp_vector.end(); ++it)
	{
		if((*(it + 1) - *(it)) < shortestSpan)
			shortestSpan = *(it + 1) - *(it);
	}
	return shortestSpan;
}

int Span::longestSpan(void) const
{
	if(_vector.size() < 2)
		throw std::runtime_error("more than 2 elements need to find a span");


	std::vector<int> tmp_vector = _vector;
	std::sort(tmp_vector.begin() , tmp_vector.end());


	return tmp_vector[tmp_vector.size() - 1]  - tmp_vector[0];
}
