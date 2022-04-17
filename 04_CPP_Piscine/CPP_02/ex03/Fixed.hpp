#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Fixed
{
public:
	Fixed(void);							
	Fixed(int const val);
	Fixed(float const val);
	Fixed(const Fixed& fixed);				
	~Fixed(void);							

	Fixed& operator=(const Fixed& other);		

	bool operator>(const Fixed& other);		
	bool operator<(const Fixed& other);		
	bool operator>=(const Fixed& other);		
	bool operator<=(const Fixed& other);		
	bool operator==(const Fixed& other);		
	bool operator!=(const Fixed& other);		

	Fixed operator+(const Fixed& other);	
	Fixed operator-(const Fixed& other);	
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);	

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	int getRawBits(void) const;

	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
	static			Fixed& min(Fixed& a, Fixed& b);
	static const	Fixed& min(const Fixed& a, const Fixed& b);
	static			Fixed& max(Fixed& a, Fixed& b);
	static const	Fixed& max(const Fixed& a, const Fixed& b);

private:
	static int const rawBits = 8;
	int value;
};

ostream& operator<<(ostream& o, const Fixed& fixed);