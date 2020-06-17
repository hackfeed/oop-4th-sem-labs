#pragma once

#include <cmath>
#include <memory>

#include "manager_base.hpp"
#include "transform_matrix.h"
#include "object_scene.hpp"
#include "scene.hpp"

class TransformManager : public BaseManager
{
public:
    void moveObject(std::shared_ptr<SceneObject> obj, int dx, int dy, int dz);
    void scaleObject(std::shared_ptr<SceneObject> obj, double x, double y, double z);
    void rotateObjectOX(std::shared_ptr<SceneObject> obj, double angle);
    void rotateObjectOY(std::shared_ptr<SceneObject> obj, double angle);
    void rotateObjectOZ(std::shared_ptr<SceneObject> obj, double angle);

private:
    double degreesToRadians(double angle);
};
