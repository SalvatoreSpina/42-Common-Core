#include "Scalar.hpp"

static string	decimal(float value) {
	return (isfinite(value) && !(value - nearbyint(value)) ? ".0" : "");
}

static string	decimal(double value) {
	return (isfinite(value) && !(value - nearbyint(value)) ? ".0" : "");
}

int	main(int argc, char *argv[]) {
	string			str;

	if (argc != 2) {
		cout << "Only 1 argument!" << endl;
		return (1);
	}

	str = argv[1];
	if (!str[0]) {
		cout << "No empty string!" << endl;
		return (2);
	}

	Scalar				scalar(str);

	cout << "char: ";
	try {
		char			letter;

		letter = static_cast<char>(scalar);
		cout << "'" << letter << "'";
	} catch (Scalar::NotPrintableException &e) {
		cout << e.what();
	} catch (Scalar::NotPossibleException &e) {
		cout << e.what();
	}
	cout << endl;

	cout << "int: ";
	try {
		cout << static_cast<int>(scalar);
	} catch (Scalar::NotPossibleException &e) {
		cout << e.what();
	}
	cout << endl;

	cout << "float: ";
	try {
		cout << static_cast<float>(scalar) << decimal(static_cast<float>(scalar)) << "f";
	} catch (Scalar::NotPossibleException &e) {
		cout << e.what();
	}
	cout << endl;

	cout << "double: ";
	try {
		cout << static_cast<double>(scalar) << decimal(static_cast<double>(scalar));
	} catch (Scalar::NotPossibleException &e) {
		cout << e.what();
	}
	cout << endl;

	return (0);
}