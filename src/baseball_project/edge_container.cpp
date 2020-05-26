#include "edge_container.h"

EdgeContainer::EdgeContainer()
{
    // intentionally left empty
}

int EdgeContainer::find_connection(string stadium_a, string stadium_b) const
{
    int index = -1;
    for (size_t i = 0; i < size(); i++)
    {
        if (_list[i].match(stadium_a, stadium_b))
        {
            index = i;
        }
    }
    return index;
}

int EdgeContainer::get_cost(string stadium_a, string stadium_b) const
{
    assert(connected(stadium_a, stadium_b));
    return _list[find_connection(stadium_a, stadium_b)].get_cost();
}

bool EdgeContainer::connected(string stadium_a, string stadium_b) const
{
    return (find_connection(stadium_a, stadium_b) >= 0);
}

void EdgeContainer::print() const
{
    for (size_t i = 0; i < size(); i++)
    {
        _list[i].print_info();
        cout << endl;
    }
    cout << endl;
}
