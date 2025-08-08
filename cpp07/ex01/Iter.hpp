#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <string>
template <typename T, typename F>
void iter(T *array, int length, F function)
{
	if(!array || !function || length < 0)
		return;
	for(int i = 0; i < length; i++)
		function(array[i]);

}

#endif
