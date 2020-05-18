#ifndef _LISTITERATOR_HPP_
#define _LISTITERATOR_HPP_

#include "listiterator.h"

template <typename typeData>
ListIterBase<typeData>::ListIterBase()
{
    this->ptrCur.lock() = nullptr;
}

template <typename typeData>
ListIterBase<typeData>::ListIterBase(const ListIterBase<typeData> &listIter) : ptrCur(listIter.ptrCur) {}

template <typename typeData>
ListIterBase<typeData>::ListIterBase(const std::shared_ptr<ListNode<typeData>> node) : ptrCur(node) {}

template <typename typeData>
ListIterBase<typeData>::~ListIterBase() {}

template <typename typeData>
ListIterBase<typeData> &ListIterBase<typeData>::operator=(const ListIterBase<typeData> &listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;

    return *this;
}

template <typename typeData>
ListIterBase<typeData> &ListIterBase<typeData>::next()
{
    this->ptrCur = this->ptrCur.lock()->getNext();
    return *this;
}

template <typename typeData>
ListIterBase<typeData> &ListIterBase<typeData>::operator++()
{
    this->next();
    return *this;
}

template <typename typeData>
ListIterBase<typeData> ListIterBase<typeData>::operator++(int)
{
    ListIterBase<typeData> tmp(*this);
    this->operator++();
    return tmp;
}

template <typename typeData>
bool ListIterBase<typeData>::checkRange() const
{
    return (this->ptrCur.lock() == nullptr) ? false : true;
}

template <typename typeData>
bool ListIterBase<typeData>::operator==(const ListIterBase<typeData> &listIter) const
{
    return this->ptrCur.lock() == listIter.ptrCur.lock();
}

template <typename typeData>
bool ListIterBase<typeData>::operator!=(const ListIterBase<typeData> &listIter) const
{
    return this->ptrCur.lock() != listIter.ptrCur.lock();
}

template <typename typeData>
ListIter<typeData>::ListIter()
{
    this->ptrCur.lock() = nullptr;
}

template <typename typeData>
ListIter<typeData>::ListIter(const ListIter<typeData> &listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename typeData>
ListIter<typeData>::ListIter(const std::shared_ptr<ListNode<typeData>> node)
{
    this->ptrCur = node;
}

template <typename typeData>
ListIter<typeData> &ListIter<typeData>::operator=(const ListIter<typeData> &listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;

    return *this;
}

template <typename typeData>
typeData &ListIter<typeData>::getCur()
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename typeData>
const typeData &ListIter<typeData>::getCur() const
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename typeData>
typeData &ListIter<typeData>::operator*()
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename typeData>
const typeData &ListIter<typeData>::operator*() const
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename typeData>
typeData *ListIter<typeData>::operator->()
{
    return &this->ptrCur.lock()->getPtrData();
}

template <typename typeData>
const typeData *ListIter<typeData>::operator->() const
{
    return &this->ptrCur.lock()->getPtrData();
}

template <typename typeData>
ConstListIter<typeData>::ConstListIter()
{
    this->ptrCur.lock() = nullptr;
}

template <typename typeData>
ConstListIter<typeData>::ConstListIter(const ConstListIter<typeData> &listIter)
{
    this->ptrCur = listIter.ptrCur;
}

template <typename typeData>
ConstListIter<typeData>::ConstListIter(const std::shared_ptr<ListNode<typeData>> node)
{
    this->ptrCur = node;
}

template <typename typeData>
ConstListIter<typeData> &ConstListIter<typeData>::operator=(const ConstListIter<typeData> &listIter)
{
    if (this != &listIter)
        this->ptrCur = listIter.ptrCur;

    return *this;
}

template <typename typeData>
const typeData &ConstListIter<typeData>::getCur() const
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename typeData>
const typeData &ConstListIter<typeData>::operator*() const
{
    return this->ptrCur.lock()->getPtrData();
}

template <typename typeData>
const typeData *ConstListIter<typeData>::operator->() const
{
    return &this->ptrCur.lock()->getPtrData();
}

#endif
