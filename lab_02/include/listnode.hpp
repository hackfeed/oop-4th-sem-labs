#ifndef _LISTNODE_HPP_
#define _LISTNODE_HPP_

#include "listnode.h"

template <typename typeData>
ListNode<typeData>::ListNode() : data(0), next(nullptr) {}

template <typename typeData>
ListNode<typeData>::ListNode(const typeData data) : data(data), next(nullptr) {}

template <typename typeData>
ListNode<typeData>::ListNode(const std::shared_ptr<ListNode<typeData>> node) : data(node->data)
{
    this->next = node;
}

template <typename typeData>
ListNode<typeData>::ListNode(const typeData data, const std::shared_ptr<ListNode<typeData>> nextNode) : data(data)
{
    this->next = nextNode;
}

template <typename typeData>
ListNode<typeData>::~ListNode()
{
    this->data = 0;
    this->next = nullptr;
}

template <typename typeData>
void ListNode<typeData>::setData(const typeData data)
{
    this->data = data;
}

template <typename typeData>
typeData ListNode<typeData>::getData() const
{
    return this->data;
}

template <typename typeData>
typeData &ListNode<typeData>::getPtrData()
{
    return this->data;
}

template <typename typeData>
void ListNode<typeData>::setNext(const std::shared_ptr<ListNode<typeData>> nextNode)
{
    this->next = nextNode;
}

template <typename typeData>
std::shared_ptr<ListNode<typeData>> ListNode<typeData>::getNext()
{
    return this->next;
}

template <typename typeData>
bool ListNode<typeData>::operator==(const ListNode &secondNode) const
{
    return (this->data == secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator!=(const ListNode &secondNode) const
{
    return (this->data != secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator>(const ListNode &secondNode) const
{
    return (this->data > secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator<(const ListNode &secondNode) const
{
    return (this->data < secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator>=(const ListNode &secondNode) const
{
    return (this->data >= secondNode.data) ? true : false;
}

template <typename typeData>
bool ListNode<typeData>::operator<=(const ListNode &secondNode) const
{
    return (this->data <= secondNode.data) ? true : false;
}

#endif
