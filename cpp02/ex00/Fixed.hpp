#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
	private :
		int _fixedPointValue;
		static const int _fractionalBits = 8;

	public :
		Fixed(void);
		Fixed(Fixed const &copy);
		~Fixed(void);
		Fixed const &operator = (Fixed const &obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif