#include "Scalar.hpp"

static int	notPossible_char(double value);
static int	notPossible_int(double value);

Scalar::Scalar(string str) {
	if (str.length() == 1 && !('0' <= str[0] && str[0] <= '9')) {
		this->value = static_cast<double>(str[0]);
	} else {
		this->value = static_cast<double>(atof(str.c_str()));
	}
}
Scalar::Scalar(Scalar const &src) {
	(*this) = src;
}

Scalar::~Scalar(void) {
	return ;
}

Scalar	&Scalar::operator=(Scalar const &src) {
	(void) src;

	return (*this);
}

char	Scalar::toChar(void) {
	if (notPossible_char(this->value))
		throw Scalar::NotPossibleException();
	if (isprint(this->value)) {
		return (this->value);
	} else {
		throw Scalar::NotPrintableException();
	}
}

int	Scalar::toInt(void) {
	if (notPossible_int(this->value))
		throw Scalar::NotPossibleException();
	return (static_cast<int>(this->value));
}

float	Scalar::toFloat(void) {
	if ((this->value < numeric_limits<float>::min()
			&& numeric_limits<float>::max() < this->value))
		throw Scalar::NotPossibleException();
	return (static_cast<float>(this->value));
}

double	Scalar::toDouble(void) {
	if ((this->value < numeric_limits<double>::min()
			&& numeric_limits<double>::max() < this->value))
		throw Scalar::NotPossibleException();
	return (this->value);
}

const char *Scalar::NotPrintableException::what() const throw() {
	return ("Not printable");
}

const char *Scalar::NotPossibleException::what() const throw() {
	return ("Impossible");
}

static int	notPossible_char(double value) {
	return (
		value < numeric_limits<char>::min() ||
		value > numeric_limits<char>::max()
	) || !isfinite(value);
}

static int	notPossible_int(double value) {
	return (
		value < numeric_limits<int>::min() ||
		value > numeric_limits<int>::max()
	) || !isfinite(value);
}