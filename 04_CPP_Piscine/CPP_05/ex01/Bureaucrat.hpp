#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include "Form.hpp"

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::cerr;

class Bureaucrat
{
private:
    const string	name;
	int			grade;

	Bureaucrat() : name(""){};

public:
	Bureaucrat(string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	string	getName() const;
	int	getGrade() const;
	void	increaseGrade(int amount);
	void	decreaseGrade(int amount);
	void signForm(Form &form);

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

ostream &operator<<(ostream &os, Bureaucrat const &bureaucrat);

#endif