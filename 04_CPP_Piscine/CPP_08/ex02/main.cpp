#include "MutantStack.cpp"

int main(void)
{
	cout << "Sample Stack test:" << endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	cout << "top : " << mstack.top() << endl;

	mstack.pop();
	cout << "top : " << mstack.top() << endl;
	cout << "size : " << mstack.size() << endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();

	for (; it != mstack.end(); it++)
		cout << "value : " << *it << endl;

	cout << endl;
	cout << "And this is the list, it should be equal:" << endl;

	list<int> list;

	list.push_back(5);
	list.push_back(17);

	cout << "top : " << list.back() << endl;

	list.pop_back();
	cout << "top : " << list.back() << endl;
	cout << "size : " << list.size() << endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator l_it = list.begin();

	for (; l_it != list.end(); l_it++)
		cout << "value : " << *l_it << endl;
	cout << endl;

return 0;
}