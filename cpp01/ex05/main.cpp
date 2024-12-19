#include "Harl.hpp"


int main(void)
{
	Harl harl;
	level levels[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	for (int i = 0; i < 4; i++)
	{
		(harl.*(levels[i].func))();
	}
	return 0;
}