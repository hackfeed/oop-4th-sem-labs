#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator.h"
#include <QDebug>

template <typename T>
iterator<T>::iterator(const iterator<T> &iterator)
{
    this->ptr = iterator.ptr;
    this->current_index = iterator.current_index;
    this->vector_size = iterator.vector_size;
}

template <typename T>
iterator<T>::iterator(const vector<T> &vector)
{
    this->current_index = 0;
    this->vector_size = vector.get_size();
    this->ptr = vector.value;
}

template <typename T>
T &iterator<T>::operator*()
{
    return *get_current();
}

template <typename T>
const T &iterator<T>::operator*() const
{
    return get_current();
}

template <typename T>
T *iterator<T>::operator->()
{
    return get_current();
}

template <typename T>
const T *iterator<T>::operator->() const
{
    return get_current();
}

template <typename T>
iterator<T>::operator bool() const
{
    return current_index >= vector_size || !vector_size ? false : true;
}

template <typename T>
iterator<T> &iterator<T>::operator+=(size_t number)
{
    current_index += number;
    return *this;
}

template <typename T>
iterator<T> iterator<T>::operator+(size_t number) const
{
    iterator<T> iterator(*this);
    iterator += number;
    return iterator;
}

template <typename T>
iterator<T> &iterator<T>::operator++()
{
    this->current_index++;

    return *this;
}

template <typename T>
iterator<T> iterator<T>::operator++(int)
{
    ++(*this);

    return *this;
}

template <typename T>
bool iterator<T>::operator==(const iterator<T> &iterator) const
{
    return this->current_index == iterator.current_index;
}

template <typename T>
bool iterator<T>::operator!=(const iterator<T> &iterator) const
{
    return this->current_index != iterator.current_index;
}

template <typename T>
T *iterator<T>::get_current() const
{
    return this->ptr.lock().get() + current_index;
}

#endif
