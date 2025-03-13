#include "Span.hpp"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

  try
  	{

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		Span sp1(10);
		std::vector<int> vec = {1, 5, 10, 20 ,15, 19};
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