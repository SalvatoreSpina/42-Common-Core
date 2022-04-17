#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(string const &name, size_t grade) : name(name)
{
	if (grade <= 0)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name)
{
	this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

string Bureaucrat::getName() const
{
	return (this->name);
}

size_t Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::increaseGrade(size_t amount)
{
	if (this->grade - amount <= 0)
			throw Bureaucrat::GradeTooHighException();
	if (this->grade - amount > 150)
			throw Bureaucrat::GradeTooLowException();
	this->grade -= amount;
}

void Bureaucrat::decreaseGrade(size_t amount)
{
	if (this->grade + amount <= 0)
			throw Bureaucrat::GradeTooHighException();
	if (this->grade + amount > 150)
			throw Bureaucrat::GradeTooLowException();
	this->grade += amount;
}

ostream &operator<<(ostream &os, Bureaucrat const &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (os);
}