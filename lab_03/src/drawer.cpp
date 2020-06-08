#include "drawer.h"

qt_drawer::qt_drawer(const qt_drawer &_drawer)
{
    this->scene = _drawer.scene;
}

void qt_drawer::clear_scene()
{
    scene->clear();
}

void qt_drawer::draw_line(const point &point1, const point &point2)
{
    this->scene->addLine(point1.get_x(), point1.get_y(), point2.get_x(), point2.get_y());
}
