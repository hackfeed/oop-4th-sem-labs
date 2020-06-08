#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include "drawer.h"

class abstract_factory
{
public:
    virtual std::unique_ptr<base_drawer> create_graphics() = 0;
};

class qt_factory : public abstract_factory
{
public:
    virtual std::unique_ptr<base_drawer> create_graphics() override
    {
        return std::unique_ptr<base_drawer>(new qt_drawer);
    }
};

#endif
