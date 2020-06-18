#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <initializer_list>
#include <istream>
#include <iterator>
#include <memory>
#include <ostream>

#include "vector_base.hpp"
#include "exception_container.hpp"

template <typename T>
class Vector : public BaseVector<T>
{
private:
    template <typename Ptr, typename Ref, typename VectorPtr>
    class Iterator;

public:
    using iterator = Iterator<std::shared_ptr<T>, T &, Vector<T> *>;
    using const_iterator = Iterator<const std::shared_ptr<T>, const T &, const Vector<T> *>;

    Vector();
    Vector(size_t size, const T &data);
    Vector(Vector<T> &&vec) noexcept;
    Vector(const std::initializer_list<T> &lst);
    Vector(const Vector<T> &vec);

    iterator begin();
    iterator end();
    const const_iterator cbegin() const;
    const const_iterator cend() const;
    const const_iterator begin() const;
    const const_iterator end() const;

    void clean() override;
    void push_back(const T &value);
    void erase(iterator &it);
    size_t size() const override;
    T &operator[](int index);
    const T &operator[](int index) const;
    Vector<T> &operator=(const Vector<T> &vec);
    Vector<T> &operator=(Vector<T> &&vec);
    T &at(size_t index);
    const T &at(size_t index) const;

private:
    const size_t START_SIZE = 8;
    void resize();
    void allocate(size_t size);
    size_t allocated_size;
    T *data_;
};

template <typename T>
Vector<T>::Vector()
{
    allocate(START_SIZE);
}

template <typename T>
Vector<T>::Vector(size_t size, const T &data)
{
    allocate(size);
    for (int i = 0; i < size; ++i)
        push_back(data);
}

template <typename T>
Vector<T>::Vector(Vector<T> &&vec) noexcept
{
    data_ = vec.data_;
    allocated_size = vec.allocated_size;
    this->size_ = vec.size_;
}

template <typename T>
void Vector<T>::allocate(size_t size)
{
    time_t t_time = time(NULL);
    data_ = new T[size];
    if (!data_)
        throw MemError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    allocated_size = size;
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T> &lst)
{
    allocate(lst.size());
    this->size_ = 0;
    data_ = nullptr;
    for (auto &element : lst)
    {
        this->push_back(element);
    }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &vec)
{
    data_ = vec.data_;
    allocated_size = vec.allocated_size;
    this->size_ = vec.size_;
}

template <typename T>
void Vector<T>::clean()
{
    if (!data_)
        return;
    delete[] data_;
    data_ = nullptr;
    this->size_ = 0;
    allocated_size = 0;
}

template <typename T>
void Vector<T>::resize()
{
    size_t new_size = allocated_size * 2;
    T *new_data = new T[new_size];
    for (size_t i = 0; i < this->size_; ++i)
        new_data[i] = data_[i];

    delete[] data_;
    data_ = new_data;
    allocated_size = new_size;
}

template <typename T>
void Vector<T>::erase(iterator &it)
{
    time_t t_time = time(NULL);
    if (it > end())
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    for (auto i = it; i != end() - 1; ++i)
        *i = *(i + 1);
    this->size_--;
}

template <typename T>
size_t Vector<T>::size() const
{
    return this->size_;
}

template <typename T>
void Vector<T>::push_back(const T &value)
{
    if (!data_)
        allocate(START_SIZE);
    if (this->size_ == allocated_size)
        resize();
    data_[this->size_++] = value;
}

template <typename T>
T &Vector<T>::operator[](int index)
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->size_)
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return data_[index];
}

template <typename T>
const T &Vector<T>::operator[](int index) const
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->size_)
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));

    return data_[index];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &vec)
{
    data_ = vec.data_;
    this->size_ = vec.size_;
    allocated_size = vec.allocated_size;

    return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&vec)
{
    data_ = vec.data_;
    this->size_ = vec.size_;
    allocated_size = vec.allocated_size;
    vec.~Vector();

    return *this;
}

template <typename T>
T &Vector<T>::at(size_t index)
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->size_)
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return data_[index];
}

template <typename T>
const T &Vector<T>::at(size_t index) const
{
    time_t t_time = time(NULL);
    if (index < 0 || index >= this->size_)
        throw RangeError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    return data_[index];
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return iterator(this, 0);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return iterator(this, size());
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return const_iterator(this, size());
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return const_iterator(this, size());
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::begin() const
{
    return cbegin();
}

template <typename T>
const typename Vector<T>::const_iterator Vector<T>::end() const
{
    return cend();
}

#endif