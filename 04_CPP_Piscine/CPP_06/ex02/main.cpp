#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    switch (rand() % 3)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return NULL;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        cout << "A" << endl;
    else if (dynamic_cast<B *>(p))
        cout << "B" << endl;
    else if (dynamic_cast<C *>(p))
        cout << "C" << endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        cout << "A" << endl;
        return;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        cout << "B" << endl;
        return;
    }
    catch(...) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        cout << "C" << endl;
        return;
    }
    catch(...) {}
}

int main(void)
{
    cout << "Now the Base* p:" << endl;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        Base *p = generate();
        identify(p);
    }

    cout << "\nNow the Base& p:" << endl;
    srand(time(NULL));
    for (int i = 0; i < 10; ++i)
    {
        Base *p = generate();
        identify(*p);
    }

    return 0;
}