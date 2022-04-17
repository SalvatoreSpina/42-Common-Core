#include "Brain.hpp"

Brain::Brain()
{
    const string ideas[] = {
        "eat",
        "sleep",
        "mlmlml",
        "run",
        "walk",
    };

    cout << "Constructor Brain:";
    for (int i = 0; i < 100; ++i)
    {
        this->ideas[i] = ideas[rand() % (sizeof(ideas) / sizeof(string))];
        cout << " " << this->ideas[i];
    }
    cout << endl;
}

Brain::Brain(Brain const &other)
{
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.getIdea(i);
}

Brain &Brain::operator=(Brain const &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i] = other.getIdea(i);
    }
    return *this;
}

Brain::~Brain()
{
    cout << "Destructor Brain:";
    for (int i = 0; i < 100; ++i)
            cout << " " << this->ideas[i];
    cout << endl;
}

string const &Brain::getIdea(int index) const
{
    return this->ideas[index];
}