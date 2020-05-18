#ifndef _LISTITERATOR_H_
#define _LISTITERATOR_H_

#include "listnode.h"

template <typename typeData>
class ListIterBase
{
public:
    ListIterBase();
    ListIterBase(const ListIterBase<typeData> &listIter);
    ListIterBase(const std::shared_ptr<ListNode<typeData>> node);
    virtual ~ListIterBase();

    ListIterBase<typeData> &operator=(const ListIterBase<typeData> &listIter);

    ListIterBase<typeData> &next();
    ListIterBase<typeData> &operator++();
    ListIterBase<typeData> operator++(int);

    bool checkRange() const;

    bool operator==(const ListIterBase<typeData> &listIter) const;
    bool operator!=(const ListIterBase<typeData> &listIter) const;

protected:
    std::weak_ptr<ListNode<typeData>> ptrCur;
};

template <typename typeData>
class ListIter : public ListIterBase<typeData>
{
public:
    ListIter();
    ListIter(const ListIter<typeData> &listIter);
    ListIter(const std::shared_ptr<ListNode<typeData>> node);

    ListIter<typeData> &operator=(const ListIter<typeData> &listIter);

    typeData &getCur();
    const typeData &getCur() const;

    typeData &operator*();
    const typeData &operator*() const;

    typeData *operator->();
    const typeData *operator->() const;
};

template <typename typeData>
class ConstListIter : public ListIterBase<typeData>
{
public:
    ConstListIter();
    ConstListIter(const ConstListIter<typeData> &listIter);
    ConstListIter(const std::shared_ptr<ListNode<typeData>> node);

    ConstListIter<typeData> &operator=(const ConstListIter<typeData> &listIter);

    const typeData &getCur() const;
    const typeData &operator*() const;
    const typeData *operator->() const;
};

#endif
