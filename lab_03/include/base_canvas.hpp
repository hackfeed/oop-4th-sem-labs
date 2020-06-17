#pragma once

#include "point.hpp"

class BaseCanvas
{
public:
    virtual void addLine(const Point<double> &p1, const Point<double> &p2) = 0;
};
