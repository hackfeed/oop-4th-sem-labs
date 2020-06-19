#ifndef OBJECT_CAMERA_HPP
#define OBJECT_CAMERA_HPP

#include "matrix.hpp"
#include "visitor.hpp"
#include "object_invisible.hpp"
#include "point.hpp"

// Свести к базовомоу классу
class Camera : public InvisibleObject
{
public:
    Camera(std::string name);

    const Point<double> &GetPosition() const;
    void SetPosition(const Point<double> &position);

    double GetXAng() const;
    void SetXAng(double x_angle);

    double GetYAng() const;
    void SetYAng(double y_angle);

    double GetZAng() const;
    void SetZAng(double z_angle);

    void Transform(const std::shared_ptr<Matrix<double>> mtr);
    void Accept(std::shared_ptr<Visitor> visitor) override;

private:
    Point<double> position;
    double x_angle;
    double y_angle;
    double z_angle;
};

#endif