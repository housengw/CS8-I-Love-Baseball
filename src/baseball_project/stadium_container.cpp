#include "stadium_container.h"

StadiumContainer::StadiumContainer()
{
    _allocated = 10;
    _stadium_list = new Stadium [_allocated];
    _size = 0;
}


StadiumContainer::~StadiumContainer ()
{
    delete [] _stadium_list;
} //destructor


StadiumContainer& StadiumContainer::operator = (const StadiumContainer& rhs)
{
    if (this == &rhs) return *this;
    if (_stadium_list != nullptr) delete [] _stadium_list;
    _size = rhs._size;
    _allocated = rhs._allocated;
    _stadium_list = new Stadium [rhs._allocated];
    std::copy(rhs._stadium_list, rhs._stadium_list + rhs._size, _stadium_list);
    return *this;
} //assginment operator


StadiumContainer::StadiumContainer(const StadiumContainer &source)
{
    _size = source._size;
    _allocated = 2*source._size;
    _stadium_list = new Stadium [_allocated];
    std::copy(source._stadium_list, source._stadium_list + source._size, _stadium_list);
} //copy constructor


StadiumContainer StadiumContainer::stadiums_grass_surface ( )
{
    StadiumContainer temp;
    string surface;
    for(size_t i = 0; i < _size; i++){
        surface = _stadium_list[i].get_surface() ;
        if (surface == GRASS_SURFACE_NAME){
            temp.add(_stadium_list[i]);
        }
    }
    return temp;
}


bool StadiumContainer::add(const Stadium &stadium){
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


int StadiumContainer::find(string stadium_name) const{
    int index = -1;
    for (size_t i=0; i<size(); i++){
        if (_stadium_list[i].get_stadium_name() == stadium_name){
            index = i;
        }
    }
    return index;
}


void StadiumContainer::reserve(size_t n){
    assert(n > _allocated);
    Stadium* temp = _stadium_list;
    _allocated = n;
    _stadium_list = new Stadium [_allocated];
    std::copy(temp, temp+size(), _stadium_list);
    delete[] temp;
}


const Stadium& StadiumContainer::operator[](size_t index) const{
    assert(index < size() && index >= 0);
    return _stadium_list[index];
}


Stadium& StadiumContainer::operator[](size_t index){
    assert(index < size() && index >= 0);
    return _stadium_list[index];
}

void StadiumContainer::print(){
    for (size_t i=0; i<size(); i++){
        _stadium_list[i].print_info();
        cout<<endl;
    }
    cout<<endl;
}
