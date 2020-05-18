#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <stdarg.h>

#include "errors.h"
#include "listnode.h"
#include "listiterator.h"

class BaseList
{
public:
    BaseList();
    virtual ~BaseList();

    size_t size() const;

protected:
    size_t sizeList;
};

template <typename typeData>
class List : public BaseList
{
public:
    List();
    List(const size_t countNodes, ...);
    explicit List(const List<typeData> &someList);
    List(List<typeData> &&someList);
    List(const typeData &data, const size_t countData = 1);
    List(const std::initializer_list<typeData> &someList);
    virtual ~List();

    List<typeData> &operator=(const List<typeData> &someList);
    List<typeData> &operator=(List<typeData> &&someList);

    List<typeData> &append(const typeData &data);
    List<typeData> &operator+=(const typeData &data);
    List<typeData> operator+(const typeData &data) const;

    List<typeData> &insert(const typeData &data, const ListIter<typeData> &iter);
    friend List<typeData> operator+(const typeData &data, const List<typeData> &list);

    List<typeData> &extend(const List &ListToAdd);
    List<typeData> &operator+=(const List<typeData> &someList);
    List<typeData> operator+(const List<typeData> &somelist) const;

    const typeData pop();

    const typeData remove(const ListIter<typeData> &iter);

    List<typeData> &clear();

    bool operator==(const List<typeData> &someList) const;
    bool operator!=(const List<typeData> &someList) const;

    ListIter<typeData> begin();
    ListIter<typeData> end();
    ConstListIter<typeData> begin() const;
    ConstListIter<typeData> end() const;

private:
    std::shared_ptr<ListNode<typeData>> head;
    std::shared_ptr<ListNode<typeData>> tail;

    std::shared_ptr<ListNode<typeData>> initNode(const typeData &data, std::shared_ptr<ListNode<typeData>> ptrNode = nullptr);
    void addList(const List<typeData> &ListToAdd);
    bool isNodesEqual(const List<typeData> &someList) const;
    bool isEmpty() const;

protected:
};

#endif
