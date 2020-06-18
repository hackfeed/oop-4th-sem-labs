#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <cstdlib>
#include <iostream>
#include <iterator>
#include <memory>

#include "vector.hpp"

template <typename T>
template <typename Ptr, typename Ref, typename VectorPtr>
class Vector<T>::Iterator : public std::iterator<std::random_access_iterator_tag, T, ptrdiff_t, Ptr, Ref>
{
private:
    VectorPtr vector;
    size_t i;

public:
    Iterator(VectorPtr vector, size_t i) : vector(vector), i(i) {}
    Iterator() = default;

    Ref operator*()
    {
        return (*vector)[i];
    }

    Ptr operator->()
    {
        return &(*vector)[i];
    }

    Iterator &operator+=(ptrdiff_t t)
    {
        i += t;
        return *this;
    }
    Iterator operator+(ptrdiff_t t) const
    {
        return Iterator(vector, i + t);
    }
    Iterator &operator-=(ptrdiff_t t)
    {
        i -= t;
        return *this;
    }
    Iterator operator-(ptrdiff_t t) const
    {
        return Iterator(vector, (i - t));
    }
    ptrdiff_t operator-(const Iterator &right) const
    {
        return static_cast<ptrdiff_t>(i) - right.i;
    }
    Ref operator[](ptrdiff_t n)
    {
        return *(*this + n);
    }
    bool operator==(const Iterator &right) const
    {
        return i == right.i;
    }
    bool operator!=(const Iterator &right) const
    {
        return i != right.i;
    }
    Iterator operator++(int)
    {
        Iterator tmp = *this;
        *this += 1;
        return tmp;
    }
    Iterator &operator++()
    {
        *this += 1;
        return *this;
    }
    Iterator operator--(int)
    {
        Iterator tmp = *this;
        *this -= 1;
        return tmp;
    }
    Iterator &operator--()
    {
        *this -= 1;
        return *this;
    }
    bool operator<(const Iterator &right) const
    {
        return (i < right.i);
    }
    bool operator>(const Iterator &right) const
    {
        return (i > right.i);
    }

    T &get()
    {
        return (*vector)[i];
    }
};

#endif