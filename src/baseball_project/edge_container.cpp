#include "edge_container.h"

EdgeContainer::EdgeContainer()
{
    _allocated = 10;
    _edge_list = new Edge [_allocated];
    _size = 0;
}


EdgeContainer::~EdgeContainer ()
{
    delete [] _edge_list;
} //destructor


EdgeContainer& EdgeContainer::operator = (const EdgeContainer& rhs)
{
    if (this == &rhs) return *this;
    if (_edge_list != nullptr) delete [] _edge_list;
    _size = rhs._size;
    _allocated = rhs._allocated;
    _edge_list = new Edge [rhs._allocated];
    std::copy(rhs._edge_list, rhs._edge_list + rhs._size, _edge_list);
    return *this;
} //assginment operator


EdgeContainer::EdgeContainer(const EdgeContainer &source)
{
    _size = source._size;
    _allocated = 2*source._size;
    _edge_list = new Edge [_allocated];
    std::copy(source._edge_list, source._edge_list + source._size, _edge_list);
} //copy constructor


bool EdgeContainer::add(const Edge& edge){
    // some condition: return false;
    if (size() == _allocated){
        reserve(size()*2);
    }
    _edge_list[_size++] = edge;
    return true;
}


bool EdgeContainer::remove(size_t index){
    assert(index < size() && index >= 0);
    for (size_t i=index+1; i<size(); i++){
        _edge_list[i-1] = _edge_list[i];
    }
    _size--;
    return true;
}


void EdgeContainer::reserve(size_t n){
    assert(n > _allocated);
    Edge* temp = _edge_list;
    _allocated = n;
    _edge_list = new Edge [_allocated];
    std::copy(temp, temp+size(), _edge_list);
    delete[] temp;
}


const Edge& EdgeContainer::operator[](size_t index) const{
    assert(index < size() && index >= 0);
    return _edge_list[index];
}


Edge& EdgeContainer::operator[](size_t index){
    assert(index < size() && index >= 0);
    return _edge_list[index];
}

void EdgeContainer::print(){
    for (size_t i=0; i<size(); i++){
        _edge_list[i].print_info();
        cout<<endl;
    }
    cout<<endl;
}
