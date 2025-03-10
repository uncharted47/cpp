#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}



Base * generate(void)
{
	srand(time(0));
	int i = rand() % 3;
	Base *p;
	switch (i)
	{
	case 0:
		p = new A();
		return p;
	case 1 :
		p = new B();
		return p;

	case 2 :
		p = new C();
		return p;

	default :
		p =  NULL;
		return p;

	}

}


void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) {
        std::cout << "The object is of type A" << std::endl;
    }
	else if (dynamic_cast<B*>(p)) {
        std::cout << "The object is of type B" << std::endl;
	}
	else if (dynamic_cast<C*>(p)) {
	std::cout << "The object is of type C" << std::endl;
	}
	else
	std::cout << "The object is of type Base" << std::endl;

}


void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
        std::cout << "The object is of type A" << std::endl;
		return ;
		(void)a;
	}
	catch(const std::exception& e)
	{
	}

	try
	{
		B &b = dynamic_cast<B&>(p);
        std::cout << "The object is of type B" << std::endl;
		return ;
		(void) b;

	}
	catch(const std::exception& e)
	{
	}


	try
	{
		C &c = dynamic_cast<C&>(p);
        std::cout << "The object is of type C" << std::endl;
		return ;
		(void)c;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "The object is of type Base" << std::endl;
	return ; 
}