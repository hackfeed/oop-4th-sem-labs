#ifndef _LISTBASE_H_
#define _LISTBASE_H_

#include <iostream>

// Сделать абстрактным

class ListBase
{
public:
    ListBase();
    virtual ~ListBase() = 0;

    size_t size() const;

protected:
    size_t sizeList;
};

#endif