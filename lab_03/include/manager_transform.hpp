#ifndef MANAGER_TRANSFORM_HPP
#define MANAGER_TRANSFORM_HPP

#include <cmath>
#include <memory>

#include "manager_base.hpp"
#include "transform_matrix.h"
#include "object_scene.hpp"
#include "scene.hpp"

class TransformManager : public BaseManager
{
public:
    void MoveObject(std::shared_ptr<SceneObject> obj, int dx, int dy, int dz);
    void ScaleObject(std::shared_ptr<SceneObject> obj, double x, double y, double z);
    void RotateX(std::shared_ptr<SceneObject> obj, double angle);
    void RotateY(std::shared_ptr<SceneObject> obj, double angle);
    void RotateZ(std::shared_ptr<SceneObject> obj, double angle);

private:
    double DegToRad(double angle);
};

#endif