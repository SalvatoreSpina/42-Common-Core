#if !defined(INTERN_HPP)
#define INTERN_HPP

#include <iostream>
#include "Form.hpp"

using std::cout;
using std::endl;
using std::string;
using std:: exception;

class Intern
{
private:
public:
	Intern() {}
	Intern(Intern const &) {}
	~Intern() {}

	Intern& operator=(Intern const &);
	Form *makeForm(string const &formName, string const &target);

	class NotKnownFormException : public exception
	{
	public:
		const char *what() const throw()
		{
			return ("Intern can't create form they don't know");
		}
	};
};

#endif