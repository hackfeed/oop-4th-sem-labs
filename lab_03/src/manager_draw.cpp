#include "manager_draw.hpp"

#include <ctime>

#include "exception_draw.hpp"
#include "transform_matrix.h"

void DrawManager::ProjectPoint(Point<double> &point)
{
    Point<double> cam_pos(camera_->getPosition());
    std::shared_ptr<matrix<double>> transform_matrix(std::make_shared<MoveMatrix>(-cam_pos.getX(), -cam_pos.getY(), 0));
    point.transform(transform_matrix);
    transform_matrix.reset(new RotateOxMatrix(-camera_->getXAngle()));
    point.transform(transform_matrix);
    transform_matrix.reset(new RotateOyMatrix(-camera_->getYAngle()));
    point.transform(transform_matrix);
    transform_matrix.reset(new RotateOzMatrix(-camera_->getZAngle()));
    point.transform(transform_matrix);

    double eps = 1e-10;
    double znam = point.getZ() + cam_pos.getZ();
    if (znam < eps && znam > -eps)
    {
        znam = eps;
    }
    double distCoef = cam_pos.getZ() / znam;
    point.setX(point.getX() * distCoef);
    point.setY(point.getY() * distCoef);
}

void DrawManager::SetDrawer(std::shared_ptr<BaseDrawer> drawer)
{
    drawer_ = drawer;
}

void DrawManager::SetCamera(std::shared_ptr<Camera> camera)
{
    camera_ = camera;
}

void DrawManager::Visit(Model &model)
{
    time_t t_time = time(NULL);
    if (!drawer_)
    {
        throw DrawerError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    if (!camera_)
    {
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }

    auto compound = model.getMesh();
    auto lines = compound->getLines();

    for (auto &line : lines)
    {
        ProjectPoint(line.get_first());
        ProjectPoint(line.get_second());
        drawer_->drawLine(line.get_first(), line.get_second());
    }
}

void DrawManager::Visit(Camera &camera) {}

void DrawManager::Visit(CompositeObject &composite) {}
