#include "stadium_container.h"

StadiumContainer::StadiumContainer()
{
    _allocated = 10;
    _stadium_list = new Stadium [_allocated];
    _size = 0;
}


bool StadiumContainer::add(Stadium stadium){
    // some condition: return false;
    if (size() == _allocated){
        reserve(size()*2);
    }
    _stadium_list[_size++] = stadium;
    return true;
}


bool StadiumContainer::remove(size_t index){
    assert(index < size() && index >= 0);
    for (size_t i=index+1; i<size(); i++){
        _stadium_list[i-1] = _stadium_list[i];
    }
    _size--;
    return true;
}


void StadiumContainer::reserve(size_t n){
    assert(n > _allocated);
    Stadium* temp = _stadium_list;
    _allocated = n;
    _stadium_list = new Stadium [_allocated];
    for (size_t i=0; i<size(); i++){
        _stadium_list[i] = temp[i];
    }
    delete[] temp;
}


const Stadium& StadiumContainer::operator[](size_t index) const{
    assert(index < size() && index >= 0);
    return _stadium_list[index];
}

void StadiumContainer::print(){
    for (size_t i=0; i<size(); i++){
        cout<<_stadium_list[i].get_stadium_name()<<" ";
    }
    cout<<endl;
}
