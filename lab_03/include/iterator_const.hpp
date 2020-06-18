#ifndef ITERATOR_CONST_HPP
#define ITERATOR_CONST_HPP

template <class T>
class VectorBase;
template <class T>
class MatrixBase;

#include "iterator_base.hpp"

template <class T>
class ConstIterator : public IteratorBase<T>
{
public:
    ConstIterator(const ConstIterator &);

    const T &operator*();
    const T *operator->();

    friend class VectorBase<T>;
    friend class MatrixBase<T>;

private:
    ConstIterator(T *);
};

template <class T>
ConstIterator<T>::ConstIterator(T *pointer) : IteratorBase<T>(pointer)
{
}

template <class T>
ConstIterator<T>::ConstIterator(const ConstIterator &other) : IteratorBase<T>(other.pointer)
{
}

template <class T>
const T &ConstIterator<T>::operator*()
{
    return *this->pointer;
}

template <class T>
const T *ConstIterator<T>::operator->()
{
    return this->pointer;
}

#endif