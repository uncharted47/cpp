#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
#include <cmath>
// #include
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
		Fixed operator - (Fixed const &obj) const;
		Fixed operator+(Fixed const &obj);
		Fixed operator*(Fixed const &obj);
		Fixed operator/(Fixed const &obj);
		bool operator>(Fixed const &obj);
		bool operator<(Fixed const &obj);
		bool operator>=(Fixed const &obj);
		bool operator<=(Fixed const &obj);
		bool operator==(Fixed const &obj);
		bool operator!=(Fixed const &obj);
		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(Fixed const &a, Fixed const &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(Fixed const &a, Fixed const &b);

};

	std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif