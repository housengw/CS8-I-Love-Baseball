#include "edge_container.h"

EdgeContainer::EdgeContainer()
{
    //intentionally left empty
}


int EdgeContainer::find_connection(string stadium_a, string stadium_b){
    int index = -1;
    for (size_t i=0; i<size(); i++){
        if (_list[i].match(stadium_a, stadium_b)){
            index = i;
        }
    }
    return index;
}


bool EdgeContainer::connected(string stadium_a, string stadium_b){
    return (find_connection(stadium_a, stadium_b) >= 0);
}


void EdgeContainer::print(){
    for (size_t i=0; i<size(); i++){
        _list[i].print_info();
        cout<<endl;
    }
    cout<<endl;
}
