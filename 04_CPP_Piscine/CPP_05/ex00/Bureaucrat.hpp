#ifndef Bureaucrat_H
#define Bureaucrat_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::cerr;

class Bureaucrat
{
private:
    const string	name;
	size_t			grade;

	Bureaucrat() : name(""){};

public:
	Bureaucrat(string const &name, size_t grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	string	getName() const;
	size_t	getGrade() const;
	void	increaseGrade(size_t amount);
	void	decreaseGrade(size_t amount);

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