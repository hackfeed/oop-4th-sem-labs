#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <class T>
class VectorBase;
template <class T>
class MatrixBase;

#include "iterator_base.hpp"

template <class T>
class Iterator : public IteratorBase<T>
{
public:
    Iterator(const Iterator &);

    T &operator*();
    T *operator->();

    friend class VectorBase<T>;
    friend class MatrixBase<T>;

private:
    Iterator(T *);
};

template <class T>
Iterator<T>::Iterator(T *pointer) : IteratorBase<T>(pointer)
{
}

template <class T>
Iterator<T>::Iterator(const Iterator &other) : IteratorBase<T>(other.pointer)
{
}

template <class T>
T &Iterator<T>::operator*()
{
    return *this->pointer;
}

template <class T>
T *Iterator<T>::operator->()
{
    return this->pointer;
}

#endif