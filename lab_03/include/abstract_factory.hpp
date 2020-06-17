#ifndef ABSTRACT_FACTORY_HPP
#define ABSTRACT_FACTORY_HPP

#include <memory>

#include "qt_drawer.hpp"

class AbstractFactory
{
public:
    virtual std::shared_ptr<BaseDrawer> CreateUi() const = 0;
};

#endif