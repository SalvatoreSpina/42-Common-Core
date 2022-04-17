#if !defined(FORM_HPP)
#define FORM_HPP

#include <iostream>
#include <fstream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::cerr;
using std::exception;

class Bureaucrat;

class Form
{
private:
	const string target;
	const string name;
	bool sign;
	const int signGrade;
	const int execGrade;
	Form() : target(""), name(""), signGrade(42), execGrade(42){};

public:
	Form(string const &target, string const &name, int signGrade, int execGrade);
	Form(Form const &other);
	Form &operator=(Form const &other);
	virtual ~Form();

	string getTarget() const;
	string getName() const;
	bool getSign() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void beSigned(Bureaucrat const &bureaucrat);

	void execute(Bureaucrat const &executor) const;

	virtual void action(Bureaucrat const &executor) const = 0;

	class GradeTooLowException : public exception
	{
	public:
		const char *what() const throw()
		{
			return ("Grade too low");
		}
	};

	class NotSignedException : public exception
	{
	public:
		const char *what() const throw()
		{
			return ("Not signed");
		}
	};
};

ostream &operator<<(ostream &os, Form const &form);

#endif