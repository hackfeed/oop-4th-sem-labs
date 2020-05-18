#ifndef _LIST_HPP_
#define _LIST_HPP_

#include <memory>

#include "list.h"

BaseList::BaseList() : sizeList(0) {}

BaseList::~BaseList()
{
    this->sizeList = 0;
}

size_t BaseList::size() const
{
    return sizeList;
}

template <typename typeData>
List<typeData>::List() : head(nullptr), tail(nullptr) {}

template <typename typeData>
List<typeData>::List(const size_t countNodes, ...) : head(nullptr), tail(nullptr)
{
    va_list vlist;
    va_start(vlist, countNodes);

    typeData tmp;

    for (size_t i = 0; i < countNodes; ++i)
    {
        tmp = va_arg(vlist, typeData);
        this->append(tmp);
    }

    va_end(vlist);
}

template <typename typeData>
List<typeData>::List(const List<typeData> &someList) : head(nullptr), tail(nullptr)
{
    this->extend(someList);
}

template <typename typeData>
List<typeData>::List(List<typeData> &&someList)
{
    this->sizeList = someList->sizeList;
    this->head.reset(someList->head);
    this->tail.reset(someList->tail);

    someList->sizeList = 0;
    someList->head = nullptr;
    someList->tail = nullptr;
}

template <typename typeData>
List<typeData>::List(const typeData &data, const size_t countData) : head(nullptr), tail(nullptr)
{
    if (countData == 0)
        return;

    for (size_t i = 1; i < countData; ++i)
        this->append(data);
}

template <typename typeData>
List<typeData>::List(const std::initializer_list<typeData> &someList) : head(nullptr), tail(nullptr)
{
    for (const auto &data : someList)
        append(data);
}

template <typename typeData>
List<typeData>::~List() {}

template <typename typeData>
List<typeData> &List<typeData>::operator=(const List &someList)
{
    if (this != &someList)
    {
        this->clear();
        this->extend(someList);
    }

    return *this;
}

template <typename typeData>
List<typeData> &List<typeData>::operator=(List &&someList)
{
    if (this != someList)
    {
        this->clear();
        this->sizeList = someList->sizeList;
        this->head = someList->head;
        this->tail = someList->tail;

        someList->sizeList = 0;
        someList->head = nullptr;
        someList->tail = nullptr;
    }

    return *this;
}

template <typename typeData>
List<typeData> &List<typeData>::append(const typeData &data)
{
    std::shared_ptr<ListNode<typeData>> newNode = initNode(data);

    if (this->isEmpty())
        this->head = newNode;
    else
        this->tail->setNext(newNode);
    this->tail = newNode;

    return *this;
}

template <typename typeData>
List<typeData> &List<typeData>::operator+=(const typeData &data)
{
    this->append(data);
    return *this;
}

template <typename typeData>
List<typeData> &operator+(const List<typeData> &list, const typeData &data)
{
    List<typeData> newList(list);
    newList.append(data);
    return newList;
}

template <typename typeData>
List<typeData> &operator+(const typeData &data, const List<typeData> &list)
{
    List<typeData> newList(list);
    newList.insert(data);
    return newList;
}

template <typename typeData>
List<typeData> &List<typeData>::insert(const typeData &data, const ListIter<typeData> &iter)
{
    std::shared_ptr<ListNode<typeData>> curNode = this->head;
    std::shared_ptr<ListNode<typeData>> tmp = nullptr;
    ListIter<typeData> cur = this->begin();

    if (this->head == nullptr && cur == iter)
    {
        std::shared_ptr<ListNode<typeData>> newNode = initNode(data);
        this->head = newNode;
        this->tail = newNode;
        return *this;
    }

    for (; curNode && cur != iter; tmp = curNode, curNode = curNode->getNext(), cur.next())
        ;

    if (curNode == nullptr)
        throw RangeError(": method - insert()");

    std::shared_ptr<ListNode<typeData>> newNode = initNode(data, curNode);

    if (curNode == this->head)
        this->head = newNode;
    else
        tmp->setNext(newNode);

    return *this;
}

template <typename typeData>
List<typeData> &List<typeData>::extend(const List &ListToAdd)
{
    if (ListToAdd.isEmpty())
        return *this;

    if (this == &ListToAdd)
    {
        List<typeData> ListCopy;
        ListCopy = ListToAdd;
        addList(ListCopy);
    }
    else
    {
        addList(ListToAdd);
    }

    return *this;
}

