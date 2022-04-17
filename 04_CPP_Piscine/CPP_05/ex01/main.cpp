#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat achansel("achansel", 10);

	try
	{
		achansel.increaseGrade(9);
		cout << achansel << endl;
		achansel.increaseGrade(1);
		cout << achansel << endl;
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
	}

	Form formA("a", 10, 10);
	Form formB("b", 10, 10);
	achansel.signForm(formA);
	achansel.decreaseGrade(10);
	achansel.signForm(formB);
	cout << formA << endl;
	cout << formB << endl;
	return 0;
}