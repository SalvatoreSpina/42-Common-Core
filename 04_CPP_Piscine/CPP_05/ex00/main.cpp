#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat test("Sasso Stark", 10);


	cout << "I just created:\n" << test << "\n" << endl;

	try
	{
		test.increaseGrade(9);
		cout << test << endl;
		test.increaseGrade(1);
		cout << test << endl;
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
	}

	cout << "Now, he's\n" << test << "\n" << endl;
	try
	{
		test.decreaseGrade(140);
		cout << test << endl;
		test.decreaseGrade(10);
		cout << test << endl;
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
	}
}