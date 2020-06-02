#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>

using namespace std;

template <class T>
class Container
{
public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Container();

    /****************************************
    **  BIG 3  **
    *****************************************/
    virtual ~Container();                         //destructor
    Container& operator = (const Container& rhs); //assginment operator
    Container (const Container &copy_this);       //copy constructor

    virtual bool add(const T& item);
    bool remove(size_t index);
    void reserve(size_t n);
    size_t size() const{return _size;}
    bool empty() const{return _size == 0;}
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    const T& at(size_t index) const;
    T& at(size_t index);

    void operator += (const Container &add);
    Container<T>& operator+(Container<T> rhs);
    Container<T>& operator+(T rhs);

protected:
    T* _list;            //IN/OUT list of items type T
    size_t _allocated;   //IN/OUT allocated capacity of list
    size_t _size;        //IN/OUT size of list
};


/****************************************
**  CONSTRUCTORS  **
*****************************************/
/*******************************************************************
* Container();
*
* allocate memory for the container and initialize the size to 0.
*------------------------------------------------------------------
* Parameter: nothing
*------------------------------------------------------------------
* Return: nothing
*******************************************************************/
template <class T>
Container<T>::Container(){
    _allocated = 10;
    _list = new T [_allocated];
    _size = 0;
}


/****************************************
**  BIG 3  **
*****************************************/
/*******************************************************************
* ~Container();
*
* deletes the container class
*------------------------------------------------------------------
* Parameter: nothing
*------------------------------------------------------------------
* Return: nothing
*******************************************************************/
template <class T>
Container<T>::~Container()
{
    delete[] _list;
}


/*******************************************************************
* Container<T>& operator= (const Container<T>& rhs)
*
* sets this container class to be the same as rhs
*------------------------------------------------------------------
* Parameter: rhs (Container<T>) //the container that this container
*                               //    will be set equal to
*------------------------------------------------------------------
* Return: a reference to this container class
*******************************************************************/
template <class T>
Container<T>& Container<T>::operator= (const Container<T>& rhs)
{
    if (this == &rhs) return *this;
    if (_list != nullptr) delete [] _list;
    _size = rhs._size;
    _allocated = rhs._allocated;
    _list = new T [rhs._allocated];
    for (size_t i=0; i<rhs.size(); i++){
        _list[i] = rhs._list[i];
    }
    std::copy(rhs._list, rhs._list + rhs._size, _list);
    return *this;
}


/*******************************************************************
* Container(const Container<T>& other)
*
* constructs this container class to be the same as other
*------------------------------------------------------------------
* Parameter: other (Container<T>) //the container that this container
*                                 //    will be constructed on
*------------------------------------------------------------------
* Return: nothing
*******************************************************************/
template <class T>
Container<T>::Container(const Container<T>& other){
    _size = other._size;
    _allocated = 2*other._size;
    _list = new T [_allocated];
    std::copy(other._list, other._list + other._size, _list);
}


/*******************************************************************
* bool add(const T& item)
*
* add item into the container class
*------------------------------------------------------------------
* Parameter: item (T) //the item to be added to the container class
*------------------------------------------------------------------
* Return: true if item is added. false otherwise
*******************************************************************/
template <class T>
bool Container<T>::add(const T& item){
    // some condition: return false;
    if (size() == _allocated){
        reserve(size()*2);
    }
    _list[_size++] = item;
    return true;
}


/*******************************************************************
* void remove(size_t index)
*
* removes the item at index
*------------------------------------------------------------------
* Parameter: index (size_t) //the index at which the item is removed
*------------------------------------------------------------------
* Return: true if item is removed. false otherwise
*******************************************************************/
template <class T>
bool Container<T>::remove(size_t index){
    assert(index < size() && index >= 0);
    for (size_t i=index+1; i<size(); i++){
        _list[i-1] = _list[i];
    }
    _size--; 
    return true;
}


/*******************************************************************
* void reserve(size_t n)
*
* allocates n spaces to the container
*------------------------------------------------------------------
* Parameter: n (size_t) //the amount of space to allocate
*------------------------------------------------------------------
* Return: nothing
*******************************************************************/
template <class T>
void Container<T>::reserve(size_t n){
    if (n <= _allocated) return;
    T* temp = _list;
    _allocated = n;
    _list = new T [_allocated];
    std::copy(temp, temp+size(), _list);
    delete[] temp;
}

/*******************************************************************
* const T& operator[](size_t index) const
*
* gets the item at index
*------------------------------------------------------------------
* Parameter: index (size_t) //the index at which the item is get
*------------------------------------------------------------------
* Return: the item at index
*******************************************************************/
template <class T>
const T& Container<T>::operator[](size_t index) const{
    assert(index < size() && index >= 0);
    return _list[index];
}


/*******************************************************************
* const T& operator[](size_t index) const
*
* gets the item at index
*------------------------------------------------------------------
* Parameter: index (size_t) //the index at which the item is get
*------------------------------------------------------------------
* Return: the item at index
*******************************************************************/
template <class T>
T& Container<T>::operator[](size_t index){
    assert(index < size() && index >= 0);
    return _list[index];
}

/*******************************************************************
* const T& at(size_t index) const
*
* gets the item at index
*------------------------------------------------------------------
* Parameter: index (size_t) //the index at which the item is get
*------------------------------------------------------------------
* Return: the item at index
*******************************************************************/
template <class T>
const T& Container<T>::at(size_t index) const
{
    assert(index < size() && index >= 0);
    return _list[index];
}

/*******************************************************************
* T& at(size_t index)
*
* gets the item at index
*------------------------------------------------------------------
* Parameter: index (size_t) //the index at which the item is get
*------------------------------------------------------------------
* Return: the item at index
*******************************************************************/
template <class T>
T& Container<T>::at(size_t index)
{
    assert(index < size() && index >= 0);
    return _list[index];
}

/*******************************************************************
* void operator += (const Container &add)
*
* appends all items from add to this container
*------------------------------------------------------------------
* Parameter: add (Container) //the container with items to be
*                            //    appended to this container
*------------------------------------------------------------------
* Return: nothing
*******************************************************************/
template <class T>
void Container<T>::operator += (const Container &add)
{
    if (size() + add.size() >= _allocated){
        reserve (size() + add.size());
    }

    std::copy(add._list, add._list + add.size(), _list + size());
    _size += add.size();
}

/*******************************************************************
* Container<T>& operator+(Container<T> rhs)
*
* appends items of rhs to this container
*------------------------------------------------------------------
* Parameter: rhs (Container<T>) //the container to be appended to
*                               //    this container
*------------------------------------------------------------------
* Return: a reference to this container
*******************************************************************/
template <class T>
Container<T>& Container<T>::operator+(Container<T> rhs){
    for (size_t i=0; i<rhs.size(); i++){
        add(rhs[i]);
    }
    return *this;
}

/*******************************************************************
* Container<T>& Container<T>::operator+(T rhs)
*
* appends rhs to this container
*------------------------------------------------------------------
* Parameter: rhs (T) //the item to be appended to
*                    //    this container
*------------------------------------------------------------------
* Return: a reference to this container
*******************************************************************/
template <class T>
Container<T>& Container<T>::operator+(T rhs){
    add(rhs);
    return *this;
}




#endif // CONTAINER_H
