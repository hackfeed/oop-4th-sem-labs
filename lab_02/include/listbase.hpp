#ifndef _LISTBASE_HPP_
#define _LISTBASE_HPP_

#include "listbase.h"

// cpp

ListBase::ListBase() : sizeList(0) {}

ListBase::~ListBase() = default;

size_t ListBase::size() const
{
    return sizeList;
}

#endif