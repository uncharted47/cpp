#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>
#include <iostream>
#include <vector>
template <typename T>
int easyfind(T &container, int integer)
{
    typename T::iterator it = std::find(container.begin(), container.end(), integer);
    if (it == container.end())
        throw std::runtime_error("No Matching Value");
    return *it;
}
#endif