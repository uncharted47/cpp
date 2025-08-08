#include "Array.hpp"



template <typename T>
Array<T>::Array() : Arr(NULL), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : length(n) {
    Arr = new T[n];
    if (!Arr) {
        std::cerr << "Memory allocation failed" << std::endl;
        exit(1);
    }
}

template <typename T>
Array<T>::Array(Array const &copy) : Arr(NULL), length(0) {
    *this = copy;
}

template <typename T>
Array<T>::~Array() {
    delete[] Arr;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs) {
    if (this != &rhs) {
        delete[] Arr;
        Arr = new T[rhs.length];
        for (unsigned int i = 0; i < rhs.length; i++)
            Arr[i] = rhs.Arr[i];
        length = rhs.length;
    }
    return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if(!Arr)
        throw std::runtime_error("Array is not initialized");
    if (index >= length)
        throw std::runtime_error("Out of bounds");
    return Arr[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if(!Arr)
        throw std::runtime_error("Array is not initialized");
    if (index >= length)
        throw std::runtime_error("Out of bounds");
    return Arr[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return length;
}