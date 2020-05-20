#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <stdarg.h>

#include "errors.h"
#include "listbase.h"
#include "listnode.h"
#include "listiterator.h"

template <typename T>
class List : public ListBase
{
public:
    List();
    List(const size_t countNodes, ...);
    explicit List(const List<T> &someList);
    List(List<T> &&someList);
    List(const T &data, const size_t countData = 1);
    List(const std::initializer_list<T> &someList);
    virtual ~List() = default;

    List<T> &operator=(const List<T> &someList);
    List<T> &operator=(List<T> &&someList);

    List<T> &append(const T &data);
    List<T> &operator+=(const T &data);
    List<T> operator+(const T &data) const;

    List<T> &insert(const T &data, const ListIter<T> &iter);

    List<T> &extend(const List &ListToAdd);
    List<T> &operator+=(const List<T> &someList);
    List<T> operator+(const List<T> &somelist) const;

    const T pop();

    const T remove(const ListIter<T> &iter);

    List<T> &clear();

    bool operator==(const List<T> &someList) const;
    bool operator!=(const List<T> &someList) const;

    ListIter<T> begin();
    ListIter<T> end();
    ConstListIter<T> begin() const;
    ConstListIter<T> end() const;

private:
    std::shared_ptr<ListNode<T>> head;
    std::shared_ptr<ListNode<T>> tail;

    std::shared_ptr<ListNode<T>> initNode(const T &data, std::shared_ptr<ListNode<T>> ptrNode = nullptr);
    void addList(const List<T> &ListToAdd);
    bool isNodesEqual(const List<T> &someList) const;
    bool isEmpty() const;

protected:
};

#endif
