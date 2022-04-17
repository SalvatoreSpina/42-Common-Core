#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

typedef Form *Fn;

Form *Intern::makeForm(string const &formName, string const &target)
{
	const string formNames[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"};

	Form *(*forms[3])(string const &target) = {
		&ShrubberyCreationForm::create,
		&RobotomyRequestForm::create,
		&PresidentialPardonForm::create};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			cout << "Intern creates " << formName << endl;
			return forms[i](target);
		}
	}
	throw Intern::NotKnownFormException();
}