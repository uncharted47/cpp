#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <string>
template <typename T>
void iter(T *array, int length, void (*function)(T&))
{
	if(!array || !function || length < 0)
		return;
	for(int i = 0; i < length; i++)
		function(array[i]);

}

#endif
