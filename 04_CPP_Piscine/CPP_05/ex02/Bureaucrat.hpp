#if !defined(BURECRAT_HPP)
#define BURECRAT_HPP

#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::cerr;
using std::exception;

class Form;

class Bureaucrat
{
private:
	const string name;
	int grade;

	Bureaucrat() : name(""){};

public:
	Bureaucrat(string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	string getName() const;
	int getGrade() const;
	void increaseGrade(int amount);
	void decreaseGrade(int amount);

	void signForm(Form &form);
	void executeForm(Form &form);

	class GradeTooHighException : public exception
	{
	public:
		const char *what() const throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public exception
	{
	public:
		const char *what() const throw()
		{
			return ("Grade too low");
		}
	};
};

ostream &operator<<(ostream &os, Bureaucrat const &bureaucrat);

#endif