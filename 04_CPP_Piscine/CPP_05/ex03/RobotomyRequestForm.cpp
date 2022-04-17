#include <cstdlib>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(string const &target) : Form(target, "RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	this->Form::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::action(Bureaucrat const &executer) const
{
	this->Form::execute(executer);
	cout << "\a";

	if (rand() % 2 == 0)
		cout << this->getTarget() << " is a robot!\n";
	else
		cout << this->getTarget() << " is human!\n";
}

Form *RobotomyRequestForm::create(string const &target)
{
	return new RobotomyRequestForm(target);
}