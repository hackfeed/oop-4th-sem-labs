#ifndef ITERATOR_H
#define ITERATOR_H

#include <iterator>
#include <memory>

template <typename T>
class vector;

template <typename T>
class iterator : public std::iterator<std::input_iterator_tag, T>
{
public:
    iterator(const iterator<T> &iterator);
    iterator(const vector<T> &vector);

    T &operator*();
    const T &operator*() const;

    T *operator->();
    const T *operator->() const;

    operator bool() const;

    iterator<T> &operator+=(size_t number);
    iterator<T> operator+(size_t number) const;

    iterator<T> &operator++();
    iterator<T> operator++(int);

    bool operator==(const iterator<T> &iterator) const;
    bool operator!=(const iterator<T> &iterator) const;

private:
    std::weak_ptr<T[]> ptr;
    T *get_current() const;
    size_t current_index;
    size_t vector_size;
};

//#include "iterator.hpp"

#endif
