#pragma once

#include <QGraphicsScene>
#include <memory>

#include "base_canvas.hpp"

class QtCanvas : public BaseCanvas
{
public:
    void DrawLine(const Point<double> &p1, const Point<double> &p2) override;
    explicit QtCanvas(std::shared_ptr<QGraphicsScene> canvas_);

private:
    std::shared_ptr<QGraphicsScene> graphics_scene_;
};
