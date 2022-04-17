#include "Serialize.hpp"

int main(void)
{
	Data achansel;

	achansel.name = "Achansel";
	achansel.age = 18;

	uintptr_t out = serialize(&achansel);
	Data *data = deserialize(out);

	cout << "Name: " << data->name << endl;
	cout << "Age: " << data->age << endl;
}