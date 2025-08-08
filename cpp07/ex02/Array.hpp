#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <iostream>
#include <cstdlib>

template <typename T>
class Array {
private:
    T* Arr;
    unsigned int length;

public:
    Array();
    Array(unsigned int n);
    Array(Array const& copy);
    ~Array();
    Array& operator=(Array const& rhs);

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
};

#include "Array.tpp"

#endif