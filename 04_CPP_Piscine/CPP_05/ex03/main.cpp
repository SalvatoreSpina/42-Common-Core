#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

void test_form(Form &form, Bureaucrat &correct, Bureaucrat &wrong)
{
	wrong.signForm(form);
	correct.executeForm(form);
	correct.signForm(form);
	wrong.executeForm(form);
	correct.executeForm(form);
}

int main()
{
	srand(time(NULL));

	Bureaucrat achansel("achansel", 1);
	Bureaucrat wrong("wrong", 150);
	Intern intern;

	Form *form;

	form = intern.makeForm("ShrubberyCreationForm", "target");
	test_form(*form, achansel, wrong);
	delete form;
	cout << endl;
	form = intern.makeForm("RobotomyRequestForm", "target");
	test_form(*form, achansel, wrong);
	delete form;
	cout << endl;
	form = intern.makeForm("PresidentialPardonForm", "target");
	test_form(*form, achansel, wrong);
	delete form;

	try
	{
		form = intern.makeForm("WrongName", "target");
		test_form(*form, achansel, wrong);
		delete form;
	}
	catch (exception &e)
	{
		cerr << e.what() << endl;
	}

	return 0;
}