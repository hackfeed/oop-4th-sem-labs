#pragma once

#include <cstddef>

template <class T>
class iterator_base
{
public:
    iterator_base(const iterator_base &);
    virtual ~iterator_base();
    iterator_base &operator=(const iterator_base &);

    iterator_base &operator++();
    iterator_base operator++(int);
    iterator_base &operator--();
    iterator_base operator--(int);

    ptrdiff_t operator-(const iterator_base &);

    bool operator==(const iterator_base &);
    bool operator!=(const iterator_base &);

protected:
    iterator_base(T *);

    T *pointer;
};

template <class T>
iterator_base<T>::iterator_base(T *pointer)
{
    this->pointer = pointer;
}

template <class T>
iterator_base<T>::iterator_base(const iterator_base &other)
{
    this->pointer = other.pointer;
}

template <class T>
iterator_base<T>::~iterator_base()
{
    this->pointer = nullptr;
}

template <class T>
iterator_base<T> &iterator_base<T>::operator=(const iterator_base &rhs)
{
    if (this != &rhs)
    {
        this->pointer = rhs.pointer;
    }

    return *this;
}

template <class T>
iterator_base<T> &iterator_base<T>::operator++()
{
    ++this->pointer;
    return *this;
}

template <class T>
iterator_base<T> iterator_base<T>::operator++(int)
{
    iterator_base temp(*this);
    this->operator++();
    return temp;
}

template <class T>
iterator_base<T> &iterator_base<T>::operator--()
{
    --this->pointer;
    return *this;
}

template <class T>
iterator_base<T> iterator_base<T>::operator--(int)
{
    iterator_base temp(*this);
    this->operator--();
    return temp;
}

template <class T>
ptrdiff_t iterator_base<T>::operator-(const iterator_base<T> &rhs)
{
    return this->pointer - rhs.pointer;
}

template <class T>
bool iterator_base<T>::operator==(const iterator_base &rhs)
{
    return this->pointer == rhs.pointer;
}

template <class T>
bool iterator_base<T>::operator!=(const iterator_base &rhs)
{
    return this->pointer != rhs.pointer;
}
