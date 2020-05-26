#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>

using namespace std;

template <class T> class Container
{
  public:
    /****************************************
    **  CONSTRUCTORS  **
    *****************************************/
    Container();

    /****************************************
    **  BIG 3  **
    *****************************************/
    virtual ~Container();                       // destructor
    Container &operator=(const Container &rhs); // assginment operator
    Container(const Container &copy_this);      // copy constructor

    virtual bool add(const T &item);
    bool remove(size_t index);
    void reserve(size_t n);
    size_t size() const { return _size; }
    bool empty() const { return _size == 0; }
    const T &operator[](size_t index) const;
    T &operator[](size_t index);

    void operator+=(const Container &add);

  protected:
    T *_list;
    size_t _allocated;
    size_t _size;
};

template <class T> Container<T>::Container()
{
    _allocated = 10;
    _list = new T[_allocated];
    _size = 0;
}

template <class T> Container<T>::~Container() { delete[] _list; }

template <class T>
Container<T> &Container<T>::operator=(const Container<T> &rhs)
{
    if (this == &rhs)
        return *this;
    if (_list != nullptr)
        delete[] _list;
    _size = rhs._size;
    _allocated = rhs._allocated;
    _list = new T[rhs._allocated];
    std::copy(rhs._list, rhs._list + rhs._size, _list);
    return *this;
}

template <class T> Container<T>::Container(const Container<T> &other)
{
    _size = other._size;
    _allocated = 2 * other._size;
    _list = new T[_allocated];
    std::copy(other._list, other._list + other._size, _list);
}

template <class T> bool Container<T>::add(const T &item)
{
    // some condition: return false;
    if (size() == _allocated)
    {
        reserve(size() * 2);
    }
    _list[_size++] = item;
    return true;
}

template <class T> bool Container<T>::remove(size_t index)
{
    assert(index < size() && index >= 0);
    for (size_t i = index + 1; i < size(); i++)
    {
        _list[i - 1] = _list[i];
    }
    _size--;
    return true;
}

template <class T> void Container<T>::reserve(size_t n)
{
    assert(n > _allocated);
    T *temp = _list;
    _allocated = n;
    _list = new T[_allocated];
    std::copy(temp, temp + size(), _list);
    delete[] temp;
}

template <class T> const T &Container<T>::operator[](size_t index) const
{
    assert(index < size() && index >= 0);
    return _list[index];
}

template <class T> T &Container<T>::operator[](size_t index)
{
    assert(index < size() && index >= 0);
    return _list[index];
}

template <class T> void Container<T>::operator+=(const Container &add)
{
    if (size() + add.size() >= _allocated)
    {
        reserve(size() + add.size());
    }

    std::copy(add._list, add._list + add.size(), _list + size());
    _size += add.size();
}

#endif // CONTAINER_H
