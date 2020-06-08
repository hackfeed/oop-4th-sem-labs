#ifndef DRAWER_H
#define DRAWER_H

#include "ui_mainwindow.h"
#include "point.h"

class base_drawer
{
public:
    base_drawer() = default;
    virtual ~base_drawer() = default;
    virtual void draw_line(const point &point1, const point &point2) = 0;
    virtual void clear_scene() = 0;
};

class qt_drawer : public base_drawer
{
public:
    qt_drawer() : scene(nullptr){};
    qt_drawer(QGraphicsScene *_scene) : scene(_scene){};
    qt_drawer(const qt_drawer &_drawer);

    virtual void draw_line(const point &point1, const point &point2) override;
    virtual void clear_scene() override;

private:
    QGraphicsScene *scene;
};

#endif
