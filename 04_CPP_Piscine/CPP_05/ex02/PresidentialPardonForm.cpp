#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(string const &target) : Form(target, "PresidentialPardonForm", 72, 45)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	this->Form::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::action(Bureaucrat const &executer) const
{
	this->Form::execute(executer);
	cout << "The " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << endl;
}
