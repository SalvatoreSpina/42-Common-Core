#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(string const &name, int signGrade, int exeGrade) : name(name), signGrade(signGrade), exeGrade(exeGrade)
{
	if (signGrade <= 0 || exeGrade <= 0)
		throw Bureaucrat::GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Form::Form(Form const &other) : name(other.getName()), signGrade(other.getSignGrade()), exeGrade(other.getExecGrade())
{
	this->flagSign = other.flagSign;
}

Form &Form::operator=(Form const &other)
{
	this->flagSign = other.flagSign;
	return (*this);
}

Form::~Form()
{
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->exeGrade)
		throw Form::GradeTooLowException();
	this->flagSign = true;
}

string Form::getName() const
{
	return (this->name);
}

bool Form::getFlagSign() const
{
	return (this->flagSign);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

int Form::getExecGrade() const
{
	return (this->exeGrade);
}

ostream &operator<<(ostream &os, Form const &form)
{
	os << "< " << form.getName() << " flagSign : " << form.getSignGrade() << ", exec : " << form.getExecGrade();
	if (form.getFlagSign())
			os << ", signed";
	else
			os << ", not signed";
	os << " >";
	return (os);
}