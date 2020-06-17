#include "qt_drawer.hpp"

#include "qt_canvas.hpp"

void QtDrawer::drawLine(const Point<double> &p1, const Point<double> &p2)
{
    this->canvas->DrawLine(p1, p2);
}

void QtDrawer::setCanvas(std::shared_ptr<BaseCanvas> canvas_)
{
    this->canvas = canvas_;
}
