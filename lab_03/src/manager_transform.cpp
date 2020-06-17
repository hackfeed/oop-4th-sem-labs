#include "manager_transform.hpp"

#include "matrix.hpp"

void TransformManager::moveObject(std::shared_ptr<SceneObject> obj, int dx, int dy, int dz)
{
    std::shared_ptr<matrix<double>> transform_matrix(std::make_shared<MoveMatrix>(dx, dy, dz));
    obj->transform(transform_matrix);
}

void TransformManager::scaleObject(std::shared_ptr<SceneObject> obj, double kx, double ky, double kz)
{
    std::shared_ptr<matrix<double>> transform_matrix(std::make_shared<ScaleMatrix>(kx, ky, kz));
    obj->transform(transform_matrix);
}

void TransformManager::rotateObjectOX(std::shared_ptr<SceneObject> obj, double angle)
{
    angle = degreesToRadians(angle);
    std::shared_ptr<matrix<double>> transform_matrix(std::make_shared<RotateOxMatrix>(angle));
    obj->transform(transform_matrix);
}

void TransformManager::rotateObjectOY(std::shared_ptr<SceneObject> obj, double angle)
{
    angle = degreesToRadians(angle);
    std::shared_ptr<matrix<double>> transform_matrix(std::make_shared<RotateOyMatrix>(angle));
    obj->transform(transform_matrix);
}

void TransformManager::rotateObjectOZ(std::shared_ptr<SceneObject> obj, double angle)
{
    angle = degreesToRadians(angle);
    std::shared_ptr<matrix<double>> transform_matrix(std::make_shared<RotateOzMatrix>(angle));
    obj->transform(transform_matrix);
}

double TransformManager::degreesToRadians(double angle)
{
    return angle / 180. * 3.1415926535;
}
