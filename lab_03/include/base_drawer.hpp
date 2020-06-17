#pragma once

#include "base_canvas.hpp"
#include "point.hpp"

class BaseDrawer
{
public:
    BaseDrawer() = default;
    virtual ~BaseDrawer() = default;

    virtual void drawLine(const Point<double> &, const Point<double> &) = 0;
    virtual void setCanvas(std::shared_ptr<BaseCanvas> canvas_) = 0;

    std::shared_ptr<BaseCanvas> canvas;
};