template <typename typeData>
const typeData List<typeData>::remove(const ListIter<typeData> &iter)
{
    if (this->isEmpty())
        throw EmptyError(": method - remove()");

    std::shared_ptr<ListNode<typeData>> curNode = this->head;
    std::shared_ptr<ListNode<typeData>> tmp = nullptr;
    ListIter<typeData> cur = this->begin();

    for (; curNode && cur != iter; tmp = curNode, curNode = curNode->getNext(), cur.next())
        ;

    if (curNode == nullptr)
        throw RangeError(": method - remove()");

    typeData retData = iter.getCur();

    if (curNode->getNext() == nullptr)
        this->tail = tmp;

    if (curNode == this->head)
        this->head = this->head->getNext();
    else
        tmp->setNext(curNode->getNext());
    this->sizeList -= 1;

    return retData;
}

template <typename typeData>
const typeData List<typeData>::pop()
{
    if (this->isEmpty())
        throw EmptyError(": method - pop()");

    ListIter<typeData> iter = this->end();
    return remove(iter);
}

template <typename typeData>
List<typeData> &List<typeData>::clear()
{
    this->head = nullptr;
    this->tail = nullptr;
    this->sizeList = 0;

    return *this;
}

template <typename typeData>
List<typeData> &List<typeData>::operator+=(const List &someList)
{
    this->extend(someList);
    return *this;
}

template <typename typeData>
bool List<typeData>::operator==(const List &someList) const
{
    return isNodesEqual(someList);
}

template <typename typeData>
bool List<typeData>::operator!=(const List &someList) const
{
    return !isNodesEqual(someList);
}

template <typename typeData>
ListIter<typeData> List<typeData>::begin()
{
    return ListIter<typeData>(head);
}

template <typename typeData>
ListIter<typeData> List<typeData>::end()
{
    return ListIter<typeData>(tail);
}

template <typename typeData>
ConstListIter<typeData> List<typeData>::begin() const
{
    return ConstListIter<typeData>(head);
}

template <typename typeData>
ConstListIter<typeData> List<typeData>::end() const
{
    return ConstListIter<typeData>(tail);
}

template <typename typeData>
std::shared_ptr<ListNode<typeData>> List<typeData>::initNode(const typeData &data, std::shared_ptr<ListNode<typeData>> ptrNode)
{
    std::shared_ptr<ListNode<typeData>> newNode;
    newNode = std::make_shared<ListNode<typeData>>();
    if (!newNode)
    {
        throw MemoryError(": method - initNode()");
    }
    newNode->setData(data);
    newNode->setNext(ptrNode);
    this->sizeList += 1;

    return newNode;
}

template <typename typeData>
void List<typeData>::addList(const List &ListToAdd)
{
    typeData data = ListToAdd.head->getData();
    std::shared_ptr<ListNode<typeData>> nextNode = ListToAdd.head->getNext();
    std::shared_ptr<ListNode<typeData>> nodeToAdd = initNode(data, nextNode);
    std::shared_ptr<ListNode<typeData>> cur = this->head;

    if (this->isEmpty())
    {
        cur = nodeToAdd;
        this->head = cur;
    }
    else
    {
        for (; cur->getNext(); cur = cur->getNext())
            ;
        cur->setNext(nodeToAdd);
        cur = cur->getNext();
    }

    std::shared_ptr<ListNode<typeData>> curToAdd = nextNode;

    for (; curToAdd; curToAdd = curToAdd->getNext(), cur = cur->getNext())
    {
        data = curToAdd->getData();
        nextNode = curToAdd->getNext();
        nodeToAdd = initNode(data, nextNode);
        cur->setNext(nodeToAdd);
    }
    this->tail = nodeToAdd;
}

template <typename typeData>
bool List<typeData>::isNodesEqual(const List<typeData> &someList) const
{
    std::shared_ptr<ListNode<typeData>> curL = this->head;
    std::shared_ptr<ListNode<typeData>> curR = someList.head;
    for (; curL && curR && curL->getData() == curR->getData();)
    {
        curL = curL->getNext();
        curR = curR->getNext();
    }

    return (curL == nullptr && curR == nullptr) ? true : false;
}

template <typename typeData>
bool List<typeData>::isEmpty() const
{
    return (this->head == nullptr) ? true : false;
}

template <typename typeData>
std::ostream &operator<<(std::ostream &stream, List<typeData> &list)
{
    stream << "List";
    ListIter<typeData> iter = list.begin();
    if (!iter.checkRange())
    {
        stream << " is empty";
    }
    else
    {
        stream << ":";
        for (; iter.checkRange(); iter.next())
            stream << " " << iter.getCur();
    }

    return stream;
}

#endif
