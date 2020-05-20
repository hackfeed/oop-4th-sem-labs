#ifndef _LISTNODE_HPP_
#define _LISTNODE_HPP_

#include "listnode.h"

template <typename T>
ListNode<T>::ListNode() : data(0), next(nullptr) {}

template <typename T>
ListNode<T>::ListNode(const T data) : data(data), next(nullptr) {}

template <typename T>
ListNode<T>::ListNode(const std::shared_ptr<ListNode<T>> node) : data(node->data)
{
    this->next = node;
}

template <typename T>
ListNode<T>::ListNode(const T data, const std::shared_ptr<ListNode<T>> nextNode) : data(data)
{
    this->next = nextNode;
}

template <typename T>
ListNode<T>::~ListNode()
{
    this->data = 0;
    this->next = nullptr;
}

template <typename T>
void ListNode<T>::setData(const T data)
{
    this->data = data;
}

template <typename T>
T ListNode<T>::getData() const
{
    return this->data;
}

template <typename T>
T &ListNode<T>::getPtrData()
{
    return this->data;
}

template <typename T>
void ListNode<T>::setNext(const std::shared_ptr<ListNode<T>> nextNode)
{
    this->next = nextNode;
}

template <typename T>
std::shared_ptr<ListNode<T>> ListNode<T>::getNext()
{
    return this->next;
}

template <typename T>
bool ListNode<T>::operator==(const ListNode &secondNode) const
{
    return (this->data == secondNode.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator!=(const ListNode &secondNode) const
{
    return (this->data != secondNode.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator>(const ListNode &secondNode) const
{
    return (this->data > secondNode.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator<(const ListNode &secondNode) const
{
    return (this->data < secondNode.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator>=(const ListNode &secondNode) const
{
    return (this->data >= secondNode.data) ? true : false;
}

template <typename T>
bool ListNode<T>::operator<=(const ListNode &secondNode) const
{
    return (this->data <= secondNode.data) ? true : false;
}

#endif
