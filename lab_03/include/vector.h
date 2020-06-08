#ifndef VECTOR_H
#define VECTOR_H

#include <memory>
#include "iterator.h"

class base_vector
{
public:
    virtual size_t get_size() const = 0;
    virtual bool   is_empty() const = 0;
    virtual ~base_vector() = default;

protected:
    size_t size;

};

template <typename T>
class vector : public base_vector
{
public:
    friend class iterator<T>;

    vector();
    vector(const T *array, size_t size);
    vector(T elem, size_t size);

    virtual ~vector() = default;

    virtual size_t get_size() const;
    virtual bool   is_empty() const;

    T at(size_t index) const;

    vector<T> &push_back(const T &elem);
    vector<T> &operator += (const T &elem);

    void remove(iterator<T>);
    void remove(size_t index);

    iterator<T> begin();
    const iterator<T> begin() const;

    iterator<T> end();
    const iterator<T> end() const;

protected:
    void allocate_new(size_t size);

private:
    std::shared_ptr<T[]> value;
    size_t memory_allocated;

};

//#include "vector.hpp"

#endif
