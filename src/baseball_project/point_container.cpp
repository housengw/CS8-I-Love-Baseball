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


bool PointContainer::contains(string point_name) const{
    return (find(point_name) >= 0);
}


Point PointContainer::get_coordinates(string point_name) const{
    assert(contains(point_name));
    for (size_t i=0; i<size(); i++){
        if (_list[i].get_name() == point_name){
            return _list[i];
        }
    }
    return Point();
}


void PointContainer::print(){
    for (size_t i=0; i<size(); i++){
        cout<<"("<<_list[i].get_x()<<", "
            <<_list[i].get_y()<<") "
            <<_list[i].get_name();
        cout<<endl;
    }
    cout<<endl;
}

