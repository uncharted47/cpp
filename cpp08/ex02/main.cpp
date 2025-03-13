
	#include "MutantStack.hpp"
	#include <list>
	#include <iostream>

	int main()
	{
		std::cout << "=== Testing MutantStack ===" << std::endl;

		MutantStack<int> mstack;

		// Test basic stack operations
		mstack.push(5);
		mstack.push(17);

		std::cout << "Top: " << mstack.top() << std::endl;

		mstack.pop();
		std::cout << "Size after pop: " << mstack.size() << std::endl;

		// Fill stack with some numbers
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		// Test iterator functionality
		std::cout << "\nIterating through stack:" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;

		// Compare with std::list
		std::cout << "\n=== Comparing with std::list ===" << std::endl;
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		std::cout << "List contents:" << std::endl;
		for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Test copy constructor
		std::cout << "\n=== Testing copy constructor ===" << std::endl;
		MutantStack<int> s(mstack);
		std::cout << "Copied stack contents:" << std::endl;
		for (MutantStack<int>::iterator it = s.begin(); it != s.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Test assignment operator
		std::cout << "\n=== Testing assignment operator ===" << std::endl;
		MutantStack<int> s2;
		s2 = mstack;
		std::cout << "Assigned stack contents:" << std::endl;
		for (MutantStack<int>::iterator it = s2.begin(); it != s2.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		// Test with different data type
		std::cout << "\n=== Testing with string type ===" << std::endl;
		MutantStack<std::string> strStack;
		strStack.push("Hello");
		strStack.push("World");
		strStack.push("!");

		for (MutantStack<std::string>::iterator it = strStack.begin();
			 it != strStack.end(); ++it)
			 {}
				std::cout << *it << " ";
		std::cout << std::endl;

		return 0;
	}