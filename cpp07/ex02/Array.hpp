#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>
#include <exception>




template <typename T> class Array
{
	private :
		 T 			*Arr;
		unsigned int length;

	public :

		Array(void) {
			*Arr = NULL;
			length = 0;
		}



		Array(unsigned int n)
		{
			length = n;
			Arr = new T[n];
		}



		Array(Array const &copy)
		{
			*this = copy;
		}


		~Array(void) {
			delete[] Arr;
		}


		Array &operator = (Array const &rhs)
		{
			if (this != &rhs)
			{
				Arr = new T[rhs.length];
				for (size_t i = 0; i < rhs.length; i++)
					Arr[i] = rhs.Arr[i];
				length = rhs.length;
			}
			return (*this);
		}



	T &operator[](unsigned int index)
	{
		if (index >= length)
			throw OutOfBounds();
		return Arr[index];
	}


	const T& operator[](unsigned int index) const {
		if (index >= length)
			throw OutOfBounds();
		return Arr[index];
	}


	unsigned int size() const
	{
		return (length);
	}


	class OutOfBounds : public std::exception       {
		virtual const char* what() const throw()        {
				return ("Out of bounds");
		}
};
};


#endif