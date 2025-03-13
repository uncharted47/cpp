#ifndef SPAN_HPP
# define SPAN_HPP
#include <algorithm>
#include <vector>
#include <iomanip>
#include <iostream>
class Span
{
	private :
		std::vector<int> _vector;
		unsigned int limit;
	public :
		Span(void);
		Span(unsigned int N);
		Span(Span const &copy);
		~Span(void);
		Span &operator = (Span const &rhs);
		void addNumber(int N);
		int shortestSpan(void) const;
		int longestSpan(void) const;
		void addNumberList(unsigned int N);
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end) {
       		 unsigned int range = std::distance(begin, end);
            if (range <= limit - _vector.size())
                std::copy(begin, end, std::back_inserter(_vector));
            else
                throw std::runtime_error("Out of available slots for elements");
    }

};

#endif