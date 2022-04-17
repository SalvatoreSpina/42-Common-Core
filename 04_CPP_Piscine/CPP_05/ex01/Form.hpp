#ifndef FORM_H
#define FORM_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::cerr;

class Bureaucrat;

class Form
{
private:
    const string	name;
	bool            flagSign;
    const int       signGrade;
    const int       exeGrade;
	
	Form() : name(""), signGrade(1), exeGrade(1){}

public:
	Form(string const &name, int signGgrade, int exeGrade);
	Form(Form const &other);
	Form &operator=(Form const &other);
	~Form();

	string	getName() const;
    bool getFlagSign() const;
    int getSignGrade() const;
    int getExecGrade() const;

	void beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too high");
		} 
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too low");
		} 
	};
};

ostream &operator<<(ostream &os, Form const &Form);

#endif