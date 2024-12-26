#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
#include <cmath>
#include <ostream>
class Fixed
{
	private :
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public :
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &copy);
		~Fixed(void);
		Fixed const &operator = (Fixed const &obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

	std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif