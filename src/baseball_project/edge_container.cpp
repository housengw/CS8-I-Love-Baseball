#include "edge_container.h"

EdgeContainer::EdgeContainer()
{
    //intentionally left empty
}

void EdgeContainer::print(){
    for (size_t i=0; i<size(); i++){
        _list[i].print_info();
        cout<<endl;
    }
    cout<<endl;
}
