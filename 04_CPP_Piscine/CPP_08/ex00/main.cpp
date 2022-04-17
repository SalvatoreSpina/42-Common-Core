#include "easyfind.hpp"

int main(void)
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> v(arr, arr + sizeof(arr) / sizeof(int));

	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		cout << *it << ' ';
	cout << endl;

	try
	{
		cout << "He will find this: " << *easyfind(v, 5) << endl;
		cout << "But not this, and he will throw an exception: \n" << *easyfind(v, 42) << endl;
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	return (0);
}