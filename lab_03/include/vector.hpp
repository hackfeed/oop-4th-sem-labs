#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <QDebug>
#include "vector.h"
#include "iterator.h"

template <typename T>
vector<T>::vector()
{
    this->size = 0;
    this->allocate_new(100);
}

template <typename T>
vector<T>::vector(const T *array, size_t _size)
{
    this->allocate_new(_size * 2);

    for (int i = 0; i < _size; i++)
    {
        this->push_back(*(array + i));
    }
}

template <typename T>
vector<T>::vector(T elem, size_t _size)
{
    this->allocate_new(_size * 2);

    for (int i = 0; i < _size; i++)
    {
        this->push_back(elem);
    }
}

template <typename T>
size_t vector<T>::get_size() const
{
    return this->size;
}

template <typename T>
bool vector<T>::is_empty() const
{
    return this->size == 0 ? true : false;
}

template <typename T>
T vector<T>::at(size_t index) const
{
    if (index >= this->size)
    {
        //todo
    }

    return this->value[index];
}

template <typename T>
vector<T> &vector<T>::push_back(const T &elem)
{
    if (this->size >= memory_allocated)
    {
        allocate_new(size * 2);
    }

    this->value[this->size++] = elem;
}

template <typename T>
vector<T> &vector<T>::operator+=(const T &elem)
{
    this->push_back(elem);
}

template <typename T>
void vector<T>::remove(iterator<T> _iterator)
{
    //todo
}

template <typename T>
void vector<T>::remove(size_t index)
{
    //iterator<T> iterator(index);
    //this->remove(iterator);
}

template <typename T>
iterator<T> vector<T>::begin()
{
    iterator<T> iterator(*this);
    return iterator;
}

template <typename T>
iterator<T> vector<T>::end()
{
    iterator<T> iterator(*this);
    return iterator + this->size;
}

template <typename T>
const iterator<T> vector<T>::begin() const
{
    const iterator<T> iterator(*this);
    return iterator;
}

template <typename T>
const iterator<T> vector<T>::end() const
{
    const iterator<T> iterator(*this);
    return iterator + this->size;
}

template <typename T>
void vector<T>::allocate_new(size_t new_size)
{

    try
    {
        this->value.reset(new T[new_size]);
    }
    catch (std::bad_alloc &exception)
    {
        //todo
    }

    this->memory_allocated = new_size;
}

#endif
