#include "souvenirs_container.h"

SouvenirsContainer::SouvenirsContainer()
{
    add(souvenir("Baseball cap", 25.99));
    add(souvenir("Baseball bat", 35.35));
    add(souvenir("Team pennant", 12.99));
    add(souvenir("Autographed baseball", 19.99));
}

int SouvenirsContainer::find(string souvenir_name) const
{
    int index = -1;
    for (size_t i = 0; i < size(); i++)
    {
        if (_list[i]._name == souvenir_name)
        {
            index = i;
        }
    }
    return index;
}

void SouvenirsContainer::print() const
{
    for (size_t i = 0; i < size(); i++)
    {
        cout << _list[i];
    }
    cout << endl;
}

bool SouvenirsContainer::add(const souvenir &item)
{

    if (contains(item._name))
    {
        return false;
    }

    if (size() == _allocated)
    {
        reserve(size() * 2);
    }
    _list[_size++] = item;
    return true;
}

souvenir &SouvenirsContainer::get(string souvenir_name)
{
    assert(contains(souvenir_name));

    return _list[find(souvenir_name)];
}

const souvenir &SouvenirsContainer::get(string souvenir_name) const
{
    assert(contains(souvenir_name));

    return _list[find(souvenir_name)];
}

bool SouvenirsContainer::contains(string souvenir_name) const
{
    return (find(souvenir_name) >= 0);
}
