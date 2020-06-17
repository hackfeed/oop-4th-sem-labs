#pragma once

#include <QGraphicsScene>

#include "visitor.hpp"
#include "manager_base.hpp"
#include "matrix.hpp"
#include "base_drawer.hpp"
#include "scene.hpp"

class DrawManager : public BaseManager, public Visitor
{
public:
    void setDrawer(std::shared_ptr<BaseDrawer> drawer);
    void setCamera(std::shared_ptr<Camera> camera);
    void visit(Model &model);
    void visit(Camera &model);
    void visit(CompositeObject &model);

private:
    std::shared_ptr<BaseDrawer> drawer_;
    std::shared_ptr<Camera> camera_;
    void proectPoint(Point<double> &point);
};
