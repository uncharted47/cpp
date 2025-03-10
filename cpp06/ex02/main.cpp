#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base *b = new B();
 	C c_obj;  // Create an actual object, not a temporary
    Base &c = c_obj;  // Reference to the object

	identify(b);
	identify(c);
	delete b;
}