#ifndef _LISTITERATOR_HPP_
#define _LISTITERATOR_HPP_

#include <ctime>

#include "listiterator.h"

template <typename T>
ListIterBase<T>::ListIterBase()
{
    this->ptrCur.lock() = nullptr;
}

template <typename T>
ListIterBase<T>::ListIterBase(const ListIterBase<T> &listIter) : ptrCur(listIter.ptrCur) {}

template <typename T>
ListIterBase<T>::ListIterBase(const std::shared_ptr<ListNode<T>> node) : ptrCur(node) {}

template <typename T>
ListIterBase<T> &ListIterBase<T>::operator=(const ListIterBase<T> &listIter)
{
    if (this != &listIter)
    {
        this->ptrCur = listIter.ptrCur;
    }

    return *this;
}

template <typename T>
ListIterBase<T> &ListIterBase<T>::next()
{
    this->ptrCur = this->ptrCur.lock()->getNext();
    return *this;
}

template <typename T>
ListIterBase<T> &ListIterBase<T>::operator++()
{
    this->next();
    return *this;
}

template <typename T>
ListIterBase<T> ListIterBase<T>::operator++(int)
{
    ListIterBase<T> tmp(*this);
    this->operator++();
    return tmp;
}

template <typename T>
bool ListIterBase<T>::checkRange() const
{
    return (this->ptrCur.lock() == nullptr) ? false : true;
}

template <typename T>
bool ListIterBase<T>::operator==(const ListIterBase<T> &listIter) const
{
    return this->ptrCur.lock() == listIter.ptrCur.lock();
}

template <typename T>
bool ListIterBase<T>::operator!=(const ListIterBase<T> &listIter) const
{
    return this->ptrCur.lock() != listIter.ptrCur.lock();
}

template <typename T>
ListIter<T>::ListIter()
{
    this->ptrCur.lock() = nullptr;
}

template <typename T>
ListIter<T>::ListIter(const ListIter<T> &listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename T>
ListIter<T>::ListIter(const std::shared_ptr<ListNode<T>> node)
{
    this->ptrCur = node;
}

template <typename T>
ListIter<T> &ListIter<T>::operator=(const ListIter<T> &listIter)
{
    if (this != &listIter)
    {
        this->ptrCur = listIter.ptrCur;
    }

    return *this;
}

template <typename T>
T &ListIter<T>::getCur()
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T &ListIter<T>::getCur() const
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
T &ListIter<T>::getNext()
{
    if (this->ptrCur.lock() == this->end() || this->ptrCur.next().lock() == this->end())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.next().lock()->getPtrData();
}

template <typename T>
const T &ListIter<T>::getNext() const
{
    if (this->ptrCur.lock() == this->c_end() || this->ptrCur.next().lock() == this->c_end())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.next().lock()->getPtrData();
}

template <typename T>
T &ListIter<T>::operator*()
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T &ListIter<T>::operator*() const
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
T *ListIter<T>::operator->()
{
    return &this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T *ListIter<T>::operator->() const
{
    return &this->ptrCur.lock()->getPtrData();
}

template <typename T>
ListIter<T>::operator bool()
{
    return &this->ptrCur.expired();
}

template <typename T>
ListIter<T>::operator bool() const
{
    return &this->ptrCur.expired();
}

template <typename T>
ConstListIter<T>::ConstListIter()
{
    this->ptrCur.lock() = nullptr;
}

template <typename T>
ConstListIter<T>::ConstListIter(const ConstListIter<T> &listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename T>
ConstListIter<T>::ConstListIter(const std::shared_ptr<ListNode<T>> node)
{
    this->ptrCur = node;
}

template <typename T>
ConstListIter<T> &ConstListIter<T>::operator=(const ConstListIter<T> &listIter)
{
    if (this != &listIter)
    {
        this->ptrCur = listIter.ptrCur;
    }

    return *this;
}

template <typename T>
const T &ConstListIter<T>::getCur() const
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T &ConstListIter<T>::getNext() const
{
    if (this->ptrCur.lock() == this->c_end() || this->ptrCur.next().lock() == this->c_end())
    {
        time_t t_time = time(NULL);
        throw ListIteratorError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return this->ptrCur.next().lock()->getPtrData();
}

template <typename T>
const T &ConstListIter<T>::operator*() const
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename T>
const T *ConstListIter<T>::operator->() const
{
    return &this->ptrCur.lock()->getPtrData();
}

template <typename T>
ConstListIter<T>::operator bool() const
{
    return &this->ptrCur.expired();
}

#endif
