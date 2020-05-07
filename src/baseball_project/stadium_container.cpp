#include "stadium_container.h"

StadiumContainer::StadiumContainer()
{
    _allocated = 10;
    _stadium_list = new Stadium [_allocated];
    _size = 0;
}

StadiumContainer::~StadiumContainer ()
{
    bool debug = false;
    if (debug)
        cout<<endl << "~ MemberContainer() Destructor"<<endl;
    delete [] _stadium_list;
} //destructor

StadiumContainer& StadiumContainer::operator = (const StadiumContainer& RHS)
{
    bool debug = false;
    if (debug)
        cout<<"MemberContainer& operator = ( ) Assignment "<<endl;

    if (_stadium_list == RHS._stadium_list){
        return *this;
    }
    if (_stadium_list != nullptr){
        delete [] _stadium_list;
    }

    _size = RHS._size;
    _allocated = RHS._allocated;
    _stadium_list = new value_type [RHS._allocated];

    std::copy(RHS._stadium_list, RHS._stadium_list + RHS._size, _stadium_list);

    return *this;

} //assginment operator

StadiumContainer::StadiumContainer (const StadiumContainer &source)
{
    bool debug = false;
    if (debug)
        cout<<endl <<"MemberContainer(MemberContainer copy) COPY CTOR" <<endl;

    _size = source._size;
    _allocated = 2*source._size;
    _stadium_list = new value_type [_allocated];
    std::copy(source._stadium_list, source._stadium_list + source._size, _stadium_list);

} //copy constructor

StadiumContainer StadiumContainer::stadiums_grassSurface ( )
{
    StadiumContainer temp;
    string surface;
    for(size_t i = 0; i < _size; i++){
        surface = _stadium_list[i].get_surface() ;
        surface.pop_back();
        if (surface == "Grass"){
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
//    _stadium_list[_size++] = stadium;

    _stadium_list[_size] = stadium;
    _size++;

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


Stadium& StadiumContainer::operator[](size_t index) {
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
