#ifndef _LISTBASE_H_
#define _LISTBASE_H_

#include <iostream>

class ListBase
{
public:
    ListBase();
    virtual ~ListBase();

    size_t size() const;

protected:
    size_t sizeList;
};

#endif