#include "point_container.h"

PointContainer::PointContainer()
{
    //intentionally left empty
}


int PointContainer::find(string point_name) const{
    int index = -1;
    for (size_t i=0; i<size(); i++){
        if (_list[i].get_name() == point_name){
            index = i;
        }
    }
    return index;
}

void PointContainer::print(){
    for (size_t i=0; i<size(); i++){
        cout<<"("<<_list[i].get_x()<<", "
            <<_list[i].get_y()<<") "
            <<_list[i].get_name()<<endl;
        cout<<endl;
    }
    cout<<endl;
}

