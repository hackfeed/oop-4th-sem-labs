#pragma once

#include <memory>

#include "qt_drawer.hpp"

class AbstractFactory
{
public:
    virtual std::shared_ptr<BaseDrawer> createGraphics() const = 0;
};
