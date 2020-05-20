#ifndef _LISTBASE_HPP_
#define _LISTBASE_HPP_

#include "listbase.h"

ListBase::ListBase() : sizeList(0) {}

ListBase::~ListBase()
{
    this->sizeList = 0;
}

size_t ListBase::size() const
{
    return sizeList;
}

#endif