#pragma once

#include <QGraphicsScene>
#include <memory>

#include "base_drawer.hpp"
#include "point.hpp"

class QtDrawer : public BaseDrawer
{
public:
    QtDrawer() = default;

    void drawLine(const Point<double> &p1, const Point<double> &p2) override;
    void setCanvas(std::shared_ptr<BaseCanvas> canvas_) override;
};
