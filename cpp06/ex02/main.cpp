#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base *b = new B();
 	C c_obj;  
    Base &c = c_obj;  

	identify(b);
	identify(c);
	delete b;
}