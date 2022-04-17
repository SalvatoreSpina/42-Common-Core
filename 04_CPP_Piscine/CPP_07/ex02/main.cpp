#include "Array.hpp"

int main(void)
{
    Array<string> array(5);

    for (int i = 0; i < 5; i++)
        array[i] = string("Hello" + to_string(i));

    for (int i = 0; i < 5; i++)
        cout << array[i] << endl;

    Array<string> array2;
    array2 = array;

    for (int i = 0; i < 5; i++)
        cout << array2[i] << endl;

    try {
        cout << array2[6] << endl;
    }
    catch (const exception &e)
	{
		cout << e.what() << endl;
	}

    return (0);
}