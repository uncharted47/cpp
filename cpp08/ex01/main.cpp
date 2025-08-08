#include "Span.hpp"

int main()
{
  try
  	{

		Span span = Span(5);
		span.addNumber(7);
		span.addNumber(15);
		span.addNumber(23);
		span.addNumber(42);
		span.addNumber(88);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest span: " << span.longestSpan() << std::endl;

		Span sp1(10);
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(5);
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(15);
		vec.push_back(19);
		sp1.addRange(vec.begin(), vec.end());
		std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp1.longestSpan() << std::endl;

  	}
  	catch(const std::exception& e)
  	{
		std::cerr << e.what() << '\n';
  	}



    return 0;
}