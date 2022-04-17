#pragma once

#include <iostream>
#include <limits>
#include <cmath>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::string;
using std::exception;
using std::numeric_limits;

class Scalar {
private:
	double			value;

public:
	Scalar(void);
	Scalar(string str);
	Scalar(Scalar const &src);

	~Scalar(void);
	Scalar			&operator=(Scalar const &src);
	int				toInt(void);
	char			toChar(void);
	float			toFloat(void);
	double			toDouble(void);

	class NotPrintableException: public exception {
		public:
			virtual const char *what() const throw();
	};
	class NotPossibleException: public exception {
		public:
			virtual const char *what() const throw();
	};

	operator		int(void) { return (this->toInt()); }
	operator		char(void) { return (this->toChar()); }
	operator		float(void) { return (this->toFloat()); }
	operator		double(void) { return (this->toDouble()); }
};