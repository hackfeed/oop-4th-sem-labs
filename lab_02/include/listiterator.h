#ifndef _LISTITERATOR_H_
#define _LISTITERATOR_H_

#include <iterator>

#include "listnode.h"

template <typename T>
class ListIterBase
{
public:
    ListIterBase();
    ListIterBase(const ListIterBase<T> &listIter);
    ListIterBase(const std::shared_ptr<ListNode<T>> node);
    virtual ~ListIterBase() = default;

    ListIterBase<T> &operator=(const ListIterBase<T> &listIter);

    ListIterBase<T> &next();
    ListIterBase<T> &operator++();
    ListIterBase<T> operator++(int);

    bool checkRange() const;

    bool operator==(const ListIterBase<T> &listIter) const;
    bool operator!=(const ListIterBase<T> &listIter) const;

protected:
    std::weak_ptr<ListNode<T>> ptrCur;
};

template <typename T>
class ListIter : public ListIterBase<T>
{
public:
    ListIter();
    ListIter(const ListIter<T> &listIter);
    ListIter(const std::shared_ptr<ListNode<T>> node);

    ListIter<T> &operator=(const ListIter<T> &listIter);

    T &getCur();
    const T &getCur() const;

    T &operator*();
    const T &operator*() const;

    T *operator->();
    const T *operator->() const;

    // bool

    // getNext
};

template <typename T>
class ConstListIter : public ListIterBase<T>
{
public:
    ConstListIter();
    ConstListIter(const ConstListIter<T> &listIter);
    ConstListIter(const std::shared_ptr<ListNode<T>> node);

    ConstListIter<T> &operator=(const ConstListIter<T> &listIter);

    const T &getCur() const;
    const T &operator*() const;
    const T *operator->() const;
};

#endif
