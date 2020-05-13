#include "stadium_container.h"

StadiumContainer::StadiumContainer()
{
    //intentionally left empty
}

StadiumContainer StadiumContainer::stadiums_grass_surface()
{
    StadiumContainer temp;
    string surface;
    for(size_t i = 0; i < _size; i++){
        surface = _list[i].get_surface() ;
        if (surface == GRASS_SURFACE_NAME){
            temp.add(_list[i]);
        }
    }
    return temp;
}

StadiumContainer StadiumContainer::stadiums_turf_surface()
{
    StadiumContainer temp;
    string surface;
    for(size_t i = 0; i < _size; i++){
        surface = _list[i].get_surface() ;
        if (surface == TURF_SURFACE_NAME){
            temp.add(_list[i]);
        }
    }
    return temp;
}

int StadiumContainer::find(string stadium_name) const{
    int index = -1;
    for (size_t i=0; i<size(); i++){
        if (_list[i].get_stadium_name() == stadium_name){
            index = i;
        }
    }
    return index;
}


bool StadiumContainer::contains(string stadium_name) const{
    return (find(stadium_name) >= 0);
}


void StadiumContainer::print() const{
    for (size_t i=0; i<size(); i++){
        _list[i].print_info();
        cout<<endl;
    }
    cout<<endl;
}
